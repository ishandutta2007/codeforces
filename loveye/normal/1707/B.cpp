#include<cstdio>
#include<map>
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
#define fi first
#define se second

const int N=1e5+5,M=5e5+5;
int n,a[N];
map<int,int> cnt,nxt;
int main() {
	int t; cin>>t;
	while(t--) {
		cin>>n;
		cnt.clear();
		fr(i,1,n) cin>>a[i],++cnt[a[i]];
		fo(kas,1,n) {
			int lst=-1;
			for(auto p:cnt) {
				if(p.se>1) nxt[0]+=p.se-1;
				if(~lst) ++nxt[p.fi-lst];
				lst=p.fi;
			}
			swap(cnt,nxt);
			nxt.clear();
		}
		cout<<(cnt.begin())->fi<<endl;
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