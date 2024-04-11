#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 200005, L = 19;
int n, a[N], b[N], tot = 0;
int Log2[N], fMax[N][L], fMin[N][L];
LL ans = 0;
void ST_prework(){
    for(int i = 1; i <= n; i++){
        Log2[i] = log(i) / log(2);
        fMax[i][0] = a[i];
        fMin[i][0] = b[i]; 
    }
    int t = log(n) / log(2) + 1;
    for(int j = 1; j < t; j++){
        for(int i = 1; i + (1 << j) - 1 <= n; i++){
            fMax[i][j] = max(fMax[i][j - 1], fMax[i + (1 << (j - 1))][j - 1]);
            fMin[i][j] = min(fMin[i][j - 1], fMin[i + (1 << (j - 1))][j - 1]);
        }
    }
}
int inline getMax(int l, int r){
    int t = Log2[r - l + 1];
    return max(fMax[l][t], fMax[r - (1 << t) + 1][t]);
}
int inline getMin(int l, int r){
    int t = Log2[r - l + 1];
    return min(fMin[l][t], fMin[r - (1 << t) + 1][t]);
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for(int i = 1; i <= n; i++)
        scanf("%d", b + i);

    ST_prework();
    for(int i = 1; i <= n; i++){
        int x, y, l = i, r = n;
        // max 
        // min 
        while(l < r){
            int mid = (l + r) >> 1;
            if(getMax(i, mid) >= getMin(i, mid)) r = mid;
            else l = mid + 1;
        }
        x = r;
        if(getMax(i, x) != getMin(i, x)) continue;

        l = x, r = n;
        while(l < r){
            int mid = (l + r + 1) >> 1;
            if(getMax(i, mid) > getMin(i, mid)) r = mid - 1;
            else l = mid;
        }
        
        ans += r - x + 1;
    }
    printf("%lld\n", ans);
    return 0;
}