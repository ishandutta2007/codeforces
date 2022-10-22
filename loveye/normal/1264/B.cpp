#include<cstdio>
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

const int N = 1e5 + 5;
int out[N],top;
int c[4],a[4],b[4];
int G[4][4];
void Euler(int u) {
	fo(i,0,4) if(G[u][i]) {
		--G[u][i];
		Euler(i);
	}
	out[++top] = u;
}
int vis[4];
void dfs(int u) {
	vis[u] = 1;
	fo(v,0,4) if(G[u][v] && !vis[v]) dfs(v);
}
int main() {
	fo(i,0,4) cin >> c[i];
	fo(s,0,4) fo(t,0,4) {
		b[0] = c[0] - (s == 0);
		a[0] = c[0] - (t == 0);
		fr(i,1,2) {
			b[i] = c[i] - (s == i) - a[i-1];
			a[i] = c[i] - (t == i) - b[i-1];
		}
		if(0 == c[3] - (s == 3) - a[2] && 0 == c[3] - (t == 3) - b[2]) {
			int ok = 1;
			fo(i,0,3) if(a[i] < 0 || b[i] < 0) {
				ok = 0; break;
			}
			fo(i,0,3) {
				G[i][i+1] = a[i];
				G[i+1][i] = b[i];
			}
			fo(i,0,4) vis[i] = 0;
			dfs(s);
			fo(i,0,4) if(c[i] && !vis[i]) {
				ok = 0; break;
			}
			if(!ok) continue;
			cout << "YES" << endl;
			Euler(s);
			while(top) cout << out[top--] << ' ';
			return 0;
		}
	}
	cout << "NO" << endl;
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