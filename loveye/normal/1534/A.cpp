#include<bits/stdc++.h>
using namespace std;

int read();
#define LL long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 150;
int t,n,m;
char s[N][N];
int main() {
	cin >> t;
	while(t--) {
		cin >> n >> m;
		fr(i,1,n) cin >> &s[i][1];
		int ok = 1,flag = -1;
		fr(i,1,n) {
			fr(j,1,m) if(s[i][j] != '.') {
				flag = (i + j & 1) ^ (s[i][j] != 'R'); break;
			}
			if(flag != -1) break;
		}
		if(flag == -1) flag = 0;
		fr(i,1,n) fr(j,1,m) if((i + j & 1) == flag) {
			if(s[i][j] == 'W') ok = 0;
			s[i][j] = 'R';
		} else {
			if(s[i][j] == 'R') ok = 0;
			s[i][j] = 'W';
		}
		if(!ok) puts("NO");
		else {
			cout << "YES" << endl;
			fr(i,1,n) printf("%s\n",&s[i][1]);
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