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
set<ll>dp[4];
char ans[2000][2000];
void set_winning(int i,int j){
    dp[0].insert(i+j);
    dp[1].insert(-1*i + j);
    dp[2].insert(i - j);
    dp[3].insert(-1*i - j);
    ans[i][j] = 'M';
}
ll max_dist(int i,int j){
    ll ans = 0;
    ll curr = i+j;
    ans = max(ans,max(abs(curr-(*dp[0].begin())),abs(curr-(*dp[0].rbegin()))));
    curr = -1*i + j;
    ans = max(ans,max(abs(curr-(*dp[1].begin())),abs(curr-(*dp[1].rbegin()))));
    curr = i - j;
    ans = max(ans,max(abs(curr-(*dp[2].begin())),abs(curr-(*dp[2].rbegin()))));
    curr = -1*i - j;
    ans = max(ans,max(abs(curr-(*dp[3].begin())),abs(curr-(*dp[3].rbegin()))));
    return ans;
}
void solve(){
    ll n,k;cin>>n>>k;
    vector<pair<ll,pii>>numbers(n*n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>numbers[i*n+j].F;
            numbers[i*n+j].S = {i,j};
        }
    }
    sort(numbers.begin(),numbers.end());
    reverse(numbers.begin(),numbers.end());
    set_winning(numbers[0].S.F,numbers[0].S.S);
    for(int i=1;i<numbers.size();i++){
        if(max_dist(numbers[i].S.F,numbers[i].S.S)>k){
            ans[numbers[i].S.F][numbers[i].S.S] = 'G';
        }else{
            set_winning(numbers[i].S.F,numbers[i].S.S);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j];
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