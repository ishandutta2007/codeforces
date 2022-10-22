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
int ans;
int chk(int i) {return i>=1&&i<=n-2&&s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c';}
int main() {
	cin>>n>>q>>s+1;
	fr(i,1,n-2) ans+=chk(i);
	while(q--) {
		static int i;
		static char c;
		cin>>i>>c;
		ans-=chk(i-2)+chk(i-1)+chk(i);
		s[i]=c;
		ans+=chk(i-2)+chk(i-1)+chk(i);
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