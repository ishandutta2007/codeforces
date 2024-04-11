#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
//#define tr(it,v) for(auto it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()

#if 1
	#define DEB printf
#else
	#define DEB(...)
#endif

typedef long long ll;
typedef long long LL;
typedef double D;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef vector<int> vi;

const int inft = 1000000009;
const int mod = 1000000007;
const int MAXN = 1003;

char M[MAXN][MAXN];
int dist[MAXN][MAXN][2];
int n;

inline void trymove(queue<ppi> &Q, int u, int v, int mv, int d) {
	if(u==v && u!=n-1 && d!=0 && d%2==0) return;
	if(dist[u][v][mv] != inft) return;
	dist[u][v][mv] = d;
	Q.push(ppi(pii(u,v),mv));
}

void solve() {
	int m;
	scanf("%d%d",&n,&m);
	fru(i,m) {
		int a,b;
		scanf("%d%d",&a,&b);
		a--; b--;
		M[a][b]=M[b][a]=1;
	}
	fru(i,n) M[i][i] = 2;
	fru(i,n) fru(j,n) dist[i][j][0] = dist[i][j][1] = inft;
	queue<ppi> Q;
	trymove(Q,0,0,0,0);
	while(!Q.empty()) {
		pii cur = Q.front().x;
		int mv = Q.front().y;
		Q.pop();
		int d = dist[cur.x][cur.y][mv];
		if(mv==0) {
			if(cur.x==n-1) trymove(Q, cur.x, cur.y, mv^1, d+1);
			else fru(j,n) if(M[cur.x][j]==1) trymove(Q, j, cur.y, mv^1, d+1);
		} else {
			if(cur.y==n-1) trymove(Q, cur.x, cur.y, mv^1, d+1);
			else fru(j,n) if(M[cur.y][j]==0) trymove(Q, cur.x, j, mv^1, d+1);
		}
	}
	if(0) fru(i,n) fru(j,n) printf("dist[%d][%d] = %d %d\n",i,j,dist[i][j][0],dist[i][j][1]);
	int d = dist[n-1][n-1][0];
	if(d == inft) d = -2;
	printf("%d\n", d/2);
}

int main() {
	int te = 1;
//	scanf("%d",&te);
	fru(ti,te) solve();
	return 0;
}