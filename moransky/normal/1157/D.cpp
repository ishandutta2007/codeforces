#include <cstdio>
#include <iostream>
using namespace std;
const int K = 100010;
typedef long long LL;
int n, k, a[K];
int main(){
    scanf("%d%d", &n, &k);
    LL S = 0;
    for(int i = 1; i <= k; i++) a[i] = i, S += i;
    if(S > n) { puts("NO"); return 0; }
    int d = (n - S) / k, l = (n - S) % k;
    for(int i = 1; i <= k; i++) a[i] += d;
    int r = k;

    while(l){
        while(l && a[r] + 1 <= a[r - 1] * 2) l--, a[r]++;
        r--;
        if(l && a[r] + 1 > a[r - 1] * 2) { puts("NO"); return 0; }
    }  
    puts("YES");
    for(int i = 1; i <= k; i++) 
        printf("%d ", a[i]);
    return 0;
}