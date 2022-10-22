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
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll T;
ll n;
ll a[2005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, 1, 2*n) cin >> a[i];
		sort(a+1, a+2*n+1);
		
		rep(i, 1, 2*n-1){
			multiset<ll> S;
			rep(j, 1, 2*n-1){
				if(i == j) continue;
				S.insert(a[j]);
			}
			
			ll x = a[2*n]; bool flag = true; vector<P> ans;
			rep(j, 1, n-1){
				auto it = S.end(); it--;
				auto it2 = S.lower_bound(x - *it);
				if(it == it2 || it2 == S.end() || *it + *it2 != x){
					flag = false;
					break;
				}
				ans.push_back(P(*it, *it2));
				x = *it;
				S.erase(it), S.erase(it2);
			}
			if(flag){
				cout << "YES" << endl;
				cout << a[i]+a[2*n] << endl;
				cout << a[i] << " " << a[2*n] << endl;
				for(auto p : ans) cout << p.first << " " << p.second << endl;
				goto end;
			}
		}
		cout << "NO" << endl;
		end:;
	}
	
	return 0;
}