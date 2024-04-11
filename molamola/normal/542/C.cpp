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
#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()

int n, f[220];
ll ans, ans2;
int chk[220];

ll gc(ll x, ll y){return y ? gc(y, x%y) : x;}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",f+i);
    ans = 1;
    for(int i=1;i<=n;i++){
        int t = i, j;
        for(j=1;j<=n+1;j++){
            t = f[t];
            if(t == i)break;
        }
        if(j != n+2)ans = ans * j / gc(ans, j), chk[i] = 1;
    }
    for(int i=1;i<=n;i++){
        int t = i, j;
        for(j=1;j<=n+1;j++){
            t = f[t];
            if(chk[t])break;
        }
        if(!chk[i]){
            ans2 = max(ans2, (ll)j);
        }
    }
    ll t = ans;
    while(t < ans2)t += ans;
    printf("%lld", t);
    return 0;
}