#include<bits/stdc++.h>
using namespace std;
const int MOD = 0;

const int S = 1 << 21;
char p0[S],*p1,*p2;
#ifndef ZXY
#define getchar() (p2 == p1 && (p2 = (p1 = p0) + fread(p0,1,S,stdin)) == p1 ? EOF : *p1++)
#endif
inline int read() {
	static int x,c;x = 0;
	do{c = getchar();}while(!isdigit(c));
	do{x = (x << 3) + (x << 1) + (c & 15);c = getchar();}while(isdigit(c));
	return x;
}

#define LL long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define ci const int &

int T,a,b,c,d,cnt;
int main() {
	ios::sync_with_stdio(0);
	cin >> T;
	while(T--) {
		cnt = 0;
		cin >> a >> b >> c >> d;
		if(a & 1) ++cnt;
		if(b & 1) ++cnt;
		if(c & 1) ++cnt;
		if(cnt == 0 || cnt == 3) puts("YES");
		else if(cnt == 1) puts(d & 1 ? "NO" : "YES");
		else if(a && b && c) puts(d & 1 ? "YES" : "NO");
		else puts("NO");
	}
	return 0;
}