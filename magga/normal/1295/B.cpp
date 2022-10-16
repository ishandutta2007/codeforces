#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n,x;cin>>n>>x;
    string s;cin>>s;
    long long int arr[n+1];
    map<long long int,long long int>m;
    arr[0]=0;
    for(long long int i=0;i<n;i++){
        if(s[i]=='1'){
            arr[i+1]=arr[i]-1;
        }else{
            arr[i+1]=arr[i]+1;
        }
        //cout<<arr[i+1]<<" ";
        m[arr[i+1]]++;
    }
    //cout<<"\n";
    long long int p = arr[n];
    if(p==0){
        if(m.find(x)==m.end() && x==0){
            cout<<1<<"\n";
        }else if(m.find(x)==m.end()){
            cout<<0<<"\n";
        }else{
            cout<<-1<<"\n";
        }
        return;
    }
    long long int ans = 0 ;
    for(auto i : m){
        //cout<<i.first<<" "<<i.second<<"\n";
        if((x-i.first)%p==0 && (x-i.first)/p >= 0){
            ans+=i.second;
        }
    }
    if(x==0){
        ans++;
    }
    cout<<ans<<"\n";
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