#include<bits/stdc++.h>
using namespace std;
set<int>arr[200001];
long long int flow[200001]{0};
long long int val[200001]{0};
long long int ans[200001]{0};
map<pair<int,int>,int>m1,m2;
int n,m,u,v,d;
void pre(){}
void solve(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v>>d;
        arr[u].insert(v);
        arr[v].insert(u);
        flow[u]+=d;flow[v]+=d;
        m1[{u,v}]=i;
        m2[{u,v}]=d;m2[{v,u}]=d;
    }
    stack<int>wait;
    wait.push(1);
    while(wait.size()>0){
        //cout<<wait.top()<<"\n";
        auto p = wait.top();
        wait.pop();
        for(auto i:arr[p]){
            arr[i].erase(p);
            val[i]+=m2[{i,p}];
            flow[i]-=m2[{i,p}];
            if(flow[i]==val[i] && i!=n){
                wait.push(i);
            }
            if(m1.find({i,p})!=m1.end()){
                ans[m1[{i,p}]]=1;
            }
        }
    }
    for(int i=0;i<m;i++){
        cout<<ans[i]<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}