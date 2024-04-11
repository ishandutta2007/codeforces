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

const int inft = 1000000009;
const int MAXN = 1000006;

void solve() {
	int a,b,c,d,e,f;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	printf("%d\n",a*b+a*c+b*c + d*e+d*f+e*f);
}

int main() {
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int t=1;
//	scanf("%d",&t);
	fru(i,t) solve();
	return 0;
}