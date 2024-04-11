#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MaxN  = 200005,
          MaxM  = 200005,
          True  = 1,
          False = 0,
          FileNotFound = 2,
          Bad   = -1337;

vector<int> clauses[MaxN];
vector<pair<int,bool>> occurs[MaxM];
int result[MaxM];
bool isOkayClause[MaxN];
int N, M;

void input(){
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; i++){
        int t;
        scanf("%d", &t);
        for(int j = 0; j < t; j++){
            int v;
            scanf("%d", &v);
            clauses[i].push_back(v);
        }
    }
}

void make_occurs(){
    fill(result, result+M+1, FileNotFound);
    fill(isOkayClause, isOkayClause+N+1, false);
    for(int clause = 0; clause < N; clause++){
        sort(clauses[clause].begin(), clauses[clause].end());
        for(int v : clauses[clause]){
            occurs[abs(v)].emplace_back(clause, (v>=0));
        }
    }

    for(int var = 1; var <= M; var++){
        vector<bool> appeared(2, false);
        for(auto P : occurs[var]){
//            printf("var %d appeared %d\n", var, P.second);
            appeared[P.second] = true;
        }

        if(!appeared[0] || !appeared[1]){
            bool which = false;
            if(!appeared[0]) which = true;
//            printf("res is %d (%d)\n", which, var);
            result[var] = which;
            for(auto P : occurs[var]){
                isOkayClause[P.first] = true;
            }
        }
    }
}

vector<int> adj[MaxN];
vector<int> treeAdj[MaxN];
multimap<pair<int,int>,int> edges;

int numVerts, numEdges, curConn;
int vis[MaxN];
int previous[MaxN];
int edgeU, edgeV;

void make_clauses_graph(){
    for(int cl = 0; cl < N; cl++){
        if(isOkayClause[cl]){
            adj[cl].push_back(cl);
//            printf("%d-%d\n", cl,cl);
//            edges.insert(make_pair(make_pair(cl,cl),
        }
    }

    for(int var = 1; var <= M; var++){
        if(result[var] != FileNotFound) continue;
        int u = occurs[var][0].first, //abs(clauses[var][0]),
            v = occurs[var][1].first; //abs(clauses[var][1]);
        adj[u].push_back(v);
        adj[v].push_back(u);
        if(u > v) swap(u,v);
        edges.insert(make_pair(make_pair(u,v), var));
//        printf("%d-%d (%d)\n", u, v, var);
    }
}


void dfs(int v, int pnt){
//    printf("dfs(%d,%d)\n", v, pnt);
    vis[v] = curConn;
    for(int s : adj[v]){
        if(s == pnt) continue;
        if(vis[s] == curConn){
            edgeU = v;
            edgeV = s;
            previous[v] = s;
//            printf("previous[%d]=%d\n", v,s);
        }
        if(vis[s]) continue;
        treeAdj[v].push_back(s);
        treeAdj[s].push_back(v);
        dfs(s, v);
    }
}

void dfs_prev(int v){
//    printf("dfs_prev(%d)\n", v);
    vis[v] = curConn;
    for(int s : treeAdj[v]){
        if(vis[s] == curConn) continue;
//        printf("previous[%d]=%d\n", s, v);
        previous[s] = v;
//        printf("->%d\n", s);
        dfs_prev(s);
    }
}

void recover_data(){
    for(int cl = 0; cl < N; cl++){
        int prv = previous[cl];
//        printf("cl=%d prv=%d\n", cl, prv);
        // spelniamy cl przy pomocy cl-prv
        if(cl == prv) continue;
        int a = min(cl, prv),
            b = max(cl, prv);
        auto it = edges.find(make_pair(a,b));
        assert(it != edges.end());
        int t = it->second;
//        printf("t=%d\n", t);
        edges.erase(it);

        bool res;
        if(occurs[t][0].first == cl){
            res = occurs[t][0].second;
        } else {
            res = occurs[t][1].second;
        }

/*        bool rev = (occurs[t][0].first != a);
        if(!occurs[t][0].second) rev = !rev;
        if(a != cl) rev = !rev;*/

        result[t] = res;
    }

    for(int var = 1; var <= M; var++){
        if(result[var] == FileNotFound){
            result[var] = 0;
        }
    }
}



int main(){
    input();
    make_occurs();
    make_clauses_graph();

    curConn = 0;
    for(int cl = 0; cl < N; cl++){
        if(vis[cl]) continue;
        numVerts = numEdges = 0;
        edgeU = edgeV = -1;
        curConn++;
        dfs(cl, -1);
//        printf("(%d,%d)\n", edgeU, edgeV);
        if(edgeU == -1){
            printf("NO\n");
            return 0;
        }

        curConn++;
        dfs_prev(edgeU);
    }

    recover_data();
    printf("YES\n");
    for(int i = 1; i <= M; i++){
        assert(result[i] == True || result[i] == False);
        printf("%d", result[i]);
    }
    printf("\n");
}