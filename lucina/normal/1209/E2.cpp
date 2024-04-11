#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
int n ,m;
vector<int> col[2005];
int mx[2005];
int go[(1 << 12)];
int t[(1 << 12)];
int best[(1 << 12)], keep[(1 << 12)];
void calcula(int column){
    for(int i = 0 ; i< (1 << n ) ; i++){
        best[i] = 0;
    }
    vector<int> d = col[column];
    for(int i = 0 ;i < n; i++){
        keep[0] = 0;
        for(int mask = 1 ;mask < (1 << n) ; mask++){
            int k = __builtin_ctz(mask);
            keep[mask] = keep[mask ^ (1 << k)] + d[k];
            best[mask] = max(best[mask], keep[mask]);
        }
        d.push_back(d[0]);
        d.erase(d.begin());
    }
    return ;
}
void solve(){
    int x;
    scanf("%d %d", &n, &m);
    int fm = m ;
    for(int i = 0 ;i < n;i ++){
        for(int j = 0 ; j< m ;j++){
            scanf("%d", &x);
            col[j].push_back(x);
            mx[j] = max(mx[j], x);
        }
    }
    vector<int> now;
    for(int i = 0 ;i < m ; i++) now.emplace_back(i);
    sort(now.begin(), now.end(), [](int u,int v) {
            return mx[u] > mx[v];
         });
    m = min(m , n);
    for(int i = 0 ; i< (1 << n) ; i++)
        go[i] = 0;
    for(int i = 0 ; i < m ; i ++ ){
        calcula(now[i]);
        for(int mask = 0 ; mask < (1 << n) ; ++ mask){
            t[mask] = go[mask];
            for(int submask = mask ;submask > 0 ; submask = (submask - 1) & mask){
                t[mask] = max(t[mask], best[submask] + go[mask ^ submask]);
            }
        }
        for(int mask = 0 ; mask < (1 << n) ; ++ mask){
            go[mask] = t[mask];
        }
    }
    printf("%d\n", go[(1 << n) - 1 ]);
    for(int j = 0 ;j < fm ; j++)
        col[j].clear(), mx[j] = 0;
}


int main(){
    int T;
    for(scanf("%d ", &T); T -- ; ){
        solve();
    }
}
/*
    Good Luck
        -Lucina
*/