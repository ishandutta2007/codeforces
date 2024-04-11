#include<bits/stdc++.h>
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;
void solve(){
    int n;cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    if(n%2==1){
        cout<<"NO"<<"\n";
        return;
    }
    sort(arr,arr+n);
    ll ans[n];
    int last = n-1;
    int start = n/2 - 1;
    for(int i=0;i<n;i++){
        if(i%2==0){
            ans[i]=arr[last];
            last--;
        }else{
            ans[i]=arr[start];
            start--;
        }
    }
    for(int i=0;i<n;i++){
        if((ans[i]-ans[(i+1)%n])*(ans[i]-ans[(i-1+n)%n])>0) continue;
        cout<<"NO"<<"\n";
        return;
    }
    cout<<"YES"<<"\n";
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin>>T;
    for(long long int i=0;i<T;i++){
        solve();
    }   
}