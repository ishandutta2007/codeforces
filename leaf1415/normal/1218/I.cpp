#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint n;
llint a[2005][2005], b[2005][2005];
llint c[2005];
llint p;
vector<P> ans;

bool check()
{
	ans.clear();
	
	for(int j = 1; j <= n; j++){
		if(a[p][j] != b[p][j]){
			ans.push_back(make_pair(2, j));
			for(int i = 1; i <= n; i++) a[i][j] ^= c[i];
		}
	}
	for(int i = 1; i <= n; i++){
		if(i == p) continue;
		bool same = true;
		for(int j = 1; j <= n; j++){
			if(a[i][j] != b[i][j]){
				same = false;
				break;
			}
		}
		if(!same){
			ans.push_back(make_pair(1, i));
			bool inv = true;
			for(int j = 1; j <= n; j++){
				if((a[i][j]^c[j]) != b[i][j]){
					inv = false;
					break;
				}
			}
			if(!inv) return false;
		}
	}
	return true;
}

void clear(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			a[i][j] = 0;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	char x;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> x;
			a[i][j] = x-'0';
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> x;
			b[i][j] = x-'0';
			b[i][j] ^= a[i][j];
		}
	}
	for(int i = 1; i <= n; i++){
		cin >> x;
		c[i] = x-'0';
	}
	clear();
	
	p = -1;
	for(int i = 1; i <= n; i++){
		if(c[i]){
			p = i;
			break;
		}
	}
	if(p == -1){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(b[i][j]){
					cout << -1 << endl;
					return 0;
				}
			}
		}
		cout << 0 << endl;
		return 0;
	}
	
	if(!check()){
		clear();
		for(int i = 1; i <= n; i++) a[p][i] = c[i];
		if(!check()){
			cout << -1 << endl;
			return 0;
		}
		ans.push_back(make_pair(1, p));
	}
	
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++){
		if(ans[i].first == 1) cout << "row ";
		else cout << "col ";
		cout << ans[i].second-1 << "\n";
	}
	flush(cout);
	
	return 0;
}