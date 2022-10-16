#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

template<typename TH>
void debug_vars(const char* data, TH head){
    cerr << data << "=" << head << "\n";
}

template<typename TH, typename... TA>
void debug_vars(const char* data, TH head, TA... tail){
    while(*data != ',') cerr << *data++;
    cerr << "=" << head << ",";
    debug_vars(data+1, tail...);
}

#ifdef LOCAL
#define debug(...) debug_vars(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) {}
#endif

/////////////////////////////////////////////////////////


const int MaxN = 100005;

int N;
vector<int> adj[MaxN];
int visited[MaxN];
int curCol;
int cut, current;
int cnt[MaxN];

void input(){
    scanf("%d", &N);
    for(int i = 0; i < N-1; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

bool dfs_is_path(int v){
    visited[v] = curCol;
    int sz = adj[v].size();
    if(v == cut) sz--;
    if(sz >= 3) return false;
    for(int s : adj[v]){
        if(s == current) continue;
        if(visited[s] == curCol) continue;
        if(!dfs_is_path(s)) return false;
    }
    return true;
}

int main(){
    input();
    curCol = 0;
    for(int v = 1; v <= N; v++){
        if(adj[v].size() <= 2) continue;
        cnt[v] = 0;
        current = v;
        for(int s : adj[v]){
            curCol++;
            cut = s;
            visited[v] = curCol;
            if(!dfs_is_path(s)) cnt[v]++;
        }
        if(cnt[v] >= 3){
            debug(v);
            printf("No\n"); return 0;
        }
    }
    printf("Yes\n");
    return 0;
}