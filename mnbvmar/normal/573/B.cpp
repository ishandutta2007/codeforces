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
int heights[MaxN];

void input(){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%d", &heights[i]);
    }
    heights[0] = heights[N+1] = 0;
}

int dist[MaxN];
bool vis[MaxN];

int main(){
    input();
    fill(dist, dist+N+2, MaxN);

    set<pair<int,int>> Q;
    for(int i = 2; i < N; i++){
        Q.insert(make_pair(heights[i], i));
    }

    Q.insert(make_pair(1, 1));
    Q.insert(make_pair(1, N));

    while(!Q.empty()){
        auto P = *Q.begin(); Q.erase(Q.begin());
        int t = P.first,
            v = P.second;
        if(v == 0 || v > N) continue;
        if(dist[v] <= N) continue;
        dist[v] = t;
        Q.insert(make_pair(t+1, v-1));
        Q.insert(make_pair(t+1, v+1));
    }


    printf("%d\n", *max_element(dist+1, dist+N+1));
}