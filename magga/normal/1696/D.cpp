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
struct MinStack{
    int n;
    vector<vector<ll>>val;
    MinStack(int _n,vector<ll>arr){
        n = _n;
        val.assign(2,vector<ll>(n));
        stack<pair<int,int>>s;
        for(int i=0;i<n;i++){
            while(s.size()>0 && s.top().F>arr[i]){
                auto j = s.top();
                s.pop();
                val[0][j.second]=i;
            }
            s.push({arr[i],i});
        }
        while(s.size()>0){
            auto i = s.top();
            s.pop();
            val[0][i.S]=n;
        }
        for(int i=0;i<n;i++){
            while(s.size()>0 && s.top().F<arr[i]){
                auto j = s.top();
                s.pop();
                val[1][j.second]=i;
            }
            s.push({arr[i],i});
        }
        while(s.size()>0){
            auto i = s.top();
            s.pop();
            val[1][i.S]=n;
        }
    }
};
void pre(){}
void solve(){
    int n;cin>>n;
    vector<ll>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(n==1){
        cout<<0<<"\n";
        return;
    }
    MinStack ms(n,arr);
    // for(auto i:ms.val){
    //     for(auto j:i){
    //         cout<<j<<" ";
    //     }
    //     cout<<"\n";
    // }
    int i = 0;
    int ans = 0;
    while(i<n-1){
        ans++;
        if(arr[i]>arr[i+1]){
            int nextMax = ms.val[1][i];
            int curr = i;
            while(ms.val[0][curr]<n && ms.val[0][curr]<nextMax){
                curr = ms.val[0][curr];
            }
            i = curr;
        }else{
            int nextMin = ms.val[0][i];
            int curr = i;
            while(ms.val[1][curr]<n && ms.val[1][curr]<nextMin){
                curr = ms.val[1][curr];
            }
            i = curr;
        }
    }
    cout<<ans<<"\n";
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