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
int n;
char a[N],b[N];
int ca[2],cb[2];
int main() {
	int t; cin>>t;
	while(t--) {
		cin>>n;
		cin>>a+1>>b+1;
		ca[0]=ca[1]=cb[0]=cb[1]=0;
		fr(i,1,n) ++ca[a[i]-'0'];
		fr(i,1,n) ++cb[b[i]-'0'];
		int ans=2e9;
		if(ca[0]==cb[0]&&ca[1]==cb[1]) {
			int res=0;
			fr(i,1,n) if(a[i]!=b[i]) ++res;
			ans=min(ans,res);
		}
		if(cb[0]==ca[1]-1&&cb[1]==ca[0]+1) {
			int res=0;
			fr(i,1,n) if(a[i]==b[i]) ++res;
			if(ca[0]!=n) ans=min(ans,res-1+1);
		}
		cout<<(ans<1e9?ans:-1)<<endl;
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