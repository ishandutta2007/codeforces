#include<bits/stdc++.h>
using namespace std;
void pre(){}
int n,u,v;
vector<long long int>arr[200001];
map<int,int>dp[200001];
priority_queue<pair<int,int>>df[200001];
int ma = 0;
int root = 1;
int dfs(int to,int from){
    int ret = 0;
    for(int i:arr[to]){
        if(i!=from){
            dp[to][i]=dfs(i,to);
            ret=max(ret,dp[to][i]);
        }
    }
    return ret+1;
}
void dfs2(int to,int from){
    int ans = 0;
    int val = 0;
    priority_queue<int>pq;
    for(auto i:dp[to]){
        pq.push(i.second);
    }
    while(pq.size()>0){
        if(val==3){
            pq.pop();
            continue;
        }
        ans+=pq.top();
        pq.pop();
        val++;
    }
    for(auto i:dp[to]){
        pq.push(i.second);
    }
    if(ans>ma){
        root=to;
        ma=ans;
    }
    for(int i:arr[to]){
        if(i!=from){
            int oo = 0;
            if(dp[to][i]==pq.top()){
                pq.pop();
                if(pq.size()!=0){
                    oo=pq.top();
                }
                pq.push(dp[to][i]);
            }else{
                oo=pq.top();
            }
            dp[i][to]=oo+1;
            dfs2(i,to);
        }
    }
}
pair<int,int> dfs3(int to,int from){
    int bot = to;
    int ret = 0;
    for(int i:arr[to]){
        if(i!=from){
            auto u = dfs3(i,to);
            df[to].push(u);
            if(u.first>ret){
                ret=u.first;
                bot=u.second;
            }
            ret=max(ret,dp[to][i]);
        }
    }
    return {ret+1,bot};
}
void solve(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    dfs(1,0);
    dfs2(1,0);
    dfs3(root,0);
    set<int>v;
    int val=0;
    while(df[root].size()>0){
        if(val==3){
            df[root].pop();
            continue;
        }
        v.insert(df[root].top().second);
        df[root].pop();
        val++;
    }
    cout<<ma<<"\n";
    if(v.size()==3){
        for(auto i:v){
            cout<<i<<" ";
        }
        cout<<"\n";
    }else{
        v.insert(root);
        int p = v.size();
        for(auto i:v){
            cout<<i<<" ";
        }
        while(p<3){
            int u = rand()%n+1;
            if(v.find(u)==v.end()){
                cout<<u<<" ";
                v.insert(u);
                p++;
            }
        }
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