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
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()

const ll MOD = 1e9 + 7;
ll F[200020];
ll inv[200020];

ll pow(ll x,ll y){
    ll res = 1;
    while(y){
        if(y&1)res = (res * x) % MOD;
        x = (x * x) % MOD;
        y >>= 1;
    }
    return res;
}

ll get(int x, int y){
    ll res = F[x+y];
    res = (res * inv[x]) % MOD;
    res = (res * inv[y]) % MOD;
    return res;
}

struct pt{
    int x, y;
    bool operator<(const pt &l)const{
        return x+y < l.x+l.y;
    }
}p[2020];
ll d[2020];

int main() {
    F[0] = F[1] = 1;
    for(int i=1;i<=200010;i++){
        F[i] = (i * F[i-1]) % MOD;
        inv[i] = pow(F[i], MOD-2);
    }
    inv[0] = inv[1];
    int r, c, n;
    scanf("%d%d%d",&r,&c,&n);
    for(int i=0;i<n;i++){
        scanf("%d%d", &p[i].x, &p[i].y);
    }
    sort(p, p+n);
    ll ans = get(r-1, c-1);
    for(int i=0;i<n;i++){
        ll tmp = get(p[i].x-1, p[i].y-1);
        for(int j=0;j<i;j++){
            if(p[j].x <= p[i].x && p[j].y <= p[i].y){
                tmp -= d[j] * get(p[i].x-p[j].x, p[i].y-p[j].y) % MOD;
                tmp = (tmp + MOD) % MOD;
            }
        }
        d[i] = tmp;
        ans -= d[i] * get(r-p[i].x, c-p[i].y) % MOD;
        ans = (ans + MOD) % MOD;
    }
    printf("%lld", ans);
    return 0;
}