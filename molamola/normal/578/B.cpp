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

int n, x, k;
ll a[200020];
ll l[200020], r[200020];

int main() {
    scanf("%d%d%d",&n,&k,&x);
    for(int i=1;i<=n;i++)scanf("%lld",a+i);
    for(int i=1;i<=n;i++)l[i] = l[i-1] | a[i];
    for(int i=n;i;i--)r[i] = r[i+1] | a[i];
    ll ans = l[n];
    for(int i=1;i<=n;i++){
        ll y = a[i];
        for(int u=0;u<k;u++)y *= x;
        ans = max(ans, l[i-1] | r[i+1] | y);
    }
    printf("%lld",ans);
    return 0;
}