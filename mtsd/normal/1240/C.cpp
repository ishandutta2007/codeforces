#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

int n,k;
void dfs(int id,int pre,ll w,vector<vector<pair<int,ll> > > &g,vector<ll>&dp,vector<ll>&dp2){
    ll tmp = 0;
    priority_queue<ll>pq;
    for(auto x:g[id]){
        if(x.first==pre)continue;
        dfs(x.first,id,x.second,g,dp,dp2);
        tmp += dp[x.first];
        if(dp2[x.first]>dp[x.first]){
            pq.push(dp2[x.first]-dp[x.first]);
        }
    }
    int cnt = 0;
    ll nxt = 0;
    ll nxt2 = 0;
    while(!pq.empty()){
        if(cnt==k-1){
            nxt = tmp;
            nxt2 = tmp+w;
        }
        if(cnt==k){
            nxt = tmp;
            break;
        }
        cnt++;
        ll a = pq.top();
        pq.pop();
        tmp += a;
        if(cnt==k-1){
            nxt = tmp;
            nxt2 = tmp+w;
        }
        if(cnt==k){
            nxt = tmp;
            break;
        }
    }
    if(cnt<k){
        nxt = tmp;
        nxt2 = tmp + w;
    }
    dp[id] = nxt;
    dp2[id] = nxt2;
    return ;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int q;
    cin >> q;
    rep(zz,q){
        cin >> n >> k;
        vector<vector<pair<int,ll> > > g(n);
        rep(i,n-1){
            int a,b;
            ll w;
            cin >> a >> b >> w;
            a--;b--;
            g[b].push_back(MP(a,w));
            g[a].push_back(MP(b,w));
        }
        vector<ll>dp(n);
        vector<ll>dp2(n);
        dfs(0,-1,0LL,g,dp,dp2);
        // rep(i,n){
        //     cerr << dp[i] << " " << dp2[i] << endl;
        // }
        cout << max(dp[0],dp2[0]) << "\n";
    }
    return 0;
}