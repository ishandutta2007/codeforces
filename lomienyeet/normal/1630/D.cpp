// why are all the orz people always so inch
// am i doomed forever to be a faipotato trying and never succeeding?

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
void eat(){
    int n,m;
    cin>>n>>m;
    int arr[n+1],ans=0;
    pair<int,int> e={0,0};
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        ans+=abs(arr[i]);
    }
    int g;
    cin>>g;
    for(int i=1,x;i<m;i++){
        cin>>x;
        g=gcd(g,x);
    }
    for(int i=1;i<=g;i++){
        int z=0,mini=1e18;
        for(int j=i;j<=n;j+=g){
            if(arr[j]<0)z++;
            mini=min(mini,abs(arr[j]));
        }
        if(!(z&1))e.ff+=mini;
        else e.ss+=mini;
    }
    cout<<ans-min(e.ff,e.ss)*2<<"\n";
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)eat();
}