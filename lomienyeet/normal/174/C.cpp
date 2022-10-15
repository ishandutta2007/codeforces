// seems like, most of the "hard" ds near purple is ms/mq

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
signed main(){
    int n;
    cin>>n;
    int arr[n+2];
    for(int i=1;i<=n;i++)cin>>arr[i];
    arr[n+1]=0;
    stack<pair<int,int> > ms;
    vector<pair<int,int> > ans;
    ms.push({0,0});
    for(int i=1;i<=n+1;i++){
        while(ms.size()&&ms.top().ff>arr[i]){
            ans.push_back({ms.top().ss,i-1});
            ms.pop();
        }
        for(int j=ms.top().ff+1;j<=arr[i];j++)ms.push({j,i});
    }
    cout<<ans.size()<<"\n";
    for(auto i:ans)cout<<i.ff<<" "<<i.ss<<"\n";
}