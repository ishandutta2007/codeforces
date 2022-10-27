#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
#define int long long
int x,sum,n,m,l,r,l1;
int add(int a,int b){
    a%=mod;b%=mod;
    a+=b;
    return a>=mod?a-mod:a;
}
int sub(int a,int b){
    a%=mod;
    b%=mod;
    return a<b?a-b+mod:a-b;
}
int mul(int a,int b){
    a%=mod;
    b%=mod;
    return (int)((1ll*a*b)%mod);
}
int c(int a){
    a%=mod;
    return (int)((1ll*a*(a+1)/2)%mod);
}
int cal(int a,int b){
    a%=mod;
    b%=mod;
    return sub(c(b),c(a-1));
}

signed main(){
    scanf("%lld%lld",&n,&m);
    l1=min(n,m);
    x=(int)sqrt(n);
    for(int i=1;i<=x;i++){
        l=(n/(i+1));
        r=min({n,m,n/i});
        if(l>=r)continue;
        sum=add(sum,mul(cal(l+1,r),i));
        l1=l;
    }
    for(int i=1;i<=l1;i++){
        sum=add(sum,mul(i,(n/i)));
    }
    printf("%lld\n",sub((mul(n,m)),sum));
}