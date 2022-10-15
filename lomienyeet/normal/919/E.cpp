#include <bits/stdc++.h>
using namespace std;
#define int long long
int bm(int b,int p,int m){
    int ans=1;
    b%=m;
    while(p){
        if(p&1)(ans*=b)%=m;
        (b*=b)%=m;
        p>>=1;
    }
    return ans;
}
signed main(){
    int a,b,p,x;
    cin>>a>>b>>p>>x;
    int ans=0;
    for(int i=1;i<p;i++){
        int z=(b*bm(bm(a,i,p),p-2,p)+p)%p,weeee=(p-1)*((i-z+p)%p)+i;
        if(weeee>x)continue;
        ans+=(x-weeee)/(p*(p-1))+1;
    }
    cout<<ans<<"\n";
}