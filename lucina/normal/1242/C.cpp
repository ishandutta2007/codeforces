#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
const int maxn = 3e5 + 10;
map<ll, int> ss;
ll sum[17], tot;
vector<pair<ll,int>> c[(1 << 15) + 5];
int k;
void go(ll x){
    ll st = x;
    int mask = 0;
    vector<pair<ll,int>> cyc;
    while(true){
        if(!ss.count(x)) return;
        int now = ss[x];
        /// -> we are removing x (sum[now] - x) ->
        cyc.push_back(make_pair(x,now));
        ll cur = tot - sum[now] + x;
        if(mask & (1 << now)) return;
        mask ^= (1 << now);
        if(cur == st){
            c[mask] = cyc;
            return ;
        }
        x = cur;
    }
}
int dp[(1 << 15) + 5];
pair<ll, int > ans[20];
void restore(vector<pair<ll, int>> x){
    x.push_back(x[0]);
    for(int i = 1 ;i <  (int)x.size() ; ++ i){
        int id = x[i].second;
        ans[id].first = x[i].first;
        ans[id].second = x[i - 1].second + 1;
    }
}

int main(){
    scanf("%d", &k);
    ll x; int n;
    for(int i = 0 ;i < k ;i ++){
        for(scanf("%d", &n); n -- ;){
            scanf("%lld", &x);
            ss[x] = i;
            sum[i] += x;
        }
        tot += sum[i];
    }
    if(abs(tot) % k)return !printf("No\n");
    tot /= k ;
    for(auto it: ss){
        go(it.first);
    }
    //printf("-----------\n");
    memset(dp, -1 , sizeof(dp));
    dp[0] = 0;
    int const mask = (1 << k) - 1;
    for(int msk = 0 ; msk <= mask ; ++ msk){
        if(dp[msk] == -1) continue;
        int cmp = mask ^ msk;
        for(int sub = cmp ; sub > 0 ; sub = (sub - 1) & cmp){
            if(c[sub].empty()) continue;
            dp[sub ^ msk] = msk;
        }
    }
    if(dp[mask] == -1)return !printf("No\n");
    printf("Yes\n");
    int cur = mask;
    while(cur > 0){
        restore(c[cur ^ dp[cur]]);
        cur = dp[cur];
    }
    for(int i = 0 ; i < k ; i++){
        printf("%lld %d\n", ans[i].first, ans[i].second);
    }
}
/*
    Round 559
    Good Luck
        -Lucina
*/