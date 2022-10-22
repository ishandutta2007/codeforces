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

const int N=2e5+5;
int n,a[N],b[N];
void chk() {
	int p=-1;
	fr(i,1,n) if(b[i]==1) p=i;
	if(~p) {
		fr(i,p+1,n) if(b[i]!=b[i-1]+1) return;
		int len=n-p+1;
		fr(i,1,p-1) if(b[i]&&b[i]-len<=i) return;
		cout<<n-len<<endl; exit(0);
	}
}
int main() {
	cin>>n;
	int ans=0;
	fr(i,1,n) cin>>a[i];
	fr(i,1,n) {
		cin>>b[i];
		if(b[i]) ans=max(ans,i-b[i]+1);
	}
	chk();
	cout<<ans+n<<endl;
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