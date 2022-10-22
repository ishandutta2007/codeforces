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

const int N=5e4+5;
int n,m,a[N],k,b[N];
struct Node {ll v,c;};
Node s1[N],s2[N];
int t1,t2;
int main() {
	int t;cin>>t;
	while(t--) {
		cin>>n>>m;
		fr(i,1,n) cin>>a[i];
		cin>>k;
		fr(i,1,k) cin>>b[i];
		t1=t2=0;
		fr(i,1,n) if(a[i]) {
			ll z=1;
			while(a[i]%m==0) z*=m,a[i]/=m;
			if(!t1||s1[t1].v!=a[i]) s1[++t1]=Node{a[i],z};
			else s1[t1].c+=z;
		}
		fr(i,1,k) if(b[i]) {
			ll z=1;
			while(b[i]%m==0) z*=m,b[i]/=m;
			if(!t2||s2[t2].v!=b[i]) s2[++t2]=Node{b[i],z};
			else s2[t2].c+=z;
		}
		int ok=t1==t2;
		if(ok) fr(i,1,t1) if(s1[i].v!=s2[i].v||s1[i].c!=s2[i].c) {
			ok=0; break;
		}
		if(ok) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
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