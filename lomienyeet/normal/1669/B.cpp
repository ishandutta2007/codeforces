// i am just doing this to lower my TLE bot virtual solve speed

#include <bits/stdc++.h>
using namespace std;
#define int long long
void eat(){
    int n;
    cin>>n;
    int arr[n+1];
    map<int,int> mp;
    bool ok=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        mp[arr[i]]++;
        if(mp[arr[i]]>=3&&!ok){
            cout<<arr[i]<<"\n";
            ok=1;
        }
    }
    if(!ok)cout<<"-1\n";
}
signed main(){
    int t=1;
    cin>>t;
    while(t--)eat();
}