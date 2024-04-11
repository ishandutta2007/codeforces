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

char S[MAXN];

void solve() {
	int n;
	scanf("%d%s",&n,S);
	int prev = S[0], aa = 0, sc = 1;
	fru(i,n) if(i) {
		if(S[i]==prev) aa++;
		else sc++;
		prev = S[i];
	}
	sc += min(2,aa);
	printf("%d\n",sc);
}

int main() {
	int te = 1;
//	scanf("%d",&te);
	fru(ti,te) solve();
	return 0;
}