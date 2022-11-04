/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxN = 1000 + 5;
const ll INF = (1ll<<60);

int n,e,x,y;
int f[maxN] , pool[maxN] , POW[maxN] ,cost[maxN][maxN];
int dis[maxN][maxN];
ll dp[maxN];
vector <int> adj[maxN];

struct node{
    
    int v;

    node (int v=-1) : v(v) {}

    inline bool operator < (const node &sec) const{
        
        return (f[v]!=f[sec.v]) ? f[v] < f[sec.v] : v<sec.v;
    }
};

inline void dij (int root){
    
    for (int i=1; i<=n; i++)
        f[i]= POW[root]+1;

    f[root] = 0;

    set <node> sit;
    sit.insert (node(root));

    while (sit.size()){
        
        node TOP = *sit.begin(); sit.erase (TOP);

        int now = TOP.v;
    
        if (f[root] > POW[root])
            break;

        for (int i=0;i<(int)adj[now].size();i++){
            
            int tmp = adj[now][i];
            int DIS = f[now] + cost[now][tmp];

            if (DIS < f[tmp]){
                
                sit.erase (node(tmp));

                f[tmp] = DIS;

                sit.insert (node(tmp));
            }
        }
    }

    for (int i=1; i<=n; i++)
        dis[root][i] = f[i];
}
/*********************************/
struct Node{
    
    int v;
    
    Node (int v=-1) : v(v) {}

    inline bool operator < (const Node &sec) const{
        return (dp[v]!=dp[sec.v]) ? dp[v] < dp[sec.v] : v<sec.v;
    }
};

inline void solve (int x){
    
    for (int i=1; i<=n; i++)
        dp[i] = INF;

    dp[x] = 0;

    set <Node> sit; sit.insert (Node(x)); 

    while (sit.size()){
        
        Node TOP = *sit.begin(); sit.erase (TOP);

        int now= TOP.v;

        if (dp[now]==INF) break;

        for (int i=0;i<(int)adj[now].size(); i++){

            int tmp = adj[now][i];

            ll DIS = dp[now] + cost[now][tmp];

            if (DIS < dp[tmp]){
                
                sit.erase (Node(tmp));

                dp[tmp] = DIS;

                sit.insert (Node(tmp));
            }
        }
    }
}
/*********************************/
int main(){

    cin >> n >> e >> x >> y;

    for (int i=1; i<=n;i++)
    for (int j=1; j<=n;j++) cost[i][j] = cost[j][i] = 1000*1000*1000*2;
    
    for (int i=1; i<=e; i++){
        int e1,e2,w;
        cin >> e1 >> e2 >> w;
        adj[e1].push_back (e2);
        adj[e2].push_back (e1);
        cost[e1][e2] = cost[e2][e1] = min (cost[e1][e2] ,w);
    }

    for (int i=1; i<=n; i++)
        cin >> POW[i] >> pool[i];

    for (int i=1; i<=n; i++)
        dij (i);

    for (int i=1; i<=n; i++)
        adj[i].clear();

    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++) if (dis[i][j] <= POW[i]){                          
            cost[i][j] = pool[i];
            adj[i].push_back (j);
        }

    solve (x);

    if (dp[y]!=INF)
        cout << dp[y] << endl;
    else
        cout << -1 << endl;

    return 0;
}