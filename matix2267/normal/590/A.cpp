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
	vi V(n);
	fru(i,n) scanf("%d",&V[i]);
	V.pb(-1);
	int best = 0, last = -1, cur = 0;
	fru(i,n+1) {
		if(V[i] == 1-last) {
			cur++;
			best = max(best,cur);
		} else if(cur != 0) {
			i--;
			if(cur % 2 == 0) {
				fru(j,cur+1) V[i-j] = V[i];
			} else {
				fru(j,cur/2+1) V[i-j] = V[i];
				fru(j,cur/2+1) V[i-cur/2-1-j] = V[i-cur];
			}
			i++;
			cur = 0;
		}
		last = V[i];
	}
	printf("%d\n",best/2);
	V.pop_back();
	for(int u : V) printf("%d ",u);
	puts("");
}

int main() {
	int te = 1;
//	scanf("%d",&te);
	fru(ti,te) solve();
	return 0;
}