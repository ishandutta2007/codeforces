#include <iostream>
#include <string>
#include <vector>
#include <utility>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint n, m;
llint a[1005], d[1005];
vector<P> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	llint t, l, r;
	for(int i = 0; i < m; i++){
		cin >> t >> l >> r;
		r--;
		if(t == 1) for(int i = l; i <= r; i++) a[i] = 1;
		else vec.push_back(make_pair(l, r));
	}
	for(int i = 0; i < vec.size(); i++){
		llint l = vec[i].first, r = vec[i].second;
		bool flag = false;
		for(int j = l; j <= r; j++){
			if(a[j] == 0){
				flag = true;
				d[j] = 1;
				break;
			}
		}
		if(!flag){
			cout << "NO" << endl;
			return 0;
		}
	}
	
	cout << "YES" << endl;
	llint sum = 0;
	cout << 100000 << " ";
	for(int i = 2; i <= n; i++){
		sum += d[i-1];
		cout << 100000 - sum << " ";
	}
	cout << endl;
	
	return 0;
}