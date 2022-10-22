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
LL a[N];
int main() {
	int t; cin >> t;
	while(t--) {
		cin >> a[1] >> a[2] >> a[3];
		sort(a+1,a+4);
		cout << max(1ll,a[3]-a[2]-a[1]+1) << endl;
	}
	return 0;
}