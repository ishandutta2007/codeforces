#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define rep(i, n) for(int i=0;i<n;i++)
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define szz(x) (int)(x).size()
#define Fi first
#define Se second

const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f;
const ll MOD = 1000000007;
const int IT_MAX = 1 << 17;

const int MX = 1000005;

int P = 67;
char in1[2050][2050];
char in2[2050][2050];

ll sum1[2050][2050];
ll sum2[2050][2050];

ll po[4200050];
int main() {
    int N, M, i, j, k, l;
    scanf("%d %d", &N, &M);
    for(i = 1; i <= N; i++) scanf("%s", in1[i] + 1);
    for(i = 1; i <= M; i++) scanf("%s", in2[i] + 1);

    po[0] = 1;
    for(i = 1; i <= 4200000; i++) po[i] = po[i-1] * P % MOD;

    for(i = 1; i <= N; i++) {
        for(j = 1; j <= M; j++) {
            sum1[i][j] = sum1[i-1][j] + sum1[i][j-1] - sum1[i-1][j-1];
            sum1[i][j] += in1[i][j] * po[i*M+j] % MOD;
            sum1[i][j] = (sum1[i][j] % MOD + MOD) % MOD;
        }
    }
    for(i = 1; i <= M; i++) {
        for(j = 1; j <= N; j++) {
            sum2[i][j] = sum2[i-1][j] + sum2[i][j-1] - sum2[i-1][j-1];
            sum2[i][j] += in2[i][j] * po[i*M+j] % MOD;
            sum2[i][j] = (sum2[i][j] % MOD + MOD) % MOD;
        }

    }

    for(i = 1; i <= N-M+1; i++) {
        for(j = 1; j <= N-M+1; j++) {
            ll s1 = sum1[i+M-1][M] - sum1[i-1][M];
            ll s2 = sum2[M][j+M-1] - sum2[M][j-1];

            ll v1 = i*M+1, v2 = M+j;
            s1 *= po[v2];
            s2 *= po[v1];
            s1 = (s1%MOD+MOD)%MOD;
            s2 = (s2%MOD+MOD)%MOD;

            if(s1 != s2) continue;

            for(k = 1; k <= M; k++) {
                for(l = 1; l <= M; l++) {
                    if(in1[i+k-1][l] != in2[k][j+l-1]) break;
                }
                if(l <= M) break;
            }
            if(k > M) return !printf("%d %d\n", i, j);
        }
    }
    return 0;
}