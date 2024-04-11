#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<": ";
#define INF 1000000000
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<pair<int,int>>arr[100001];
int n,k,t;
void solve(){
    for(int i=0;i<=100000;i++)
        if(arr[i].size()>0){
            arr[i].clear();
            arr[i].shrink_to_fit();
        }

    bool flag = true;
    cin>>n>>k;
    int minVal = 1000000;
    for(int i=0;i<n;i++){
        cin>>t;
        minVal = min(minVal,t);
        if(arr[t].size()==0)
            arr[t].push_back({t,1});
    }
    int ans = 100000000;
    for(int i=100000;i>=0;i--){
        ans = min(ans,i-minVal);
        if(i>0){
            while(arr[i].size()>0){
                t = i;
                if(t>0)
                    t = (arr[i].back().F + t)/t;
                else 
                    t = arr[i].back().F + 1;
                if(t>k){
                    flag = false;
                    break;
                }else{
                    minVal = min(minVal,arr[i].back().F/t);
                    arr[arr[i].back().F/t].push_back({arr[i].back().F,t});
                    arr[i].pop_back();
                }
            }
            arr[i].shrink_to_fit();
        }
        if(!flag) break;
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}