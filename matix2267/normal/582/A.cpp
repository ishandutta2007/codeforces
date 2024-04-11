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

void solve() {
	int n;
	scanf("%d",&n);
	vi V(n*n);
	fru(i,n*n) scanf("%d",&V[i]);
	sort(ALL(V));
	vi ans;
	priority_queue<int> Q;
	while(V.size()) {
		if(Q.size() && V.back() == Q.top()) {
			Q.pop();
			V.pop_back();
			continue;
		}
		for(int a : ans) {
			Q.push(__gcd(a,V.back()));
			Q.push(__gcd(a,V.back()));
		}
		ans.pb(V.back());
		V.pop_back();
	}
	for(int a : ans) printf("%d ",a);
	puts("");
}

int main() {
	int te = 1;
//	scanf("%d",&te);
	fru(ti,te) solve();
	return 0;
}