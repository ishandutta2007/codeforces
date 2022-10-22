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

int n,m,x,y;
void print(int x,int y) {
	int ed = y % m + 1;
	cout << x << ' ' << y << endl;
	for(int i = 1;i <= m;++i)
		if(i != y && i != ed) cout << x << ' ' << i << endl;
	cout << x << ' ' << ed << endl;
}
int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m >> x >> y;
	for(int i = x;i >= 1;--i)
		print(i,y),y = y % m + 1;
	for(int i = x+1;i <= n;++i)
		print(i,y),y = y % m + 1;
	return 0;
}