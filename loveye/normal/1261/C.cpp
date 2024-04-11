#include<cstdio>
#include<queue>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)
typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair

const int N = 1e6 + 5;
string s[N];
vector<int> d[N],d2[N];
int n,m;
const int gox[] = {-1,-1,-1,0,0,1,1,1},goy[] = {-1,0,1,-1,1,-1,0,1};
void bfs() {
	queue<pii> q;
	fr(i,1,n) fr(j,1,m) if(s[i][j] == '.')
		q.push(mp(i,j)),d[i][j] = 0;
	while(!q.empty()) {
		pii u = q.front(); q.pop();
		fo(i,0,8) {
			int tx = u.fi + gox[i];
			int ty = u.se + goy[i];
			if(tx >= 1 && tx <= n && ty >= 1 && ty <= m && d[tx][ty] == -1) {
				d[tx][ty] = d[u.fi][u.se] + 1;
				q.push(mp(tx,ty));
			}
		}
	}
}
void add(int x1,int y1,int x2,int y2) {
	++d2[x1][y1];
	if(y2 < m) --d2[x1][y2+1];
	if(x2 < n) --d2[x2+1][y1];
	if(x2 < n && y2 < m)
		++d2[x2+1][y2+1];
}
int chk(int x) {
	fr(i,1,n) fr(j,1,m) d2[i][j] = 0;
	fr(i,1,n) fr(j,1,m) if(d[i][j] > x)
		add(max(1,i-x),max(1,j-x),min(n,i+x),min(m,j+x));
	fr(i,1,n) fr(j,1,m) d2[i][j] += d2[i-1][j] + d2[i][j-1] - d2[i-1][j-1];
	fr(i,1,n) fr(j,1,m) if((s[i][j] == 'X') ^ (d2[i][j] > 0))
		return 0;
	return 1;
}
int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m; n += 2; m += 2;
	s[1].assign(m+1,'.');
	fr(i,2,n-1) {
		cin >> s[i];
		s[i] = ".." + s[i] + ".";
	}
	s[n].assign(m+1,'.');

	fr(i,0,n) d[i].assign(m+1,-1),d2[i].resize(m+1);
	bfs();
	int l = 0,r = min(n,m)-1 >> 1;
	while(l < r) {
		int mid = l + r + 1 >> 1;
		if(chk(mid)) l = mid;
		else r = mid-1;
	}
	cout << l << '\n';
	fr(i,2,n-1) {
		fr(j,2,m-1) if(d[i][j] > l) cout << 'X';
		else cout << '.';
		cout << '\n';
	}
	return 0;
}

const int S = 1 << 21;
char p0[S],*p1,*p2;
#define getchar() (p2 == p1 && (p2 = (p1 = p0) + fread(p0,1,S,stdin)) == p1 ? EOF : *p1++)
inline int read() {
	static int x,c,f;x = 0;f = 1;
	do c = getchar(),c == '-' && (f = -1);while(!isdigit(c));
	do x = x * 10 + (c & 15),c = getchar();while(isdigit(c));
	return x * f;
}