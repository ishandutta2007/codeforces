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

const int N = 105;
int n,m,k,T;
char s[N][N],ans[N][N],col[256];
int main() {
	ios::sync_with_stdio(0);
	cin >> T;
	fr(i,1,26) col[i] = 'A'+i-1;
	fr(i,1,26) col[i+26] = 'a'+i-1;
	fr(i,1,10) col[i+52] = '0'+i-1;
	while(T--) {
		cin >> n >> m >> k;
		int cnt = 0;
		fr(i,1,n) {
			cin >> &s[i][1];
			fr(j,1,m) if(s[i][j] == 'R') ++cnt;
		}
		int goal = cnt / k + 1,res = cnt % k,x = 1,y = 1;
		fr(id,1,k) {
			if(id == res+1) --goal;
			int tmp = 0;
			while(1) {
				if(s[x][y] == 'R') ++tmp;
				ans[x][y] = col[id];
				if(x & 1) {
					if(++y > m) ++x,y = m;
				} else {
					if(--y < 1) ++x,y = 1;
				}
				if(tmp == goal) break;
			}
		}
		while(x <= n) {
			ans[x][y] = col[k];
			if(x & 1) {
				if(++y > m) ++x,y = m;
			} else {
				if(--y < 1) ++x,y = 1;
			}
		}
		fr(i,1,n) {
			ans[i][m+1] = '\0';
			cout << &ans[i][1] << endl;
		}
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