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

const int N=1e6+5;
int n;
ll a[N],s[N];
ll getsum(int l,int r) {return s[r]-s[l-1];}
int stk[N],top;
int chk(int a,int b,int c,int d) {
	return getsum(a,b)*(d-c+1)>=getsum(c,d)*(b-a+1);
}
int main() {
	n=read();
	fr(i,1,n) a[i]=read(),s[i]=s[i-1]+a[i];
	fr(i,1,n) {
		int l=i;
		while(top&&chk(stk[top],l-1,l,i)) l=stk[top--];
		stk[++top]=l;
	}
	stk[++top]=n+1;
	fr(i,1,top-1) {
		double x=1.*getsum(stk[i],stk[i+1]-1)/(stk[i+1]-stk[i]);
		fr(j,stk[i],stk[i+1]-1) printf("%.12lf\n",x);
	}
	puts("");
	return 0;
}

const int S = 1 << 21;
char p0[S],*p1,*p2;
inline int read() {
	static int x,c,f;x = 0;f = 1;
	do c = getchar(),c == '-' && (f = -1);while(!isdigit(c));
	do x = x * 10 + (c & 15),c = getchar();while(isdigit(c));
	return x * f;
}