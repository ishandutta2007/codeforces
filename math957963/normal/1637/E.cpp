#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 1010
#define MOD 998244353
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
struct Setup_io {
	Setup_io() {
		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		cout << fixed << setprecision(15);
	}
} setup_io;



int main() {
	int t, n, m, k;
	int a[N];
	vector<ll>b[N];
	set<pll>st;
	map<int, int>mp2;
	map<long long, int>mp;
	map<long long, int>::iterator itr;
	int p, q, szp, szq;
	ll x, y, ans;
	rep(i, N) {
		a[i] = 0;
		b[i].clear();
	}
	cin >> t;
	rep(tt, t) {
		ans = 0;
		st.clear();
		mp.clear();
		mp2.clear();
		cin >> n >> m;
		rep(i, n) {
			cin >> x;
			mp[x] = mp[x] + 1;
		}
		itr = mp.begin();
		k = 1;
		while (itr != mp.end()) {
			if (mp2[(*itr).second] == 0) {
				mp2[(*itr).second] = k;
				a[k] = (*itr).second;
				b[k].pb((*itr).first);
				k++;
			}
			else {
				b[mp2[(*itr).second]].pb((*itr).first);
			}
			itr++;
		}
		rep2(i, 1, k - 1) {
			sort(b[i].begin(), b[i].end(), greater<ll>());
		}
		rep(i, m) {
			cin >> x >> y;
			st.insert({ x,y });
			st.insert({ y,x });
		}


		rep2(j, 1, k - 1) {
			rep2(i, 1, j) {
				p = i;
				q = j;
				szp = b[i].size();
				szq = b[j].size();
				if (szp > szq) {
					swap(p, q);
					swap(szp, szq);
				}
				rep(ii, szp) {
					rep(jj, szq) {
						if (b[p][ii] != b[q][jj]) {
							if (st.count({ b[p][ii],b[q][jj] }) == 0) {
								x = a[p] + a[q];
								y = b[p][ii] + b[q][jj];
								ans = max(ans, (x*y));
								break;
							}
						}
					}
				}
			}
		}
		cout << ans << endl;

		rep(i, k) {
			a[i] = 0;
			b[i].clear();
		}
	}
	return 0;
}