#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<" :";
#define INF 1000000000
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;
vector<int>arr[200001];
ll n,u,v,w;
int coun[2]{0};
bool present[200001];
void dfs(int to,int from,int d){
    present[to] = d&1;
    coun[present[to]]++;
    for(auto i:arr[to]){
        if(i!=from){
            dfs(i,to,d+1);
        }
    }
}
 
// Please write the recurances once :(
void pre(){}
void solve(){
    int n;cin>>n;
    coun[0]=0;
    coun[1]=0;
    for(int i=1;i<=n;i++) arr[i].clear();
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    dfs(1,0,0);
    bool to_be_marked = 0;
    if(coun[1] < coun[0]) to_be_marked = 1;
    bool until[n+1];
    for(auto &i:until) i = 1;
    vector<int>v,p;
    for(int i=0;i<20;i++){
        if(coun[to_be_marked]&(1<<i)){
            for(int j=(1<<i);j<(1<<(i+1));j++){
                until[j]=0;
                v.push_back(j);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(until[i]) p.push_back(i);
    }
    for(int i=1;i<=n;i++){
        if(present[i]==to_be_marked){
            cout<<v.back()<<" ";
            v.pop_back();
        }else{
            cout<<p.back()<<" ";
            p.pop_back();
        }
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