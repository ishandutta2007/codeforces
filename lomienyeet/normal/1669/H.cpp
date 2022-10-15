// i am just doing this to lower my TLE bot virtual solve speed

#include <bits/stdc++.h>
using namespace std;
#define int long long
void eat(){
    int n,k;
    cin>>n>>k;
    int freq[31]={};
    for(int i=1,x;i<=n;i++){
        cin>>x;
        for(int j=0;j<31;j++)freq[j]+=((x>>j)&1);
    }
    int ans=0;
    for(int i=30;i>=0;i--){
        if(n-freq[i]<=k){
            ans+=(1<<i);
            k-=n-freq[i];
        }
    }
    cout<<ans<<"\n";
}
signed main(){
    int t=1;
    cin>>t;
    while(t--)eat();
}