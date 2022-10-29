#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;

ll a[50005];

ll abs(ll x){
    return (x>0)?x:(-x);
}

int main(){
    int n,i,k;
    ll s=0;
    scanf("%d",&n);
    for(i=0;i<n;++i){
        scanf("%d",&k);
        a[i]=k;
        s+=k;
    }
    s/=n;
    for(i=0;i<n;++i){
        a[i]-=s;
    }
    ll r=0;
    for(i=0;i<n;++i){
        r+=abs(a[i]);
        a[i+1]+=a[i];
    }
    cout<<r<<endl;
    return 0;
}