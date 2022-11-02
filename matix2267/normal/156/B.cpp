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

int S[2][MAXN], A[MAXN];
char C[MAXN], P[MAXN];

void solve() {
    int n,m;
    scanf("%d%d",&n,&m);
    int sum = 0;
    fru(i,n) {
        scanf(" %c%d",&C[i],&A[i]);
        C[i] = C[i] == '+';
        A[i]--;
        S[C[i]][A[i]]++;
        sum += !C[i];
    }
    int pot = 0;
    fru(i,n) {
        if(sum - S[0][i] + S[1][i] == m) {
            pot++;
            P[i] = 1;
        }
    }
    assert(pot > 0);
    fru(i,n) {
        if(pot > 1 && P[A[i]]) puts("Not defined");
        else puts(C[i] == P[A[i]] ? "Truth" : "Lie");
    }
}

int main() {
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int t=1;
//	scanf("%d",&t);
	fru(i,t) solve();
	return 0;
}