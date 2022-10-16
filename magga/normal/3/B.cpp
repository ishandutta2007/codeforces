#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n,v,a,b;cin>>n>>v;
    long long int arr[n+1];
    priority_queue<pair<pair<long double,long long int>,long long int>>pq;
    for(long long int i=0;i<n;i++){
        cin>>a>>b;
        arr[i+1]=b;
        pq.push({{(b*1.0)/(a*(1.0)),a},i+1});
    }
    vector<long long int>v1[2];
    long long int ans = 0;
    long long int curr = 0;
    set<pair<long long int,long long int>>s;
    while(pq.size()>0){
        auto i = pq.top();
        pq.pop();
        if(i.first.second<=v-curr){
            ans+=i.first.second*i.first.first;
            curr+=i.first.second;
            v1[i.first.second-1].push_back(i.second);
        }else{
            s.insert({i.first.second*i.first.first,i.second});
        }
    }
    if(curr<v){
        if(v1[0].size()==0){
        }else{
            s.insert({arr[v1[0].back()],v1[0].back()});
            ans-=arr[v1[0].back()];
            v1[0].pop_back();
            auto i = *s.rbegin();
            ans+=i.first;
            v1[0].push_back(i.second);
        }
    }
    cout<<ans<<"\n";
    for(auto i:v1[0]){
        cout<<i<<" ";
    }
    for(auto i:v1[1]){
        cout<<i<<" ";
    }
    cout<<"\n";
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