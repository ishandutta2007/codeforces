#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
const int N = 1000010, INF = 0x3f3f3f3f;
typedef long long LL;
int n, x, S[N], T[N], Sx[N], Tx[N];
int a[N];
LL ans = 0;
int main(){
    memset(S, 0x3f, sizeof S);
    scanf("%d%d", &n, &x);
    for(int i = 1; i <= n; i++){
        scanf("%d", a + i);
        if(S[a[i]] == INF) S[a[i]] = i;
        T[a[i]] = i;
    }
    for(int i = 1; i <= x; i++)
        Tx[i] = max(Tx[i - 1], T[i]);
    
    Sx[x + 1] = INF;
    for(int i = x; i; i--)
        Sx[i] = min(Sx[i + 1], S[i]);
    
    int r = x - 1;
    while(r && T[r] < Sx[r + 1]) r--;
    for(int l = 1; l <= x; l++){
        if(l > 2 && S[l - 1] < Tx[l - 2]) break;
        while(r <= x && (r < l || Tx[l - 1] > Sx[r + 1])) 
            r++;
        ans += x - r + 1;
    }
    printf("%lld\n", ans);
    return 0;
}