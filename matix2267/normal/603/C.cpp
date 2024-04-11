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

int get0(int a) {
	if(a<=2) return a;
	return a%2==0;
}

int get1(int a) {
	if(a<=3) return a%2;
	if(a==4) return 2;
	if(a%2==1) return 0;
	return 1+(get1(a/2)==1);
}

void solve() {
//	fru(i,21) printf("get0 %d -> %d\n",i,get0(i));
//	fru(i,21) printf("get1 %d -> %d\n",i,get1(i));
	int n,k;
	scanf("%d%d",&n,&k);
	k %= 2;
	int st = 0;
	fru(i,n) {
		int a;
		scanf("%d",&a);
		if(k==0) st ^= get0(a);
		if(k==1) st ^= get1(a);
	}
	if(st==0) puts("Nicky");
	if(st!=0) puts("Kevin");
}

int main() {
	int te = 1;
//	scanf("%d",&te);
	fru(ti,te) solve();
	return 0;
}