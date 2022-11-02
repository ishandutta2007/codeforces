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
const int MAXN = 2006;

char S[MAXN], T[MAXN];
int E[MAXN][MAXN];

void solve() {
    scanf("%s%s",S,T);
    int n = strlen(T);
    int m = strlen(S);
    fru(i,n+1) {
        E[i][0] = i;
    }
//  fru(i,n+1) { fru(j,m+1) printf("%d ",E[i][j]); puts(""); }
    fru(j,m) fru(i,n) {
        E[i+1][j+1] = E[i][j]+(T[i]!=S[j]);
    }
//  fru(i,n+1) { fru(j,m+1) printf("%d ",E[i][j]); puts(""); }
    fru(i,n) {
        E[i+1][m] = min(E[i+1][m], E[i][m]+1);
    }
    fru(j,m+1) {
        E[n][j+1] = min(E[n][j+1], E[n][j]);
    }
//  fru(i,n+1) { fru(j,m+1) printf("%d ",E[i][j]); puts(""); }
    printf("%d\n", E[n][m]);
}

int main() {
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int t=1;
//	scanf("%d",&t);
	fru(i,t) solve();
	return 0;
}