#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=(1<<21)+5;
int t,n,h,g,a[N];
vector<int> ans;
int tryf(int u,int dep) {
	int lc=u<<1,rc=u<<1|1;
	if(a[lc]==0&&a[rc]==0) return dep>g;
	if(a[lc]>a[rc]) return tryf(lc,dep+1);
	return tryf(rc,dep+1);
}
void f(int u) {
	int lc=u<<1,rc=u<<1|1;
	if(a[lc]==0&&a[rc]==0) a[u]=0;
	else if(a[lc]>a[rc]) a[u]=a[lc],f(lc);
	else a[u]=a[rc],f(rc);
}
void solve(int u,int dep) {
	while(tryf(u,dep)) f(u),ans.push_back(u);
	if(dep<g) solve(u<<1,dep+1),solve(u<<1|1,dep+1);
}
int main() {
	t=read();
	while(t--) {
		h=read(),g=read();
		fo(i,1,1<<h) a[i]=read();
		fo(i,1<<h,1<<h+1) a[i]=0;
		ans.clear();
		solve(1,1);
		ll sum=0;
		fo(i,1,1<<g) sum+=a[i];
		printf("%lld\n",sum);
		for(auto x:ans) printf("%d ",x);
		puts("");
	}
	return 0;
}

const int S = 1 << 21;
char p0[S],*p1,*p2;
inline int read() {
	static int x,c,f;x = 0;f = 1;
	do c = getchar(),c == '-' && (f = -1);while(!isdigit(c));
	do x = x * 10 + (c & 15),c = getchar();while(isdigit(c));
	return x * f;
}