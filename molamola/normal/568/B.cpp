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

const ll MOD = 1e9 + 7;
int nr[4040][4040];
int e[4040], d[4040];

int main(){
    nr[0][0] = nr[1][0] = nr[1][1] = 1;
    for(int i=2;i<=4020;i++){
        nr[i][0] = 1;
        for(int j=1;j<=i;j++)nr[i][j] = (nr[i-1][j-1] + nr[i-1][j]) % MOD;
    }
    e[0] = 1, e[1] = 2;
    for(int i=2;i<=4020;i++){
        e[i] = e[i-1];
        for(int j=0;j<i;j++)e[i] = (e[i] + (ll)nr[i-1][j] * e[i-1-j]) % MOD;
    }
    d[0] = d[1] = 1;
    for(int i=2;i<=4020;i++){
        d[i] = 0;
        for(int j=0;j<i;j++)d[i] = (d[i] + (ll)nr[i-1][j] * d[i-1-j]) % MOD;
    }
    int n; scanf("%d",&n);
    int ans = (e[n] - d[n] + MOD) % MOD;
    printf("%d",ans);
    return 0;
}