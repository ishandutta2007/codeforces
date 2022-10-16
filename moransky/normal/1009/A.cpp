#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1010;
int n, m, c[N], a[N], ans = 0;
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", c + i);
    for(int i = 1; i <= m; i++) scanf("%d", a + i);
    for(int i = 1, j = 1; i <= n; i++)
        if(c[i] <= a[j]) ans ++, j++; 
    printf("%d", ans);
    return 0;
}