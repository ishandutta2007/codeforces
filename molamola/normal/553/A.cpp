#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()

int n;
int nCr[2010][2010];

const ll MOD = 1e9 + 7;
ll ans = 1;

int main() {
    nCr[0][0] = nCr[1][0] = nCr[1][1] = 1;
    for(int i=2;i<=2005;i++){
        nCr[i][0] = 1;
        for(int j=1;j<=i;j++)nCr[i][j] = (nCr[i-1][j-1] + nCr[i-1][j]) % MOD;
    }
    scanf("%d",&n);
    int x = 0;
    for(int i=0;i<n;i++){
        int y; scanf("%d",&y);
        ans *= nCr[x+y-1][y-1];
        ans %= MOD;
        x += y;
    }
    printf("%lld", ans);
    return 0;
}