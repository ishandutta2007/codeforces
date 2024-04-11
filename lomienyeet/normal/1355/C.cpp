// dream solister is good song

#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int delta[1000005]={};
    for(int i=a;i<=b;i++){
        delta[b+i]++;
        delta[c+i+1]--;
    }
    int ps[1000005]={};
    for(int i=1;i<=1000004;i++)ps[i]=ps[i-1]+delta[i];
    for(int i=1000003;i>0;i--)ps[i]+=ps[i+1];
    int ans=0;
    c++;
    d++;
    for(int i=c;i<=d;i++)ans+=ps[i];
    cout<<ans<<"\n";
}