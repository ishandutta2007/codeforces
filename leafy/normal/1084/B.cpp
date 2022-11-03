#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;ll s;
ll a[10005];
int main(){
    cin>>n>>s;ll sum=0;
    for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
    if(sum<s){printf("-1");return 0;}
    ll t=*min_element(a+1,a+n+1);
    for(int i=1;i<=n;i++) {
        s-=(a[i]-t);
        if(s<=0) {printf("%d",t);return 0;}
    }
    cout<<t-((s+n-1)/n);
    return 0;
}