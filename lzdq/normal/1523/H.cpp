#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("inline","unroll-loops","no-stack-protector")
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<ctime>
using namespace std;
typedef long long ll;
const int MAXN=20005;
template <int T>
struct fast_io {
	char p[T], q[T], *p1, *p2, *q1, *q2;
	fast_io() {
		p1 = p2 = p;
		q1 = q, q2 = q + T;
	}
	inline char gc() {
		return p1 == p2 && (p2 = (p1 = p) + fread(p, 1, T, stdin)), p1 == p2 ? EOF : *p1++;
	}
	inline void pc(char c) {
		if (q1 == q2) q2 = (q1 = q) + fwrite(q, 1, T, stdout);
		*q1++ = c;
	}
	~fast_io() {
		fwrite(q, 1, q1 - q, stdout);
	}
};
fast_io<1<<20> io;

template <typename T = int>
T getint() {
	T res = 0;
	char ch;
	do ch = io.gc(); while (ch < 48 || ch > 57);
	do res = res * 10 + (ch & 15), ch = io.gc(); while (ch >= 48 && ch <= 57);
	return res;
}

template <typename T>
void _put(T x) {
	if (x >= 10) _put(x / 10);
	io.pc(48 ^ (x % 10));
}

template <typename T>
void Put(T x, char ch = ' ') {
	_put(x);
	io.pc(ch);
}
int n,q,a[MAXN];
int f[15][MAXN][31];
int lg[MAXN];
long clk;
struct Rus{
	static const int blks=16,MAXM=MAXN/blks+2;
	int m,a[MAXN];
	int mx[blks][MAXM],pre[MAXN],suf[MAXN],st[MAXN],stk[blks+2];
	void Init(int X,int Y){
		//clk-=clock();
		for(int i=1; i<=n; i++)
			a[i]=f[X][i][Y];
		m=(n+blks-1)/blks;
		for(int i=1,l=1,s=0; i<=n; i++){
			pre[i]=a[i];
			if(i%blks!=1) pre[i]=max(pre[i],pre[i-1]);
			while(*stk&&a[stk[*stk]]<=a[i]) s^=1<<stk[(*stk)--]-l;
			s^=1<<(stk[++*stk]=i)-l;
			st[i]=s;
			if(i%blks==0||i==n) mx[0][(i+blks-1)/blks]=a[stk[1]],*stk=s=0,l=i+1;
		}
		suf[n]=a[n];
		for(int i=n-1; i; i--){
			suf[i]=a[i];
			if(i%blks) suf[i]=max(suf[i],suf[i+1]);
		}
		for(int i=1; i<=lg[m]; i++)
			for(int j=1; j+(1<<i)-1<=m; j++)
				mx[i][j]=max(mx[i-1][j],mx[i-1][j+(1<<i-1)]);
		//clk+=clock();
		return ;
	}
	inline int Query(int l,int r){
		//int x=(l+blks-1)/blks,y=(r+blks-1)/blks;
		int x=(l+blks-1)>>4,y=(r+blks-1)>>4;
		if(x==y) return a[l+__builtin_ctz(st[r]>>l-((x-1)<<4|1))];
		int res=max(suf[l],pre[r]);
		x++,y--,l=lg[y-x+1];
		if(~l) res=max(res,max(mx[l][x],mx[l][y-(1<<l)+1]));
		return res;
	}
}ff[15][31];
int qr[MAXN][3],g[MAXN][31],h[MAXN][31],ans[MAXN];
int main(){
	//freopen("in","r",stdin);
	//scanf("%d%d",&n,&q);
	n=getint();
	q=getint();
	lg[0]=-1;
	for(int i=1; i<=n; i++){
		a[i]=getint();
		lg[i]=lg[i>>1]+1;
		for(int k=0; k<=30; k++)
			f[0][i][k]=min(i+a[i]+k,n);
	}
	for(int j=0; j<=lg[n]; j++)
		for(int k=0; k<=30; k++){
			ff[j][k].Init(j,k);
			if(j<lg[n]){
				for(int i=1; i<=n; i++)
					for(int k2=0; k+k2<=30&&f[j+1][i][k+k2]<n; k2++)
						f[j+1][i][k+k2]=max(f[j+1][i][k+k2],ff[j][k].Query(i,f[j][i][k2]));
			}
		}
	/*
	bool fk=1;
	for(int i=1; i<sizeof(fuck)/4; i++)
		if(a[i]!=fuck[i]) fk=0;
	if(fk){
		//printf("%.2f\n",(double)(clk)/CLOCKS_PER_SEC);
		printf("%.2f\n",(double)(clock())/CLOCKS_PER_SEC);
		return 0;
	}

	while(q--){
		int l=getint(),r=getint(),k=getint(),res=0;
		if(l<r){
			for(int i=0; i<=k; i++)
				g[i]=l;
			for(int j=lg[r-l+1]; ~j; j--){
				memset(h,0,sizeof(h));
				bool ok=1;
				for(int k1=0; k1<=k&&ok; k1++)
					for(int k2=0; k1+k2<=k; k2++)
						if((h[k1+k2]=max(h[k1+k2],ff[j][k1].Query(l,g[k2])))>=r){
							ok=0;
							break;
						}
				if(ok){
					res|=1<<j;
					swap(g,h);
				}
			}
			res++;
		}
		Put(res,'\n');
	}
	*/
	for(int i=1; i<=q; i++){
		int l=getint(),r=getint(),k=getint();
		qr[i][0]=l;
		qr[i][1]=r;
		qr[i][2]=k;
		for(int j=0; j<=k; j++)
			g[i][j]=l;
	}
	for(int j=lg[n]; ~j; j--){
		memset(h,0,sizeof(h));
		for(int k1=0; k1<=30; k1++)
			for(int i=1; i<=q; i++){
				int l=qr[i][0],k=qr[i][2];
				for(int k2=0; k1+k2<=k; k2++)
					h[i][k1+k2]=max(h[i][k1+k2],ff[j][k1].Query(l,g[i][k2]));
			}
		for(int i=1; i<=q; i++){
			int r=qr[i][1],k=qr[i][2];
			if(h[i][k]<r){
				ans[i]|=1<<j;
				memcpy(g[i],h[i],sizeof(int)*(k+1));
			}
		}
	}
	for(int i=1; i<=q; i++){
		int l=qr[i][0],r=qr[i][1],res=0;
		if(l<r) res=ans[i]+1;
		Put(res,'\n');
	}
	return 0;
}