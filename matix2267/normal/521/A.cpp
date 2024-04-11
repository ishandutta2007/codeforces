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
const int MOD = 1000000007;

int qpow(int a, int b) {
    int w = 1;
    while(b) {
        if(b%2) w = 1LL*w*a % MOD;
        a = 1LL*a*a % MOD;
        b/=2;
    }
    return w;
}

const char C[5] = "ACGT";
int N[4];

void solve() {
    int n; string S;
    cin >> n >> S;
    assert(n == S.size());
    fru(i,n) fru(c,4) N[c] += S[i]==C[c];
    int best = -1; vi bestat;
    fru(i,4) {
        if(N[i]>best) {
            best = N[i];
            bestat.clear();
        }
        if(N[i]==best) bestat.pb(i);
    }
    cout << qpow(bestat.size(), n) << endl;
}

int main() {
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int t=1;
//	scanf("%d",&t);
	fru(i,t) solve();
	return 0;
}