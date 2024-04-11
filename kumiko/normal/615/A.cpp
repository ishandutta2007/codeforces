#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long

int n, m, p, x;
int a[200];

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &x);
        for(int j = 1; j <= x; j++) 
            scanf("%d", &p), a[p] = 1;
    }
    bool ok = 1;
    for(int i = 1; i <= m; i++) if (a[i] == 0) ok = 0;
    printf("%s", ok ? "YES" : "NO");
  return 0;
}