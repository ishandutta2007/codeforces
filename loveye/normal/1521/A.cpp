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
#define int long long 
int n,A,B;
signed main() {
	int t;cin >> t;
	while(t--) {
		cin >> A >> B;
		if(B == 1) cout << "NO" << endl;
		else {
			cout << "YES" <<endl;
			if(B == 2) cout << A << ' ' << A * 3 << ' ' << A * 4 << endl;
			else cout << A << ' ' << A * (B-1) << ' ' << A * B << endl;
		}
	}
	return 0;
}