#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
double pi = acos(-1.0);
const int maxn = 1e6+38;
const int mod = 1e9+7;

ll n,m,q;

int main() {
    scanf("%lld%lld",&n,&q);
    for(int i=1;i<=q;i++){
        ll x,y;
        scanf("%lld%lld",&x,&y);
        ll ans = 0;
        if((x+y)%2==0){
            if(x%2==0){
                ans = (x-1)/2*n + (n+1)/2 + y/2;
            }
            else{
                ans = x/2*n + (y+1)/2;
            }
        }
        else{
            ans = (n*n+1)/2;
            if(x%2==0){
                ans += (x-1)/2*n+(n)/2+(y+1)/2;
            }
            else{
                ans += x/2*n + (y+1)/2;
            }
        }
        printf("%lld\n",ans);
    }
    
    
    
    
}