#include<bits/stdc++.h>
using namespace std;
void pre(){}
char c(int i){
    return char(i+'a');
}
void solve(){
    long long int n,m;cin>>n>>m;
    string s;cin>>s;
    map<char,long long int>g;
    long long int arr[m];
    for(long long int i=0;i<m;i++){
        cin>>arr[i];
        arr[i]--;
    }
    for(int i =0 ;i<26;i++){
        g[c(i)]=0;
    }
    long long int ans[n];
    for(long long int i=0;i<n;i++){
        ans[i]=0;
    }
    for(long long int i=0;i<m;i++){
        ans[arr[i]]++;
    }
    for(long long int i=n-2;i>=0;i--){
        ans[i]+=ans[i+1];
    }
    for(long long int i=0;i<n;i++){
        g[s[i]]+=ans[i];
        g[s[i]]++;
    }
    for(auto i:g){
        cout<<i.second<<" ";
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