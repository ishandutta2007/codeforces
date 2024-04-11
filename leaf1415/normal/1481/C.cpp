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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size()-1; (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll T;
ll n, m;
ll a[100005], b[100005], c[100005];
set<ll> S[100005];
map<ll, ll> mp;
vector<ll> ans;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n >> m;
		rep(i, 1, n) cin >> a[i];
		rep(i, 1, n) cin >> b[i];
		rep(i, 1, m) cin >> c[i];
		reverse(c+1, c+m+1);
		
		rep(i, 1, n) S[i].clear();
		mp.clear();
		rep(i, 1, n) mp[b[i]] = i;
		rep(i, 1, n) if(a[i] != b[i]) S[b[i]].insert(i);
		
		ans.clear();
		ll put = 0;
		rep(i, 1, m){
			if(S[c[i]].size()){
				ll p = *S[c[i]].begin();
				ans.push_back(p);
				S[c[i]].erase(S[c[i]].begin());
				put = p;
			}
			else{
				if(put) ans.push_back(put);
				else{
					if(mp.count(c[i]) == 0){
						cout << "NO" << endl;
						goto end;
					}
					ans.push_back(mp[c[i]]);
					put = mp[c[i]];
				}
			}
		}
		rep(i, 1, n){
			if(S[i].size()){
				cout << "NO" << endl;
				goto end;
			}
		}
		
		cout << "YES" << endl;
		reverse(all(ans));
		for(auto x : ans) cout << x << " "; cout << endl;
		end:;
	}
	
	return 0;
}