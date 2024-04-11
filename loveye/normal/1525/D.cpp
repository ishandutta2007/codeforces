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

#define int long long
const int N = 5050,INF = 0x3f3f3f3f;
int n,a[N],cnt;
LL ans;
priority_queue<int,vector<int>,greater<int> > q1,q0;
queue<int> qu;
signed main() {
	cin >> n;
	fr(i,1,n) cin >> a[i];
	fr(i,1,n) {
		if(a[i]) {
			if(q0.size()) {
				int res = i + q0.top();
				ans += res,q0.pop(),q1.push(-i-res);
			} else {
				qu.push(i);
			}
		} else {
			if(qu.size()) {
				ans += i - qu.front();
				qu.pop();
			} else if(q1.size() && q1.top() + i < 0) {
				int res = q1.top() + i;
				ans += q1.top() + i;
				q1.pop();
				q0.push(-res-i);
			} else {
				q0.push(-i);
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}