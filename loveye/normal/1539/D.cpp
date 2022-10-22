#include<bits/stdc++.h>
using namespace std;

int read();
#define LL long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define ci const int &
#define cl const LL &
#define I inline void
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 1e5 + 5;
int n;
struct Node {
	LL a,b;
} p[N];
bool cmp(const Node &a,const Node &b) {
	return a.b < b.b;
}
int main() {
	scanf("%d",&n);
	fr(i,1,n) scanf("%lld%lld",&p[i].a,&p[i].b);
	sort(p+1,p+n+1,cmp);
	LL ans = 0,alr = 0;
	for(int l = 1,r = n;l <= r;) {
		if(p[l].b <= alr) {
			ans += p[l].a;
			alr += p[l].a;
			++l;
		} else {
			LL cnt = min(p[r].a,p[l].b - alr);
			p[r].a -= cnt;
			ans += cnt * 2;
			alr += cnt;
			if(p[r].a == 0) --r;
		}
	}
	printf("%lld\n",ans);
	return 0;
}