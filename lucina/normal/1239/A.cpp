#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10, mod = 1e9+7;
int n,m, f[maxn];
int add(int a, int b){
    a += b;
    return a >= mod ? a - mod : a;
}

int main(){
    scanf("%d %d", &n, &m);
    int go = max(n , m);
    f[1] = 1, f[0] = 1;
    for(int i = 2 ;i <= go ;i++){
        f[i] = add(f[i - 1], f[i - 2]);
    }
    printf("%d\n", (2 * (add(f[n], f[m] - 1))) % mod);
}