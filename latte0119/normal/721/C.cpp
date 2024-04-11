#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <functional>

using namespace std;

#define int long long

#define fst first
#define scd second
#define PB push_back
#define MP make_pair
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define omajinai ios::sync_with_stdio(false);cin.tie(0)
#define rep(i,x) for(int i=0;i<(int)(x);++i)
#define rep1(i,x) for(int i=1;i<=(int)(x);++i)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

template<typename T>T& max(T&a,T&b){if(a>=b)return a;return b;}
template<typename T>T& min(T&a,T&b){if(a<b)return a;return b;}
template<typename T>bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}
template<typename T>T get(){T a;cin>>a;return a;}
template<typename T>T rev(T a){reverse(all(a));return a;}
template<typename T>vector<T>&sort(vector<T>&a){sort(all(a));return a;}

const int inf = 3e18;
const double eps = 1e-9;

struct edge { int to, cost; edge(int to, int cost) : to(to), cost(cost) {} };
typedef vector<edge> edges;

struct Cost {
    int cost;
    int v;
    int num;

    bool operator <(Cost c) const {
        if (num == c.num) return cost > c.cost;
        return num > c.num;
    }

    Cost(int cost, int v, int num) : cost(cost), v(v), num(num) {
    }
};

int N, M, T;

edges G[5010];
edges rG[5010];
int d[5010][5010];

void dijkstra(int s)
{
    rep(i, N) rep(j, N) d[i][j] = inf;

    priority_queue<Cost> q;

    d[0][s] = 0;

    q.push(Cost(0, s, 0));

    while (q.size()) {
        Cost p = q.top(); q.pop();

        int v = p.v;

        if (d[p.num][v] < p.cost) continue;

        int num = p.num;
        int nxt_num = p.num + 1;

        rep(i, G[v].size()) {
            edge e = G[v][i];

            if (d[nxt_num][e.to] > d[num][v] + e.cost) {
                d[nxt_num][e.to] = d[num][v] + e.cost;
                q.push(Cost(d[nxt_num][e.to], e.to, nxt_num));
            }
        }
    }
}

signed main()
{ // #define int long long scanf
    cin >> N >> M >> T;

    rep(i, M) {
        int u, v, t;
        cin >> u >> v >> t;
        -- u, -- v;
        G[u].PB(edge(v, t));
        rG[v].PB(edge(u,t));
    }

    dijkstra(0);

    vi route;
    route.PB(N - 1);

    int now = N - 1;
    for (int i = N - 1; i >= 0; --i) {
        if (d[i][now] <= T) {
            for(int j=i;j>0;j--){
                for(int k=0;k<rG[now].size();k++){
                    edge &e=rG[now][k];
                     if(d[j-1][e.to]+e.cost!=d[j][now])continue;
                    route.PB(e.to);
                    now=e.to;
                    break;
                }
            }
            break;
        }
    }

    reverse(all(route));
    cout << route.size() << endl;
    rep(i, route.size()) {
        if (i) cout << ' ';
        cout << route[i] + 1;
    }
    cout << endl;
}