#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 3e5+10;
int n;
int a[maxn], ct[2];
ll x, ans;

int main(){
    scanf("%d",&n);
    for(int i = 1 ;i<= n;i ++){
        scanf("%lld" ,&x);
        a[i] = __builtin_popcountll(x);
    }
    /**
        Q: What is the necessary condition for good sequence ?
        A:  1) The sum must be even.
            2) The maximum must be <= sum / 2
        Q2 : Is this the sufficient condition then ?
        A: Since the maximum <= sum / 2. We can simply put all bits without intersection first
        and ignore maximum one
        Then, in each step we can reduce summation of the rest bits by 2
        Continue this until the standing bit = the maximum one and simply move it to make xor = 0
        ok, let's count sub range with even sum first and subtract with the one maximum > sum / 2
    */
    int cur = 0;
    ct[0] ++ ;
    for(int i=1 ;i <= n;i ++){
            cur ^= (a[i] & 1);
            ans += ct[cur];
            ct[cur] ++;
    }
   // for(int i = 1 ;i <= n; i++)
   //     cout << a[i] << ' ';
   // cout << endl;
   // cout << ans << endl;
    for(int i=1 ;i <= n ; i++){
        int keep = 0 , ma = 0;
        for(int j = 0 ; j < 63 && (i + j <= n) ;j ++){
            keep += a[i + j];
            ma = max(ma , a[i + j]);
            if(keep % 2 == 0){
                if(ma > keep / 2)
                    ans --;
            }
        }
    }
    printf("%lld\n", ans);
}