#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()

typedef long long ll;
typedef double D;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<char> vc;

const int inft = 1000000009;
const int MAXN = 1000006;

void solve() {
	int n,m;
	scanf("%d%d",&n,&m);
	vector<vc> S(n,vc(m));
	vector<vi> A(n,vi(m));
	fru(i,n) fru(j,m) scanf(" %c",&S[i][j]);
	fru(i,n) fru(j,m) scanf("%d",&A[i][j]);
	vi mi(n,inft);
	fru(i,n) fru(j,m) mi[i] = min(mi[i], A[i][j]);
	fru(i,n) fru(j,m) {
		bool ok = 1;
		fru(ii,n) if(i!=ii) if(S[ii][j] == S[i][j]) ok = 0;
		if(ok) mi[i] = 0;
	}
	vi B(1<<n);
	fru(mm,1<<n) fru(i,n) if(mm & (1<<i)) B[mm] += mi[i];
	map<int,int> be;
	fru(j,m) fru(h,26) {
		char c = 'a'+h;
		vi P;
		int mm = 0;
		fru(i,n) if(S[i][j] == c) { P.pb(A[i][j]); mm |= 1<<i; }
		if(mm == 0) continue;
		sort(ALL(P));
		P.pop_back();
		int sum = 0;
		tr(it,P) sum += *it;
		if(sum >= B[mm]) continue;
		if(be.find(mm) != be.end()) be[mm] = min(be[mm], sum);
		else be[mm] = sum;
	}
	tr(it,be) tr(it2,be) {
		if(it2 == it) break;
		int mm = it->x | it2->x;
		int sum = it->y + it2->y;
		if(sum >= B[mm]) continue;
		if(be.find(mm) != be.end()) be[mm] = min(be[mm], sum);
		else be[mm] = sum;
	}
	int ans = B[(1<<n)-1];
	tr(it,be) ans = min(ans, it->y + B[((1<<n)-1) ^ it->x]);
	printf("%d\n",ans);
}

int main() {
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int t=1;
//	scanf("%d",&t);
	fru(i,t) solve();
	return 0;
}