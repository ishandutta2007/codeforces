#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;

llint T;
llint n, k;
vector<llint> vec[1005];
bool used[1005];

llint check(llint x)
{
	cout << "? " << x;
	for(int i = 1; i <= x; i++) cout << " " << i;
	cout << endl;
	
	llint ret;
	cin >> ret;
	if(ret == -1) exit(-1);
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> k;
		
		for(int i = 1; i <= k; i++) vec[i].clear();
		
		llint c, x;
		for(int i = 1; i <= k; i++){
			cin >> c;
			for(int j = 0; j < c; j++){
				cin >> x;
				vec[i].push_back(x);
			}
		}
		
		cout << "? " << n;
		for(int i = 1; i <= n; i++) cout << " " << i;
		cout << endl;
		
		llint mx;
		cin >> mx;
		if(mx == -1) exit(-1);
		
		
		llint ub = n, lb = 0, mid;
		while(ub-lb>1){
			mid = (ub+lb)/2;
			if(check(mid) >= mx) ub = mid;
			else lb = mid;
		}
		
		llint gid = 0;
		for(int i = 1; i <= k; i++){
			for(int j = 0; j < vec[i].size(); j++){
				if(vec[i][j] == ub){
					gid = i;
					goto end;
				}
			}
		}
		end:;
		
		for(int i = 1; i <= n; i++) used[i] = false;
		for(int i = 0; i < vec[gid].size(); i++) used[vec[gid][i]] = true;
		
		cout << "? " << (n-(llint)vec[gid].size());
		for(int i = 1; i <= n; i++){
			if(!used[i]) cout << " " << i;
		}
		cout << endl;
		
		llint res;
		cin >> res;
		if(res == -1) exit(-1);
		
		
		cout << "!";
		for(int i = 1; i <= k; i++){
			if(i == gid) cout << " " << res;
			else cout << " " << mx;
		}
		cout << endl;
		
		string s;
		cin >> s;
		if(s == "Incorrect") return 0;
	}
	return 0;
}