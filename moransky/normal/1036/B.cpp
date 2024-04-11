#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
int q;
int main(){
    scanf("%d", &q);
    while(q--){
        LL n, m, k, ans; cin >> n >> m >> k;
        if(max(n, m) > k) puts("-1");
        else{
            if((abs(n - m) & 1) == 0 && (k - min(n, m)) & 1)
                n--, m--, k-=2;
            ans = min(n, m); k -= min(m, n);
            if(abs(m - n) & 1) ans += k - 1;
            else ans += k;
            cout << ans << endl;
        }
    }
    return 0;
}