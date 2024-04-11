#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(auto it=(v).begin(); it!=(v).end(); ++it)
//#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()

#if 1
	#define DEB printf
#else
	#define DEB(...)
#endif

typedef long long ll;
typedef long long LL;
typedef double D;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int inft = 1000000009;
const int mod = 1000000007;
const int MAXN = 1000006;

int lis(vi V) {
	vi W;
	for(int v : V) {
		auto it = upper_bound(ALL(W), v);
		if(it == W.end()) {
			W.push_back(v);
		} else {
			*it = v;
		}
	}
	return W.size();
}

void solve() {
	int n,T;
	scanf("%d%d",&n,&T);
	vi V(n);
	fru(i,n) scanf("%d",&V[i]);
	int MAX = min(310, T);
	vi W(MAX*n);
	fru(i,MAX*n) W[i] = V[i%n];
	T -= MAX;
	ll ans = lis(W);
	vi C(310);
	fru(i,n) C[V[i]]++;
	sort(ALL(C));
	ans += 1LL*T*C.back();
	printf("%lld\n",ans);
}

int main() {
	int te = 1;
//	scanf("%d",&te);
	fru(ti,te) solve();
	return 0;
}