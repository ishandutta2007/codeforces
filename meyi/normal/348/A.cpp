#include<cstdio>
typedef long long ll;
ll a[1000001],n;
inline ll bfind(ll l,ll r,ll s){
    ll ans=-1;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(mid*(n-1)>=s)ans=mid,r=mid-1;
        else l=mid+1;
    }
    return ans;
}
main(){
    scanf("%lld",&n);
    ll s=0,x=0;
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
        x=(x>a[i]?x:a[i]);
        s+=a[i];
    }
    printf("%lld",bfind(x,s,s));
}