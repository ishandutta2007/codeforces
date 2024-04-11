#include <iostream>
#include <cstdio>
using namespace std;
const int N = 110;
int n, m, a[N], b[N], ans = 0;
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", a + i), ans ^= a[i];
    for(int i = 1; i <= m; i++) scanf("%d", b + i), ans ^= b[i];

    if(ans != 0)puts("NO");
    else{
        puts("YES");
        ans = b[m];
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++)
                printf("0 ");
            printf("%d\n", a[i]);
            ans ^= a[i];
        }
        b[m] = ans;
        for(int i = 1; i <= m; i++) printf("%d ", b[i]);
    }
    return 0;
}