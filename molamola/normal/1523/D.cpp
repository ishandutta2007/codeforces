#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
typedef tuple<int, int, int> t3;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int randInt(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

int n, m, p;
char In[200020][66];
int idx[66], A[200020];
int val[1<<15];

void solve() {
	scanf("%d%d%d", &n, &m, &p);
	rep(i, n) scanf("%s", In[i]);
	int ans[66] = {}, cans = 0;
	rep(tt, 50) {
		int x = randInt(0, n - 1);
		memset(idx, -1, sizeof idx);
		vector <int> w;
		rep(j, m) if(In[x][j] == '1') w.pb(j);
		int l = szz(w);
		rep(i, l) idx[w[i]] = i;
		memset(val, 0, sizeof val);
		rep(i, n) {
			A[i] = 0;
			rep(j, l) {
				if(In[i][w[j]] == '1') A[i] |= 1<<j;
			}
			val[A[i]] += 1;
		}
		rep(b, l) {
			rep(i, 1<<l) {
				if((i & 1<<b) == 0) {
					val[i] += val[i ^ 1<<b];
				}
			}
		}
		rep(i, 1<<l) {
			int ci = __builtin_popcount(i);
			if(val[i] >= (n + 1) / 2) {
				if(cans < ci) {
					cans = ci;
					memset(ans, 0, sizeof ans);
					for(int j=0;j<l;j++) if(1<<j & i) ans[w[j]] = 1;
				}
			}
		}
	}
	rep(i, m) printf("%d", ans[i]); puts("");
}

int main() {
	int T = 1; //scanf("%d", &T);
	rep(tt, T) {
		solve();
	}
	return 0;
}