#include <bits/stdc++.h>
using namespace std;
#define int long long
void eat(){
    int n,m;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        arr[i]=bitset<63>(s).to_ullong();
    }
    sort(arr,arr+n);
    int ans=((1ll<<m)-n-1)>>1;
    for(int i=0;i<n;i++){
        if(arr[i]<=ans)ans++;
    }
    cout<<bitset<63>(ans).to_string().substr(63-m)<<"\n";
}
signed main(){
    int t;
    cin>>t;
    while(t--)eat();
}