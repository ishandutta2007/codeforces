#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()
#define iter(i,j) fru(i,n) for(int j=i; j<n; j++)

typedef long long ll;
typedef double D;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int inft = 1000000009;
const int MAXN = 32;
const int LMN = 5;

int n, cnt, P[MAXN];
D G[MAXN*MAXN][MAXN*MAXN]; // liczba przejsc pary a,b -> c,d
D W[MAXN*MAXN][MAXN*MAXN];
D TMP[MAXN*MAXN][MAXN*MAXN];

template <typename T> void matpow(T c, T a, T b) {
	fru(i,cnt) fru(j,cnt) c[i][j] = 0;
	fru(i,cnt) fru(k,cnt) fru(j,cnt) c[i][j] += a[i][k] * b[k][j];
}

template <typename T> void matcpy(T a, T b) {
	fru(i,cnt) fru(j,cnt) a[i][j] = b[i][j];
}

int I[MAXN][MAXN];

void solve() {
	int k;
	scanf("%d%d",&n,&k);
	cnt = 0; iter(i,j) I[i][j] = cnt++;
	int nnp = n*(n+1)/2, nnm = n*(n-1)/2;
	fru(i,n) scanf("%d",&P[i]);
	fru(i,n) P[i]--;
	fru(i,n) fru(j,n) if(i<=j) iter(a,b) {
		int xa = (a>=i && a<=j) ? i+j-a : a;
		int xb = (b>=i && b<=j) ? i+j-b : b;
		if(xa < xb) G[I[a][b]][I[xa][xb]]++;
		if(xa > xb) G[I[a][b]][I[xb][xa]]--;
	}
	fru(i,cnt) fru(j,cnt) G[i][j] /= nnp;
	fru(i,cnt) W[i][i] = 1;
	while(k) {
		if(k%2) {
			matpow(TMP, W, G);
			matcpy(W, TMP);
		}
		matpow(TMP, G, G);
		matcpy(G, TMP);
		k/=2;
	}
	D ans = 0;
	iter(a,b) fru(i,cnt) {
		ans += W[I[a][b]][i] * ((P[a]<P[b]) ? -1 : 1);
	}
	printf("%.15lf\n", (nnm+ans)/2);
}

int main() {
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int t=1;
//	scanf("%d",&t);
	fru(i,t) solve();
	return 0;
}