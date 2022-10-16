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
#define debug(...) (__VA_ARGS__)
#endif

/////////////////////////////////////////////////////////


const int MaxV = 155;

struct Edge {
    int from, to, start;
    Edge(){}
    Edge(int f, int t, int s) : from(f), to(t), start(s) {}

    bool operator<(const Edge& other) const {
        return make_tuple(start, from, to) < make_tuple(other.start,other.from,other.to);
    }
};

using Mask = bitset<MaxV>;

const int Infty = 2e9;

int N, M;
Edge edges[MaxV];
vector<int> adj[MaxV];
int dist[MaxV];


void input(){
    scanf("%d%d", &N, &M);
    for(int i = 0; i < M; i++){
        int a, b, d;
        scanf("%d%d%d", &a, &b, &d);
        edges[i] = Edge(a,b,d);
    }
}

vector<Mask> mul(const vector<Mask>& lhs, const vector<Mask>& rhs){
//    debug("mul", lhs[1], lhs[2], rhs[1], rhs[2]);
    vector<Mask> result(N+1);
    for(int a = 1; a <= N; a++){
        for(int b = 1; b <= N; b++){
            if(lhs[a][b]) result[a] |= rhs[b];
        }
    }
//    debug(result[1]);
    return result;
}

Mask proc_reach(Mask current, int numSteps){
//    debug(current, numSteps);
    vector<Mask> coef(N+1), result(N+1);
    for(int i = 1; i <= N; i++){
        result[i][i] = true;
        for(int j : adj[i]){
            debug(i, j);
            coef[i][j] = true;
        }
    }

    int pwr2 = 1;
    while(pwr2 <= numSteps){
        if(numSteps & pwr2) result = mul(result, coef);
        coef = mul(coef, coef);
        pwr2 <<= 1;
    }

    Mask reachable;
    for(int i = 1; i <= N; i++){
        if(current[i]) reachable |= result[i];
    }
//    debug(reachable);
    return reachable;
}

void bfs(Mask reached){
//    debug("bfs", reached);
    fill(dist, dist+N+1, Infty);
    queue<int> Q;
    for(int i = 1; i <= N; i++){
        if(reached[i]){ Q.push(i); dist[i] = 0; }
    }

    while(!Q.empty()){
        int v = Q.front(); Q.pop();
//        debug(v);
        for(int s : adj[v]){
//            debug(v, s);
            if(dist[s] > dist[v]+1){
                dist[s] = dist[v]+1;
                Q.push(s);
            }
        }
    }
}


int main(){
    input();
    sort(edges, edges+M);
    int curTime = 0;
    bitset<MaxV> curReach;
    curReach.set(1);
    int result = Infty;
    bool found = false;

    for(int i = 0; i < M; i++){
        int timeDiff = edges[i].start - curTime;
        curReach = proc_reach(curReach, timeDiff);
        curTime = edges[i].start;

        adj[edges[i].from].push_back(edges[i].to);
        bfs(curReach);
        if(dist[N] < Infty){
            result = min(result, curTime + dist[N]);
            found = true;
        }
    }

    if(!found){
        printf("Impossible\n");
    } else {
        printf("%d\n", result);
    }
}