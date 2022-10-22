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
typedef pair<llint, P> T;

ll n, Q;
ll a[100005];
set<ll> S[100005];
P p[100005];
vector<P> pvec[1005];
vector<ll> svec[1005];
const ll B = 305;

void change(ll cur, ll pre)
{
	ll b = cur / B; P np = P(pre, cur-pre);
	ll pos = lower_bound(all(pvec[b]), p[cur]) - pvec[b].begin();
	pvec[b][pos] = np;
	
	sort(all(pvec[b]));
	svec[b].clear(); ll sum = 0;
	for(auto x : pvec[b]) sum += x.second, svec[b].push_back(sum);
	
	p[cur] = np;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> Q;
	rep(i, 1, n) cin >> a[i];
	
	rep(i, 1, n) S[i].insert(0);
	rep(i, 1, n) S[a[i]].insert(i);
	
	rep(i, 1, n){
		ll pre = -1, cur;
		for(auto x : S[i]){
			cur = x;
			if(pre != -1){
				p[cur] = P(pre, cur - pre);
				pvec[cur/B].push_back(P(pre, cur - pre));
			}
			pre = cur;
		}
	}
	rep(i, 0, n/B){
		sort(all(pvec[i]));
		ll sum = 0;
		for(auto x : pvec[i]) sum += x.second, svec[i].push_back(sum);
	}
	
	ll t, d, x, l, r;
	rep(i, 1, Q){
		cin >> t;
		if(t == 1){
			cin >> d >> x;
			if(a[d] == x) continue;
			ll y = a[d]; a[d] = x;
			
			S[y].erase(d); 
			auto it = S[y].lower_bound(d);
			if(it != S[y].end()){
				ll f = *it;
				it--; change(f, *it);
			}
			
			it = S[x].lower_bound(d);
			if(it != S[x].end()) change(*it, d);
			it--; change(d, *it);
			
			S[x].insert(d);
		}
		if(t == 2){
			cin >> l >> r;
			ll L = (l+B-1)/B*B, R = r/B*B, ans = 0;
			if(L > R){
				rep(j, l, r) if(p[j].first >= l) ans += p[j].second;
			}
			else{
				rep(j, l, L-1) if(p[j].first >= l) ans += p[j].second;
				rep(j, R, r) if(p[j].first >= l) ans += p[j].second;
				rep(j, L/B, R/B-1){
					ll pos = lower_bound(all(pvec[j]), P(l, -inf)) - pvec[j].begin();
					if(pos >= pvec[j].size()) continue;
					ans += svec[j].back();
					if(pos > 0) ans -= svec[j][pos-1];
				}
			}
			cout << ans << "\n";
		}
	}
	flush(cout);
	
	return 0;
}