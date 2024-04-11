#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 300005, LG = 20;
int q, a[MX], c[MX], p[MX][LG], par[MX], sig[MX];

int parent (int a) {
	return par[a] == a ? a : par[a] = parent(par[a]);
}

void join (int a, int b) {
	par[parent(a)] = parent(b);
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	iota(par, par + MX, 0);
	iota(sig, sig + MX, 0);
	
	scanf("%d %d %d", &q, &a[0], &c[0]);
	
	for (int n = 1; n <= q; n++) {
		int op;
		scanf("%d", &op);
		
		if (op == 1) {
			scanf("%d %d %d", &p[n][0], &a[n], &c[n]);
			for (int j = 1; j < LG; j++)
				p[n][j] = p[p[n][j - 1]][j - 1];
		} else {
			int v, w, in = 0;
			ll ra = 0, rb = 0;
			
			scanf("%d %d", &v, &w);
			
			while (w) {
				int u = v;
				for (int j = LG - 1; j >= 0; j--)
					if (sig[parent(p[u][j])] >= in)
						u = p[u][j];
				
				if (sig[parent(u)] < in)
					break;
				in = u;
				
				int d = min(a[u], w);
				
				a[u] -= d;
				w -= d;
				
				ra += d;
				rb += 1ll * d * c[u];
				
				if (!a[u]) {
					if (a[p[u][0]])
						sig[parent(u)] = p[u][0];
					else if (u)
						join(u, p[u][0]);
					else
						sig[parent(u)] = -1;
				}
			}
			
			printf("%I64d %I64d\n", ra, rb);
			fflush(stdout);
		}
	}
	
	return 0;
}