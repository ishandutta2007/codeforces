#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(arr[i]==i){
            cout<<"YES\n";
            for(int j=1;j<=n;j++){
                if(i!=j)cout<<i<<" "<<j<<"\n";
            }
            return 0;
        }
    }
    int u=-1,v=-1;
    for(int i=1;i<=n;i++){
        if(arr[arr[i]]==i){
            u=i;
            v=arr[i];
        }
    }
    if(u==-1){
        cout<<"NO\n";
        return 0;
    }
    vector<pair<int,int> > ans;
    ans.push_back({u,v});
    int cyc[n+1]={},z=0;
    for(int i=1;i<=n;i++){
        if(!cyc[i]){
            z++;
            int ptr=i,sz=0;
            while(!cyc[ptr]){
                if(ptr!=u&&ptr!=v){
                    if(sz&1)ans.push_back({v,ptr});
                    else ans.push_back({u,ptr});
                }
                cyc[ptr]=z;
                ptr=arr[ptr];
                sz++;
            }
            if(sz&1){
                cout<<"NO\n";
                return 0;
            }
        }
    }
    cout<<"YES\n";
    for(auto i:ans)cout<<i.first<<" "<<i.second<<"\n";
}