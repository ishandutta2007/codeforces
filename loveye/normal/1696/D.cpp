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

const int N=2.5e5+5;
int n;
int a[N],st1[19][N],st2[19][N];
int getmin(int l,int r) {
	int k=__lg(r-l+1);
	return a[st1[k][l]]<a[st1[k][r-(1<<k)+1]]?st1[k][l]:st1[k][r-(1<<k)+1];
}
int getmax(int l,int r) {
	int k=__lg(r-l+1);
	return a[st2[k][l]]>a[st2[k][r-(1<<k)+1]]?st2[k][l]:st2[k][r-(1<<k)+1];
}
int main() {
	int t;cin>>t;
	while(t--) {
		cin>>n;
		fr(i,1,n) cin>>a[i],st1[0][i]=st2[0][i]=i;
		fr(k,1,18) fr(i,1,n-(1<<k)+1) {
			if(a[st1[k-1][i]]<a[st1[k-1][i+(1<<k-1)]])
				st1[k][i]=st1[k-1][i];
			else st1[k][i]=st1[k-1][i+(1<<k-1)];
			if(a[st2[k-1][i]]>a[st2[k-1][i+(1<<k-1)]])
				st2[k][i]=st2[k-1][i];
			else st2[k][i]=st2[k-1][i+(1<<k-1)];
		}
		int p=getmax(1,n),u,f,ans=0;
		for(f=1,u=p;u^1;) {
			++ans;
			if(f) u=getmin(1,u);
			else u=getmax(1,u);
			f^=1;
		}
		for(f=1,u=p;u^n;) {
			++ans;
			if(f) u=getmin(u,n);
			else u=getmax(u,n);
			f^=1;
		}
		cout<<ans<<endl;
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