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
const int M = 1000000007;
const int MAXL = 110;
const int MAXN = 26*MAXL;

ll DP[MAXL][MAXN];
char S[MAXL];

void solve() {
    scanf("%s",S);
    int n = strlen(S), sum = 0;
    fru(i,n) sum += S[i]-'a';
    printf("%d\n", (int)((DP[n][sum]-1+M)%M));
}

int main() {
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
    DP[0][0] = 1;
    fru(i,MAXL) if(i) {
        fru(j,MAXN) {
            fru(k,26) {
                if(j+k >= MAXN) break;
                DP[i][j+k] += DP[i-1][j];
            }
        }
        fru(j,MAXN) DP[i][j] %= M;
    }
	int t=1;
	scanf("%d",&t);
	fru(i,t) solve();
	return 0;
}