#include<cstdio>
#include<numeric>
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
int n,m;
char s[N],t[N];
int ss[N],st[N],ls[N],lt[N];
int main() {
	cin>>s+1>>t+1;
	n=strlen(s+1);
	m=strlen(t+1);
	fr(i,1,n) {
		ss[i]=ss[i-1]+(s[i]!='A');
		if(s[i]=='A') ls[i]=ls[i-1]+1;
		else ls[i]=0;
	}
	fr(i,1,m) {
		st[i]=st[i-1]+(t[i]!='A');
		if(t[i]=='A') lt[i]=lt[i-1]+1;
		else lt[i]=0;
	}
	int q; cin>>q;
	while(q--) {
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		int A=ls[b],B=lt[d];
		A=min(b-a+1,A);
		B=min(d-c+1,B);
		int dt=(st[d]-st[c-1])-(ss[b]-ss[a-1]);
		if(ss[b]-ss[a-1]) {
			putchar((A>=B&&(dt||(A-B)%3==0)&&dt>=0&&(~dt&1))|'0');
		} else if(dt) {
			putchar((A>B&&dt>=0&&(~dt&1))|'0');
		} else putchar((b-a>=d-c&&(d-c-b+a)%3==0)|'0');
		//puts("");
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