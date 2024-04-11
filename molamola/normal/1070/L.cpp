#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define repp(i,n) for(int i=1;i<=n;i++)

int N, M;
bitset <2020> mat[2020];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &N, &M);
		vector <pii> E;
		int deg[2020] = {};
		for(int i=1;i<=M;i++) {
			int x, y; scanf("%d%d", &x, &y);
			deg[x]++; deg[y]++;
			E.pb(pii(x, y));
		}
		int ok = 1;
		for(int i=1;i<=N;i++) if(deg[i] & 1) ok = 0;
		if(ok) {
			puts("1");
			for(int i=1;i<=N;i++) printf("1 ");
			puts(""); 
		}
		else {
			for(int i=1;i<=N;i++) mat[i].reset();
			for(int i=1;i<=N;i++) if(deg[i] & 1) mat[i][i] = 1;
			for(pii e : E) {
				int x = e.Fi, y = e.Se;
				mat[x][y] = !mat[x][y];
				mat[y][x] = !mat[y][x];
			}
			int V[2020] = {};
			for(int i=1;i<=N;i++) V[i] = (deg[i] & 1);
			int now = 1;
			int base[2020];
			for(int i=1;i<=N;i++) {
				int f = -1;
				for(int j=now;j<=N;j++) if(mat[j][i]) {
					f = j; break;
				}
				if(f == -1) continue;
				swap(mat[f], mat[now]);
				swap(V[f], V[now]);
				for(int j=now+1;j<=N;j++) {
					if(mat[j][i]) {
						mat[j] ^= mat[now];
						V[j] ^= V[now];
					}
				}
				base[now] = i;
				++now;
			}
			--now;
			int res[2020] = {};
			for(int i=now;i;i--) {
				int p = base[i];
				res[p] = V[i];
				if(res[p]) {
					for(int j=1;j<i;j++) if(mat[j][p]) V[j] ^= 1;
				}
			}

			puts("2");
			for(int i=1;i<=N;i++) printf("%d ", res[i] + 1); puts("");
		}
	}
}