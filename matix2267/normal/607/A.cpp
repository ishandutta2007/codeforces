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
	vector<pii> V(n);
	fru(i,n) scanf("%d%d",&V[i].x,&V[i].y);
	sort(ALL(V));
	vi ANS(n);
	fru(i,n) {
		int left = V[i].x - V[i].y;
		auto it = lower_bound(ALL(V), pii(left, -1));
		int pos = it - V.begin();
		pos--;
//		printf("pos %d\n",pos);
		if(pos >= 0) ANS[i] = ANS[pos]+1;
		else ANS[i]=1;
	}
	int ma = 0;
	fru(i,n) ma = max(ma, ANS[i]);
	printf("%d\n",n-ma);
}

int main() {
	int te = 1;
//	scanf("%d",&te);
	fru(ti,te) solve();
	return 0;
}