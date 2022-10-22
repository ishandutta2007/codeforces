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

const int N=1e5+5;
int n,a[N];
int pre[N],suf[N];
int chkmax(int &a,int b) {if(a<b) return a=b,1; return 0;}
int main() {
	cin>>n;
	pre[0]=suf[n+1]=(1<<30)-1;
	fr(i,1,n) {
		cin>>a[i];
		pre[i]=pre[i-1]&~a[i];
	}
	rf(i,n,1) suf[i]=suf[i+1]&~a[i];
	int ans=-1,id=-1;
	fr(i,1,n) if(chkmax(ans,a[i]&pre[i-1]&suf[i+1])) id=i;
	printf("%d ",a[id]);
	fr(i,1,n) if(i!=id) printf("%d ",a[i]);
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