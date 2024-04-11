#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int t, n;
ll a[33], m;
int main(){
    scanf("%d",&t);
    while(t--){
        int fl = 0;
        scanf("%d %lld",&n,&m);

        for(int i=1;i<=n;i++) scanf("%lld",a+i);

        ll u = 1, mx = *max_element(a+1, a+1+n);
        while(u <= mx){
            int fl2 = 0;
            ll v = u * m;
            for(int i=1;i<=n;i++){
                if(a[i] % v){
                    if(fl2){
                        fl = 1;
                        break;
                    }
                    a[i] -= u;
                    fl2 = 1;
                    if(a[i] % v){
                        fl = 1;
                        break;
                    }
                }
            }
            u *= m;
        }

        puts(fl ? "NO" : "YES");
    }
}