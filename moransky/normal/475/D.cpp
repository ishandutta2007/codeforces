#include <cstdio>
#include <iostream>
#include <cmath>
#include <unordered_map>
using namespace std;
typedef long long LL;
const int N = 100005, L = 18;
int n, a[N], Log[N], f[N][L];
unordered_map<int, LL> st;
int gcd(int x, int y){
    return y ? gcd(y, x % y) : x;
}
void ST_prework(){
    for(int i = 1; i <= n; i++){
        f[i][0] = a[i];
        Log[i] = log(i) / log(2);
    }
    for(int j = 1; j <= Log[n]; j++){
        for(int i = 1; i + (1 << j) - 1 <= n; i++){
            f[i][j] = gcd(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }
}
int inline query(int l, int r){
    int t = Log[r - l + 1];
    return gcd(f[l][t], f[r - (1 << t) + 1][t]);
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", a + i);
    ST_prework();
    for(int i = 1; i <= n; i++){
        int j = i, x;
        while(j <= n){
            x = query(i, j);
            int l = j, r = n;
            while(l < r){
                int mid = (l + r + 1) >> 1;
                if(query(i, mid) == x) l = mid;
                else r = mid - 1;
            }
            st[x] += r - j + 1;
            j = r + 1;
        }
    }
    int q; scanf("%d", &q);
    while(q--){
        int x; scanf("%d", &x);
        printf("%lld\n", st[x]);
    }
    return 0;
}