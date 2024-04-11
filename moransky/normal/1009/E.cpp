#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
const int N = 1000010, Mod = 998244353;
int n, a[N], s, g;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    for(int i = 1; i <= n; i++){
        s = ((LL)s * 2 + a[i] + a[i - 1] + g * 2) % Mod;
        g = ((LL)g * 2 + a[i - 1]) % Mod;
    }
    cout << s;
    return 0;
}