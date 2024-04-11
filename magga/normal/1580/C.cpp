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
pii arr[200001];
ll ans[200001]{0};
ll train[200001];
ll sum[200001];
ll parity[200001];
vector<int> occur[200001];
int pointer[200001]{0};
void solve(){
    ll n,m;cin>>n>>m;
    ll op,k;
    for(int i=1;i<=n;i++){
        cin>>arr[i].F>>arr[i].S;
        sum[i] = arr[i].F + arr[i].S;
    }
    for(int i=0;i<m;i++){
        cin>>op>>k;
        if(op==1){
            train[i]=k;
        }else{
            train[i]=0-k;
        }
        occur[k].push_back(i);
    }
    // xi + yi > sqrt(n)
    int bound = sqrt(n);
    for(int i=0;i<m;i++){
        if(train[i]<0 || sum[train[i]]<=bound)
            continue;
        ll end;
        if(pointer[train[i]]==occur[train[i]].size()-1){
            end = m;
        }else{
            end = occur[train[i]][pointer[train[i]]+1];
        }
        int j=i;
        for(;end-j>=sum[train[i]];j+=sum[train[i]]){ 
            ans[j+arr[train[i]].F]++;
            ans[j+sum[train[i]]]--;
        }
        ans[min(j+arr[train[i]].F,end)]++;
        ans[end]--;
        pointer[train[i]]+=2;
    }
    for(int i=1;i<m;i++) ans[i]+=ans[i-1];

    // for sum[i]<=bound
    for(int j=2;j<=bound;j++){
        vector<int>curr(j);
        int val = 0;
        for(int i=0;i<m;i++){
            if(train[i]>0 && sum[train[i]]==j){
                parity[train[i]]=i;
                for(int k=parity[train[i]]+arr[train[i]].F;k<parity[train[i]]+sum[train[i]];k++){
                    curr[k%j]++;
                }
            }   
            if(train[i]<0 && sum[0-train[i]]==j){
                train[i] = 0-train[i]; 
                for(int k=parity[train[i]]+arr[train[i]].F;k<parity[train[i]]+sum[train[i]];k++){
                    curr[k%j]--;
                }
            } 

            ans[i]+=curr[val];
            val++;
            if(val==j) val = 0;
        }
    }
    for(int i=0;i<m;i++) cout<<ans[i]<<" ";
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}