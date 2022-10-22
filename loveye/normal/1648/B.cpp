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

const int N=1e6+5;
int n,c,a[N<<1],s[N<<1];
int main() {
	ios::sync_with_stdio(0);
	int t; cin>>t;
	while(t--) {
		cin>>n>>c;
		fr(i,1,c*2) s[i]=0;
		fr(i,1,n) cin>>a[i],s[a[i]]=1;
		fr(i,1,c*2) s[i]+=s[i-1];
		int ok=1;
		fr(i,1,c) if(s[i]==s[i-1]) {
			fr(j,1,c/i) if(s[j]-s[j-1]&&s[(i+1)*j-1]-s[i*j-1]) {
				ok=0; break;
			}
			if(!ok) break;
		}
		cout<<(ok?"Yes":"No")<<endl;
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