#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int q;
ll arr[101010],ch[101010],psum[101010],n;
int main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&arr[i]);
    sort(arr+1,arr+1+n);
    for(int i=1;i<n;i++) ch[i]=arr[i+1]-arr[i];
    sort(ch+1,ch+n);
    for(int i=1;i<n;i++) psum[i]=psum[i-1]+ch[i];
    scanf("%d",&q);
    while(q--){
        ll a,b;
        scanf("%lld %lld",&a,&b);
        b=b-a+1;
        ll l=1,r=n-1;
        while(l<=r){
            ll mid=(l+r)/2;
            if(ch[mid]>b) r=mid-1;
            else l=mid+1;
        }
        printf(" %lld",arr[n]-arr[1]+1-psum[n-1]+psum[l-1]+b*(n-l+1)-1);
    }
}