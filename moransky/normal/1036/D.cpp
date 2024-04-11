#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
const int N = 300010;
int n, m, ans = 0;
LL a[N], b[N];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%lld", a + i), a[i] += a[i - 1];
    scanf("%d", &m);
    for(int i = 1; i <= m; i++) scanf("%lld", b + i), b[i] += b[i - 1];
    if(a[n] != b[m]) puts("-1");
    else{
        int i = 1, j = 1;
        while(true){
            if(i > n || j > m) { puts("-1"); break; }
            while(a[i] < b[j]){
                if(i + 1 > n) { puts("-1"); return 0; }
                i++;
            }
            while(a[i] > b[j]){
                if(j + 1 > m){ puts("-1"); return 0; }
                j++;
            }
            if(a[i] == b[j]){
                i++, j++, ans++;
                if(i == n + 1 && j == m + 1) { printf("%d\n", ans); break; }
            }
        }
    }
    return 0;
}