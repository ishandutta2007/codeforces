#include <iostream>
#include <cstdio>
using namespace std;
const int N = 200010;
int n, m, a[N], cnt = 0, tot = 0;
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", a + i);
        cnt = (tot + a[i]) / m;
        tot = (tot + a[i]) % m;
        printf("%d ", cnt);
    } 
}