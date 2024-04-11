#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n,m,ans=1;
    cin>>n>>m;
    bool sv[m*19+1]={},done[n+1]={};
    vector<int> e;
    for(int i=1;i<20;i++){
        int c=0;
        for(int j=1;j<=m;j++){
            if(sv[i*j])continue;
            sv[i*j]=1;
            c++;
        }
        e.push_back(c);
    }
    for(int i=2;i<=n;i++){
        if(done[i])continue;
        int ptr=i,cnt=0;
        while(ptr<=n){
            done[ptr]=1;
            ans+=e[cnt++];
            ptr*=i;
        }
    }
    cout<<ans<<"\n";
}