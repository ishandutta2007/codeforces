#include<cstdio>
#include<set>
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
int n,a[N];
set<int> s;
int main() {
	int t; cin>>t; while(t--) {
		cin>>n;
		int ok=1;
		fr(i,1,n) cin>>a[i];
		fr(i,2,n) if(a[i]!=a[i-1]) ok=0;
		if(ok) cout<<"YES"<<endl;
		else {
			fr(i,1,n) {
				if(a[i]==1) ok|=1;
				if(a[i]==0) ok|=2;
			}
			if(!(ok&1)) cout<<"YES"<<endl;
			else if(ok==3) cout<<"NO"<<endl;
			else {
				s.clear();
				fr(i,1,n) s.insert(a[i]);
				ok=1;
				fr(i,1,n) if(a[i]>=2&&s.count(a[i]-1))
					ok=0;
				cout<<(ok?"Yes":"NO")<<endl;
			}
		}
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