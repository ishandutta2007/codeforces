#include<bits/stdc++.h>
#define int long long
using namespace std;
int const MOD=1000000007;
int n,f,g=1,t;
signed main(){
    cin>>n;
    for(int i=2;i<=n;++i)
        t=f,f=3*g%MOD,g=(t+2*g)%MOD;
    cout<<f<<"\n";
}