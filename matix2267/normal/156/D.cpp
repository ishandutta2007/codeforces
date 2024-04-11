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

int tf[MAXN], M[MAXN];

int find(int x) {
    if(tf[x]==x) return x;
    return tf[x] = find(tf[x]);
}

void Union(int a,int b) {
    tf[find(a)] = find(b);
}

void solve() {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    fru(i,n) tf[i] = i;
    fru(_,m) {
        int a,b;
        scanf("%d%d",&a,&b);
        Union(a-1, b-1);
    }
    fru(i,n) M[find(i)] += 1;
    vi V;
    fru(i,n) if(M[i]) V.pb(M[i]);
    int s = V.size();
    // n^(s-2) * prod(V)
    ll ans = 1%k;
    if(s!=1) {
        fru(i,s-2) ans = ans*n%k;
        fru(i,s) ans = ans*V[i]%k;
    }
    printf("%d\n", (int)ans);
}

int main() {
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int t=1;
//	scanf("%d",&t);
	fru(i,t) solve();
	return 0;
}