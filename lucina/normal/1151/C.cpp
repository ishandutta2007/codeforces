#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10,mod=1e9+7;
#define ll long long
ll l,r,inv;

ll mul(ll a,ll b){
    return (a*b)%mod;
}
ll solve(ll x){
    if(x==0)return 0ll;
    ll res=1,even=0,odd=1;
    int power=0;
    ll res2=1;
    while((res<<1)+1<=x){
        res<<=1;
        res++;
        res2<<=1;
        power++;
       // cout<<res2<<endl;
        if(power&1){
            even+=res2;
        }
        else
            odd+=res2;

    }
   // cout<<res<<endl;
    //cout<<res2<<endl;;
     //   cout<<odd<<' '<<even<<endl;
    odd%=mod;
    even%=mod;
    ll ret=x-res;
    //cout<<ret<<endl;
    ll ans=0;
    power++;
    if(power&1)
        even+=(ret);
    else odd+=ret;
   // cout<<odd<<' '<<even<<endl;
    odd%=mod;
    even%=mod;
    ans+=((mul(even,even+1))%mod);
    ans%=mod;
    ans+=(mul(odd,odd));
    ans%=mod;
    return ans;

}
int main(){
    scanf("%lld%lld",&l,&r);
    printf("%lld\n",(((solve(r)-solve(l-1))%mod+mod)%mod));
}