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
int x2,n;
vector<int> fac[N];
int main() {
	n=int(1e6);
	fr(i,1,n) for(int j=i;j<=n;j+=i) fac[j].push_back(i);
	cin>>x2;
	vector<int> tmp;
	for(auto p:fac[x2]) if(fac[p].size()==2) {
		fr(x1,x2-p+1,x2) if(fac[x1].size()!=2)
			tmp.push_back(x1);
	}
	sort(tmp.begin(),tmp.end());
	tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
	int x0=x2;
	for(auto x1:tmp) for(auto p:fac[x1]) if(fac[p].size()==2)
		x0=min(x0,x1-p+1);
	cout<<x0<<endl;
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