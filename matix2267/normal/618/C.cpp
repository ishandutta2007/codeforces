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

ll vec(pii a, pii b) {
	return 1LL*a.x*b.y - 1LL*a.y*b.x;
}

ll vec(pii a, pii b, pii c) {
	return vec(pii(a.x-b.x,a.y-b.y), pii(a.x-c.x,a.y-c.y));
}

void solve() {
	int n;
	scanf("%d",&n);
	vector<pair<pii,int> > P(n);
	fru(i,n) {
		scanf("%d%d",&P[i].x.x,&P[i].x.y);
		P[i].y = i;
	}
	sort(ALL(P));
	printf("%d %d ",P[0].y+1,P[1].y+1);
	for(int j=2;j<n;j++) {
		if(vec(P[0].x, P[1].x, P[j].x)) {
			printf("%d\n",P[j].y+1);
			return;
		}
	}
}

int main() {
	int te = 1;
//	scanf("%d",&te);
	fru(ti,te) solve();
	return 0;
}