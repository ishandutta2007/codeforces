#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(auto it=(v).begin(); it!=(v).end(); ++it)
//#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
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
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<char> vc;

const int inft = 1000000009;
const int mod = 1000000007;
const int MAXN = 1000006;

const int dx[4] = {0,-1,0,1};
const int dy[4] = {1,0,-1,0};

int n,m;
vector<vc> S;

int bfs2(const char *cc) {
	vector<vector<vi> > D(3,vector<vi>(n,vi(m,inft)));
	fru(c,3) {
		queue<pii> Q;
		fru(i,n) fru(j,m) if(S[i][j]==cc[c]) { D[c][i][j]=0; Q.push(pii(i,j)); }
		while(!Q.empty()) {
			int x = Q.front().x, y = Q.front().y;
			Q.pop();
			int d = D[c][x][y];
			fru(h,4) {
				int nx = x+dx[h], ny = y+dy[h];
				if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
				if(D[c][nx][ny] < inft) continue;
				if(S[nx][ny]=='#') continue;
				D[c][nx][ny] = d+1;
				Q.push(pii(nx,ny));
			}
		}
	}
	int ret = inft;
	fru(i,n) fru(j,m) if(S[i][j]=='.') ret = min((ll)ret, 0LL+D[0][i][j]+D[1][i][j]+D[2][i][j]-2);
	return ret;
}

pii bfs(int from, int tox, int toy) {
	vector<vi> D(n,vi(m,inft));
	queue<pii> Q;
	fru(i,n) fru(j,m) if(S[i][j]==from) { D[i][j]=-1; Q.push(pii(i,j)); }
	while(!Q.empty()) {
		int x = Q.front().x, y = Q.front().y;
		Q.pop();
		int d = D[x][y];
		fru(h,4) {
			int nx = x+dx[h], ny = y+dy[h];
			if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
			if(D[nx][ny] < inft) continue;
			if(S[nx][ny]=='#') continue;
			D[nx][ny] = d+1;
			Q.push(pii(nx,ny));
		}
	}
	pii ret(inft,inft);
	fru(i,n) fru(j,m) if(S[i][j]==tox) ret.x = min(ret.x, D[i][j]);
	fru(i,n) fru(j,m) if(S[i][j]==toy) ret.y = min(ret.y, D[i][j]);
	return ret;
}

void solve() {
	scanf("%d%d",&n,&m);
	S.resize(n,vc(m+1));
	fru(i,n) scanf("%s",&S[i][0]);
	fru(i,n) S[i].pop_back();
	pii A[3];
	fru(i,3) A[i] = bfs('1'+i, '1'+(i+1)%3, '1'+(i+2)%3); 
	int best = bfs2("123");
	fru(i,3) best = min(best, A[i].x+A[i].y);
	if(best == inft) best = -1;
	printf("%d\n",best);
}

int main() {
	int te = 1;
//	scanf("%d",&te);
	fru(ti,te) solve();
	return 0;
}