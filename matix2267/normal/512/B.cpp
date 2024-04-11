#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()

typedef long long ll;
typedef double D;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int inft = 1000000009;
const int MAXN = 1000006;

map<int,int> M;

void mm(int x, int y) {
	int old = M[x];
	if(old==0) M[x] = y;
	else M[x] = min(old, y);
}

void solve() {
	int n;
	scanf("%d",&n);
	vi V(n), C(n);
	fru(i,n) scanf("%d",&V[i]);
	fru(i,n) scanf("%d",&C[i]);
	fru(i,n) mm(V[i], C[i]);
	for(typeof(M.rbegin()) it = M.rbegin(); it != M.rend(); ++it) {
		fru(i,n) {
			int u = __gcd(V[i], it->x);
			if(u == it->x) continue;
			mm(u, C[i] + it->y);
		}
	}
	int a = M[1];
	if(a==0) a=-1;
	printf("%d\n", a);
}

int main() {
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int t=1;
//	scanf("%d",&t);
	fru(i,t) solve();
	return 0;
}