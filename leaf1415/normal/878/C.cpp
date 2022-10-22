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
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n, k;
ll a[50005][15];
ll m[50005][15], M[50005][15];
set<P> S;

ll check(ll id, ll a[])
{
	bool win = true, lose = true;
	rep(i, 1, k){
		if(M[id][i] > a[i]) win = false;
		if(m[id][i] < a[i]) lose = false;
	}
	if(win) return 1;
	if(lose) return -1;
	return 0;
}

ll getl(ll a[])
{
	ll ub = n+5, lb = -5, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		auto p = S.lower_bound(P(mid, -inf));
		//cout << "! " << p->first << " " << check(p->first, a) << endl;
		if(p == S.end() || check(p->first, a) <= 0) ub = mid;
		else lb = mid;
	}
	auto it = S.lower_bound(P(ub, -inf));
	if(it == S.end()) return inf;
	return it->first;
}

ll getr(ll a[])
{
	ll ub = n+5, lb = -5, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		auto p = S.lower_bound(P(mid, -inf));
		if(p != S.end() && check(p->first, a) >= 0) lb = mid;
		else ub = mid;
	}
	if(lb < -2) return -inf;
	auto it = S.lower_bound(P(lb, -inf));
	return it->first;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	rep(i, 1, n) rep(j, 1, k) cin >> a[i][j];

	rep(i, 1, k){
		vector<ll> comp;
		rep(j, 1, n) comp.push_back(a[j][i]);
		sort(all(comp));
		comp.erase(unique(all(comp)), comp.end());
		rep(j, 1, n) a[j][i] = lower_bound(all(comp), a[j][i]) - comp.begin();
	}

	ll id = a[1][1];
	S.insert(P(id, 1));
	rep(i, 1, k) M[id][i] = m[id][i] = a[1][i];
	cout << 1 << endl;

	rep(i, 2, n){

		//for(auto p : S) cout << "(" << p.first << ", " << p.second << ") ";
		//cout << endl;

		ll l = getl(a[i]), r = getr(a[i]);
		//cout << l << " " << r << endl;
		if(l > S.rbegin()->first || r < S.begin()->first){
			ll id = a[i][1];
			S.insert(P(id, 1));
			rep(j, 1, k) M[id][j] = m[id][j] = a[i][j];
			cout << S.rbegin()->second << endl;
			continue;
		}

		ll sum = 1, mn[15], mx[15];
		rep(j, 1, k) mn[j] = a[i][j], mx[j] = a[i][j];
		auto it = S.lower_bound(P(l, -inf));
		for(; it != S.end() && it->first <= r; ){
			sum += it->second;
			rep(j, 1, k){
				chmin(mn[j], m[it->first][j]);
				chmax(mx[j], M[it->first][j]);
			}
			auto tmp = it;
			it++;
			S.erase(tmp);
		}

		ll id = mx[1];
		S.insert(P(id, sum));
		rep(j, 1, k) m[id][j] = mn[j], M[id][j] = mx[j];

		cout << S.rbegin()->second << endl;
	}

	//for(auto p : S) cout << "(" << p.first << ", " << p.second << ") ";
	//cout << endl;

	return 0;
}