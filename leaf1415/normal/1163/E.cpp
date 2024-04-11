#include <iostream>
#include <set>
#include <vector>

using namespace std;

int n;
int s[200005], a[200005];
set<int> S;
vector<int> vec[30], B;

int getketa(int x)
{
	int ret = 0;
	for(;x;x/=2) ret++;
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) vec[getketa(a[i])].push_back(a[i]);
	
	int ans = 0;
	S.insert(0);
	for(int i = 1; i < 30; i++){
		for(int j = 0; j < vec[i].size(); j++){
			int x = vec[i][j];
			if(S.count(x)) continue;
			B.push_back(x);
			
			vector<int> tmp;
			for(auto it = S.begin(); it != S.end(); it++) tmp.push_back(*it ^ x);
			for(int k = 0; k < tmp.size(); k++) S.insert(tmp[k]);
		}
		if(i == B.size()) ans = i;
	}
	
	S.clear(), B.clear();
	S.insert(0);
	for(int i = 1; i <= ans; i++){
		for(int j = 0; j < vec[i].size(); j++){
			int x = vec[i][j];
			if(S.count(x)) continue;
			B.push_back(x);
			
			vector<int> tmp;
			for(auto it = S.begin(); it != S.end(); it++) tmp.push_back(*it ^ x);
			for(int k = 0; k < tmp.size(); k++) S.insert(tmp[k]);
		}
	}
	
	cout << ans << endl;
	for(int i = 0; i < (1<<ans); i++){
		int x = i ^ (i>>1);
		int y = 0;
		for(int j = 0; j < B.size(); j++){
			if(x & (1<<j)) y ^= B[j];
		}
		cout << y << " ";
	}
	cout << endl;
	
	return 0;
}