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

const int N=2e5+5;
int n;
string s;
int main() {
	int t;
	cin>>t;
	while(t--) {
		cin>>s;
		int res=0;
		int ok=1;
		fo(i,0,s.size()) if(s[i]=='A') ++res;
		else {
			--res;
			if(res<0) ok=0;
		}
		if(s.back()=='A') ok=0;
		cout<<(ok?"YES":"NO")<<endl;
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