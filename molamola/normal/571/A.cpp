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

ll ans;

int main(){
    int a, b, c, l;
    scanf("%d%d%d%d",&a,&b,&c,&l);
    for(int i=0;i<=l;i++){
        int m = max(-1, min(a - b - c + i, l - i));
        ans += (ll)(m+1) * (m+2) / 2;
        m = max(-1, min(b - a - c + i, l - i));
        ans += (ll)(m+1) * (m+2) / 2;
        m = max(-1, min(c - a - b + i, l - i));
        ans += (ll)(m+1) * (m+2) / 2;
    }
    printf("%lld\n",(ll)(l+1) * (l+2) * (l+3) / 6 - ans);
    return 0;
}