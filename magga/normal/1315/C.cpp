#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n;cin>>n;
    set<long long int>s;
    set<long long int>se;
    for(long long int i=1;i<=2*n;i++){
        s.insert(i);
        se.insert(-1*i);
    }
    s.insert(2*n+1);
    long long int arr[n];
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
        s.erase(arr[i]);
        se.erase(-1*arr[i]);
    }
    long long int ans[2*n];
    for(long long int i=0;i<n;i++){
        ans[2*i]=arr[i];
        ans[2*i+1]=*s.lower_bound(ans[2*i]);
        if(ans[2*i+1]==2*n+1){
            cout<<-1<<"\n";
            return;
        }
        s.erase(ans[2*i+1]);
        se.erase(-1*ans[2*i+1]);
    }
    for(long long int i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}