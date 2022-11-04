#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,p,c[100];
ll chk(ll a,ll b){
    for(int i=1;i<=a;i++) c[i] = 0;

    int cur = 1;
    while(b--){
        c[cur]++;
        cur = cur%a+1;
    }
    ll sum = 0;
    for(int i=1;i<=a;i++) sum += 1ll<<(c[i]-1);
    return sum;
}
int main(){
    scanf("%lld %lld",&n,&p);
    for(int i=1;i<=40;i++){
        if(n-p*i < 1) continue;
        int m = __builtin_popcount(n-p*i);
        if(m == i || (m < i && n-p*i >= chk(m, i))) return !printf("%d",i);
    }
    printf("-1");
}