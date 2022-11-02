#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
//#define tr(it,v) for(auto it=(v).begin(); it!=(v).end(); ++it)
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
	int n,m;
	scanf("%d%d",&n,&m);
	if(m==1) {
		puts("1.0000000000");
		return;
	}
	vector<D> U; U.pb(m-1);
	int myscore = 0;
	fru(i,n) {
		int a;
		scanf("%d",&a);
		myscore += a;
#if 0
		vector<D> W((i+1)*m+1);
		fru(j,(i+1)*m+1) {
			if(j) W[j] = W[j-1];
			if(j && j-1<=i*m) W[j] += U[j-1]/(m-1);
			if(j>=a && j-a<=i*m) W[j] -= U[j-a]/(m-1);
			if(j>=a+1 && j-a-1<=i*m) W[j] += U[j-a-1]/(m-1);
			if(j>=m+1 && j-m-1<=i*m) W[j] -= U[j-m-1]/(m-1);
		}
#endif
		vector<D> V((i+1)*m+1);
		fru(j,V.size()) {
			if(j) V[j] = V[j-1];
			if(j && j-1<U.size()) V[j] += U[j-1];
			if(j>=a && j-a<U.size()) V[j] -= U[j-a];
			if(j>=a+1 && j-a-1<U.size()) V[j] += U[j-a-1];
			if(j>=m+1 && j-m-1<U.size()) V[j] -= U[j-m-1];
		}
		fru(j,V.size()) V[j] /= (m-1);
#if 0
		printf("V: "); fru(j,(i+1)*m+1) printf("%.7lf ",V[j]); puts("");
		printf("W: "); fru(j,(i+1)*m+1) printf("%.7lf ",W[j]); puts("");
#endif
#if 0
		fru(j,(i+1)*m+1) assert(fabs(V[j]-W[j]) < 0.000001);
#endif
		swap(U,V);
	}
	U.resize(myscore);
	D ans = 1;
	fru(i,U.size()) ans += U[i];
	printf("%.10lf\n",ans);
}

int main() {
	int te = 1;
//	scanf("%d",&te);
	fru(ti,te) solve();
	return 0;
}