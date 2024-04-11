#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n,m,k,u,v;cin>>n>>m>>k;
    long long int arr[n+1][3];
    vector<long long int>g[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
        g[i].push_back(i);
    }
    for(int i=0;i<m;i++){
        cin>>u>>v;
        g[u].push_back(v);
    }
    long long int cum[n+1];
    cum[0]=k;
    for(int i=1;i<=n;i++){
        cum[i]=cum[i-1]+arr[i][1];
    }
    long long int coo[n+1];
    for(int i=0;i<n;i++){
        coo[i]=cum[i]-arr[i+1][0];
        if(coo[i]<0){
            cout<<-1<<"\n";
            return;
        }
    }
    coo[n]=cum[n];
    for(int i=n-1;i>=0;i--) coo[i]=min(coo[i],coo[i+1]);
    for(int i=n;i>=0;i--) cum[i]=coo[i];
    for(int i=1;i<=n;i++) coo[i]=cum[i]-cum[i-1];
    coo[1]+=coo[0];
    priority_queue<long long int>pq;
    bool flag[n+1];
    long long int ans = 0;
    for(int i=0;i<=n;i++) flag[i]=1;
    for(int i=n;i>=1;i--){
        for(auto j:g[i]){
            if(flag[j]){
                flag[j]=0;
                pq.push(arr[j][2]);
            }
        }
        int u = 0;
        while(pq.size()>0 && u<coo[i]){
            u++;
            ans+=pq.top();
            pq.pop();
        }
    }
    cout<<ans<<"\n";
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