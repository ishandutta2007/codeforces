#include<bits/stdc++.h>
using namespace std;

const int S = 1 << 21;
char p0[S],*p1,*p2;
#define getchar() (p2 == p1 && (p2 = (p1 = p0) + fread(p0,1,S,stdin)) == p1 ? EOF : *p1++)
inline int read() {
	static int x,c,f;x = 0;f = 1;
	do c = getchar(),c == '-' && (f = -1);while(!isdigit(c));
	do x = x * 10 + (c & 15),c = getchar();while(isdigit(c));
	return x * f;
}

#define LL long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define I inline void
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)
#define y1 y111

const int N = 2e5 + 5,M = 610;
int n,m,a[N],b[N],bl[N],bls;
struct Point {
	int x,y;
} p[N];
vector<int> bf[M];
struct BIT {
	int c[N];
	I add(int x,int v) {
		for(;x <= n;x += x & -x) c[x] += v;
	}
	inline int ask(int x) {
		int res = 0;
		for(;x;x -= x & -x) res += c[x];
		return res;
	}
} T[M];
I add(int x,int y,int v) {
	for(;x <= bl[n];x += x & -x) T[x].add(y,v);
}
inline int ask(int x,int y) {
	int res = 0;
	for(;x;x -= x & -x) res += T[x].ask(y);
	return res;
}
I init() {
	fr(i,1,n) bf[bl[p[i].x]].push_back(i);
	fr(i,1,n) add(bl[p[i].x],p[i].y,1);
}
I change(int idx,int nv) {
	add(bl[p[idx].x],p[idx].y,-1);
	p[idx].y = nv;
	add(bl[p[idx].x],p[idx].y,1);
}
inline int query(int x,int y) {
	int id = bl[x],res = 0;
	fo(i,0,bf[id].size())
		if(p[bf[id][i]].x <= x && p[bf[id][i]].y <= y)
			++res;
	if(id) res += ask(id-1,y);
	return res;
}
inline double calc_bls(int n) {
	double res = sqrt(n);
	while(fabs(res - (log2(n/res)*log2(n))) > 5)//Newton Methods
		res = res - (res - (log2(n/res)*log2(n))) / (1 + log2(n) / (res*log(2)));
	return res;
}
int main() {
#ifdef ZXY
	filein("E"); fileout("E");
#endif
	n = read(),m = read();
	bls = max(n/600.,calc_bls(n));
	fr(i,1,n) bl[i] = (i-1) / bls + 1;
	fr(i,1,n) p[a[i] = read()].x = i;
	fr(i,1,n) p[b[i] = read()].y = i;
	init();
	while(m--) {
		static int op,x1,y1,x2,y2;
		op = read(),x1 = read(),x2 = read();
		if(op == 1) {
			y1 = read(),y2 = read();
			printf("%d\n",query(x2,y2)-query(x1-1,y2)-query(x2,y1-1)+query(x1-1,y1-1));
		}
		else {
			swap(b[x1],b[x2]);
			change(b[x1],x1); change(b[x2],x2);
		}
	}
	return 0;
}