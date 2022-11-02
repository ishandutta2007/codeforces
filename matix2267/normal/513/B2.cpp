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
const int MAXN = 60;

bool take[MAXN];

void solve() {
	int n; ll m;
	cin >> n >> m;
	m--;
	fru(i,n) if(m & (1LL<<i)) take[n-i-2] = 1;
	fru(i,n) if(!take[i]) printf("%d ", i+1);
	fru(i,n) if(take[n-i-1]) printf("%d ", n-i);
}

int main() {
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int t=1;
//	scanf("%d",&t);
	fru(i,t) solve();
	return 0;
}