#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100000;
const int MOD = 10007;
int A[MAXN+10];
int main(){
    int n;
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
        scanf("%d", &A[i]);
    sort(A+1, A+1+n);
    int ans = 0;
    for(int i=1;i<=n;i++)
        (ans += A[i]%MOD*A[n-i+1]%MOD)%=MOD;
    printf("%d\n", ans);
    
    return 0;
}