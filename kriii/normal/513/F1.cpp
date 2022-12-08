#include <vector>
#include <climits>
#include <algorithm>
#include <cstdio>
#include <memory.h>
#include <limits>
#include <queue>
using namespace std;

struct MaxFlowDinic
{
    typedef long long flow_t;

    struct Edge
    {
        int next;
        int inv; /* inverse edge index */
        flow_t res; /* residual */
    };

    int n;
    vector<vector<Edge>> graph;

    vector<unsigned> q, l, start;

    void Init(int _n){
        n = _n;
        graph.resize(n);
        for(int i = 0; i < n; i++) graph[i].clear();
    }
    void AddNodes(int count) {
        n += count;
        graph.resize(n);
    }
    void AddEdge(int s, int e, flow_t cap, flow_t caprev = 0) {
        Edge forward = { e, graph[e].size(), cap };
        Edge reverse = { s, graph[s].size(), caprev };
        graph[s].push_back(forward);
        graph[e].push_back(reverse);
    }

    bool AssignLevel(int source, int sink) {
        int t = 0;
        memset(&l[0], 0, sizeof(l[0]) * l.size());
        l[source] = 1;
        q[t++] = source;
        for(int h = 0; h < t && !l[sink]; h++) {
            int cur = q[h];
            for(unsigned i = 0; i < graph[cur].size(); i++) {
                int next = graph[cur][i].next;
                if (l[next]) continue;
                if (graph[cur][i].res > 0) {
                    l[next] = l[cur] + 1;
                    q[t++] = next;
                }
            }
        }
        return l[sink] != 0;
    }

    flow_t BlockFlow(int cur, int sink, flow_t currentFlow) {
        if (cur == sink) return currentFlow;
        for(unsigned &i = start[cur]; i < graph[cur].size(); i++) {
            int next = graph[cur][i].next;
            if (graph[cur][i].res == 0 || l[next] != l[cur]+1)
                continue;
            if (flow_t res = BlockFlow(next, sink, min(graph[cur][i].res, currentFlow))) {
                int inv = graph[cur][i].inv;
                graph[cur][i].res -= res;
                graph[next][inv].res += res;
                return res;
            }
        }
        return 0;
    }

    flow_t Solve(int source, int sink)
    {
        q.resize(n);
        l.resize(n);
        start.resize(n);
        flow_t ans = 0;
        while(AssignLevel(source,sink)) {
            memset(&start[0], 0, sizeof(start[0])*n);
            while(flow_t flow = BlockFlow(source,sink,numeric_limits<flow_t>::max())) {
                ans += flow;
            }
        }
        return ans;
    }
};

int N,M,a,b;
vector<int> boss[23][23],male[23][23],female[23][23];
char map[23][23]; bool chk[23][23];
int dist[23][23][23][23];

struct bug{
    bug(int x_, int y_, long long t_){
        x = x_; y = y_; t = t_;
    }
    int x,y; long long t;
};

int main()
{
    scanf ("%d %d %d %d",&N,&M,&a,&b);
    for (int i=0;i<N;i++) scanf ("%s",map[i]);

    int r,c,t;
    scanf ("%d %d %d",&r,&c,&t);
    boss[r-1][c-1].push_back(t);
    for (int i=0;i<a;i++){
        scanf ("%d %d %d",&r,&c,&t);
        male[r-1][c-1].push_back(t);
    }
    for (int i=0;i<b;i++){
        scanf ("%d %d %d",&r,&c,&t);
        female[r-1][c-1].push_back(t);
    }

    for (int i=0;i<N;i++) for (int j=0;j<M;j++) if (map[i][j] == '.'){
        for (int x=0;x<N;x++) for (int y=0;y<M;y++) dist[i][j][x][y] = -1;
        
        queue<pair<int, int> > Q;
        Q.push(make_pair(i,j)); dist[i][j][i][j] = 0;
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        while (!Q.empty()){
            int x = Q.front().first, y = Q.front().second; Q.pop();
            for (int k=0;k<4;k++){
                int px = x + dx[k];
                int py = y + dy[k];
                if (px < 0 || py < 0 || px >= N || py >= M) continue;
                if (dist[i][j][px][py] == -1 && map[px][py] == '.'){
                    Q.push(make_pair(px,py));
                    dist[i][j][px][py] = dist[i][j][x][y] + 1;
                }
            }
        }
    }
    
    long long ans = 0;
    for (int i=0;i<N;i++) for (int j=0;j<M;j++) if (!chk[i][j] && map[i][j] == '.'){
        vector<bug> p,q; bug r(-1,-1,-1);
        vector<pair<int, int> > pt;
        for (int x=0;x<N;x++) for (int y=0;y<M;y++) if (dist[i][j][x][y] != -1){
            pt.push_back(make_pair(x,y));
            if (!boss[x][y].empty()) r = bug(x,y,boss[x][y][0]);
            for (auto t : male[x][y]) p.push_back(bug(x,y,t));
            for (auto t : female[x][y]) q.push_back(bug(x,y,t));
        }

        if (r.x == -1){
            if (p.size() != q.size()){
                printf ("-1");
                return 0;
            }
        }
        else{
            if (abs((int)p.size() - (int)q.size()) != 1){
                printf ("-1");
                return 0;
            }
            if (p.size() < q.size()) p.push_back(r);
            else q.push_back(r);
        }
        if (p.size() == 0) continue;

        vector<long long> go;
        for (int i=0;i<p.size();i++) for (int j=0;j<pt.size();j++) go.push_back(dist[p[i].x][p[i].y][pt[j].first][pt[j].second] * p[i].t);
        for (int i=0;i<q.size();i++) for (int j=0;j<pt.size();j++) go.push_back(dist[q[i].x][q[i].y][pt[j].first][pt[j].second] * q[i].t);
        sort(go.begin(),go.end());
        go.erase(unique(go.begin(),go.end()),go.end());

        long long ll = 0, rr = go.size()-1, a = -1;

        while (ll <= rr){
            long long m = (ll + rr) / 2;
            MaxFlowDinic mf;
            mf.Init(1+p.size()+pt.size()*2+q.size()+1);
            for (int i=0;i<p.size();i++){
                mf.AddEdge(0,1+i,1);
            }
            for (int i=0;i<pt.size();i++){
                mf.AddEdge(1+p.size()+i,1+p.size()+pt.size()+i,1);
            }
            for (int i=0;i<q.size();i++){
                mf.AddEdge(1+p.size()+pt.size()*2+i,1+p.size()+pt.size()*2+q.size(),1);
            }
            for (int i=0;i<p.size();i++) for (int j=0;j<pt.size();j++) if (dist[p[i].x][p[i].y][pt[j].first][pt[j].second] * p[i].t <= go[m]){
                mf.AddEdge(1+i,1+p.size()+j,1);
            }
            for (int i=0;i<q.size();i++) for (int j=0;j<pt.size();j++) if (dist[q[i].x][q[i].y][pt[j].first][pt[j].second] * q[i].t <= go[m]){
                mf.AddEdge(1+p.size()+pt.size()+j,1+p.size()+pt.size()*2+i,1);
            }

            if (mf.Solve(0,1+p.size()+pt.size()*2+q.size()) == p.size()){
                a = go[m];
                rr = m - 1;
            }
            else ll = m + 1;
        }
        if (a == -1){
            printf ("-1");
            return 0;
        }
        if (ans < a)
            ans = a;
    }
    printf ("%lld\n",ans);

    return 0;
}