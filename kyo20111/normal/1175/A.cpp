#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll n,k;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%lld %lld",&n,&k);
        ll cnt=0;
        while(n){
            cnt += n%k;
            n/=k;
            cnt++;
        }
        printf("%lld\n",cnt-1);
    }
}