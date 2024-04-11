#include<cstdio>
#include<cassert>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=1e5+5;
int n,q;
char s[N];
struct Matrix {
	int a[3][3];
	Matrix() {memset(a,0x3f,sizeof a);}
} ma,mb,mc,seg[N<<2];
Matrix operator * (const Matrix &a,const Matrix &b) {
	Matrix c;
	fo(i,0,3) fo(j,0,3) fo(k,0,3)
		c.a[i][k]=min(c.a[i][k],a.a[i][j]+b.a[j][k]);
	return c;
}
#define lc (k<<1)
#define rc (lc|1)
#define left lc,l,mid
#define right rc,mid+1,r
void change(int k,int l,int r,int p,char c) {
	if(l==r) return seg[k]=c=='a'?ma:(c=='b'?mb:mc),void();
	int mid=l+r>>1;
	if(p<=mid) change(left,p,c);
	else change(right,p,c);
	seg[k]=seg[lc]*seg[rc];
}
void build(int k,int l,int r) {
	if(l==r) return seg[k]=s[l]=='a'?ma:(s[l]=='b'?mb:mc),void();
	int mid=l+r>>1;
	build(left),build(right);
	seg[k]=seg[lc]*seg[rc];
}
int main() {
	cin>>n>>q>>s+1;
	ma.a[0][0]=1; ma.a[0][1]=ma.a[1][1]=0; ma.a[2][2]=0;
	mb.a[0][0]=0; mb.a[1][1]=1; mb.a[1][2]=mb.a[2][2]=0;
	mc.a[0][0]=0; mc.a[1][1]=0; mc.a[2][2]=1;
	build(1,1,n);
	while(q--) {
		static int p; static char c;
		cin>>p>>c;
		change(1,1,n,p,c);
		cout<<min(seg[1].a[0][0],min(seg[1].a[0][1],seg[1].a[0][2]))<<endl;
	}
	return 0;
}

const int S=1<<21;
char p0[S],*p1,*p2;
#define getchar() (p2==p1&&(p2=(p1=p0)+fread(p0,1,S,stdin))==p1?EOF:*p1++)
inline int read() {
	static int x,c,f;x=0;f=1;
	do c=getchar(),c=='-'&&(f=-1); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}