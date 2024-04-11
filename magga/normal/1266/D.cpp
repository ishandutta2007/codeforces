#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n,m,u,v,d;cin>>n>>m;
    long long int arr[n+1];
    for(int i=1;i<=n;i++) arr[i]=0;
    for(int i=0;i<m;i++){
        cin>>u>>v>>d;
        arr[u]-=d;
        arr[v]+=d;
    }
    stack<pair<long long int,int>>pos,nev;
    for(int i=1;i<=n;i++){
        if(arr[i]>0){
            pos.push({arr[i],i});
        }else if(arr[i]<0){
            nev.push({-1*arr[i],i});
        }
    }
    vector<pair<pair<int,int>,long long int>>ans;
    while(pos.size()){
        auto i = pos.top();
        auto j = nev.top();
        pos.pop();nev.pop();
        if(i.first>j.first){
            ans.push_back({{j.second,i.second},j.first});
            pos.push({i.first-j.first,i.second});
        }else if(i.first<j.first){
            ans.push_back({{j.second,i.second},i.first});
            nev.push({j.first-i.first,j.second});
        }else{
            ans.push_back({{j.second,i.second},j.first});
        }
    }
    cout<<ans.size()<<"\n";
    for(auto i:ans){
        cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}