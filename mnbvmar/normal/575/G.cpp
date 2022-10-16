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

vector<pair<int,int>> adj[MaxN];
int N, M;
int Start, End;


void input(){
    scanf("%d%d", &N, &M);
    Start = 0;
    End = N-1;
    for(int i = 0; i < M; i++){
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }
}

vector<int> vertOrder;

struct Distance {
    int lastNz, lastEdge, lastV, numEl;

    Distance(){}
    Distance(int _lastNz, int _lastEdge, int _lastV, int _numEl) 
        : lastNz(_lastNz), lastEdge(_lastEdge), lastV(_lastV), numEl(_numEl) {}

    bool operator<(const Distance& other) const {
        return make_tuple(lastNz, lastEdge, vertOrder[lastV], numEl) <
            make_tuple(other.lastNz, other.lastEdge,
                       vertOrder[other.lastV], other.numEl);
    }
};

vector<Distance> dists;
vector<int> prevVert;
vector<int> prevCost;
vector<bool> dfsVis;

void dfsZero(int v){
    dfsVis[v] = true;
    for(auto P : adj[v]){
        if(P.second != 0) continue;
        if(!dfsVis[P.first]) dfsZero(P.first);
    }
}

void dijkstra(){
    priority_queue<pair<Distance,int>, vector<pair<Distance,int>>,
        greater<pair<Distance,int>>> Q;

    int numAdded = 1;
    Distance first(0, 0, N, 0);
    dists[Start] = first;
    Q.push(make_pair(first, Start));
    vector<bool> visited(N+1, false);

    while(!Q.empty()){
        auto P = Q.top(); Q.pop();
        int v = P.second;
        if(visited[v]) continue; else visited[v] = true;
        int lastNz, lastEdge, lastV, numEl;
        lastNz = P.first.lastNz;
        lastEdge = P.first.lastEdge;
        lastV = P.first.lastV;
        numEl = P.first.numEl;
        vertOrder[v] = (numAdded++);

        for(auto DD : adj[v]){
            int s, cost;
            tie(s, cost) = DD;
            Distance newDist;
            
            if(cost == 0 && dfsVis[s]){
                newDist = Distance(lastNz,lastEdge,lastV,numEl+1);
            } else {
                newDist = Distance(numEl+1, cost, v, numEl+1);
            }
            if(newDist < dists[s]){
                dists[s] = newDist;
                prevVert[s] = v;
                prevCost[s] = cost;
                Q.push(make_pair(newDist, s));
            }
        }
    }
}


int main(){
    input();
    vertOrder.resize(N+1, -1);
    dists.resize(N+1, Distance(1e9, 1e9, 0, 1e9));
    prevVert.resize(N+1, 1e9);
    prevCost.resize(N+1, -1);
    dfsVis.resize(N+1, false);
    dfsZero(End);
    dijkstra();

    vector<int> order;
    int last = End;
    string dist;
    order.push_back(last);
    do {
        if(!dist.empty() || prevCost[last] > 0)
            dist.push_back('0' + prevCost[last]);
        last = prevVert[last];
        order.push_back(last);
    } while(last != Start);

    if(dist == "") dist = "0";

    printf("%s\n%d\n", dist.c_str(), (int)order.size());
    reverse(order.begin(), order.end());
    for(int v : order) printf("%d ", v);
    printf("\n");
}