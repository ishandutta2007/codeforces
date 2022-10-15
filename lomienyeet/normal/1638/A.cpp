#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    int ptr=1,pos;
    while(ptr<n&&arr[ptr-1]==ptr)ptr++;
    for(int i=0;i<n;i++){
        if(arr[i]==ptr){
            pos=i;
            break;
        }
    }
    reverse(arr.begin()+ptr-1,arr.begin()+pos+1);
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    cout<<"\n";
}
signed main(){
    int t;
    cin>>t;
    while(t--)solve();
}