#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
long long n,m,k,a[maxn],f;
long long ans;
int main(){
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    long long l=m/(k+1);
    ans+=((k*a[n]+a[n-1])*l);
    m%=(k+1);
    ans+=(a[n]*m);
    printf("%lld\n",ans);
}