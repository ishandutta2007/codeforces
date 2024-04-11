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
// Please write the recurances once :(
void pre(){}
map<int,multiset<int>>g;
set<int>visited;
map<pair<int,int>,int>eulerpath;
void euler(int i,int m){
    visited.insert(i);
    while(g[i].size()>0){
        auto j = *g[i].begin();
        g[i].erase(g[i].find(j));
        g[j].erase(g[j].find(i));
        euler(j,m);
        //cout<<i<<" ";
        eulerpath[{i,j}]++;
    }
}
void solve(){
    int m,d;cin>>m;
    map<int,int>count;
    vector<int>arr[m];
    for(int i=0;i<m;i++){
        cin>>d;
        arr[i].resize(d);
        for(int j=0;j<d;j++){
            cin>>arr[i][j];
            g[m + arr[i][j]].insert(i);
            g[i].insert(m + arr[i][j]);
            count[arr[i][j]]++;
        }
    }
    for(auto i:count){
        if(i.S%2==1){
            cout<<"NO"<<"\n";
            return;
        }
    }
    cout<<"YES"<<"\n";
    for(int i=0;i<m;i++){
        if(visited.find(i)==visited.end()) euler(i,m);
    }
    for(int i=0;i<m;i++){
        for(auto j:arr[i]){
            if(eulerpath[{i,j+m}]>0){
                eulerpath[{i,j+m}]--;
                cout<<'L';
            }else{
               cout<<'R'; 
            }
        }
        cout<<"\n";
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
/*
    Final L and R are easily computable
    Constructive
    Each arry can be reduced to array of Unique elements
    Find a Euler tour in Bipartite graph of arrays and their elements
    1 2                             
    1 2 3 3 
    1 1 2 2 3 3 
*/