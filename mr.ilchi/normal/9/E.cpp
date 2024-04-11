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
 *
 *
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

#define Pair pair <int, int>

using namespace std;

const int maxN= 50+5;

bool mark[maxN];
bool adj [maxN][maxN];
int n, e, cnt, comp;
int par[maxN], d[maxN];
vector <Pair> res;

inline int dfs (int v){
    mark[v]=true; 
    cnt ++; 
    par[v]= comp;
    
    int ret= 0;
    for (int i=1;i<=n;i ++)
        if (adj[v][i] && !mark[i])
            ret+= dfs (i);
    return ret+d[v];
}
/**************************************/
inline void Union (int a1, int a2){
    for (int i=1;i<=n;i ++)
        if (par[i]== a2)
            par[i]= a1; 
}
/**************************************/
int main (){
    cin >> n >> e;
    for (int i= 1;i<= e;i ++){
        int x, y;
        cin >> x >> y;
        adj[x][y]= adj[y][x]= true;
        d[x] ++; d[y] ++;
    }
    for (int i=1;i<= n;i ++)
        if (d[i] > 2){
            puts("NO");
            return 0;
        }
    bool flag= false;
    for (int i=1;i<= n;i ++)
        if (!mark[i]){
            cnt= 0; comp ++;
            int cntEdge= dfs(i)/2;
            if (cntEdge== cnt)
                flag= true;
        }

    if (flag && comp > 1){
        puts ("NO");
        return 0;
    }
    if (flag && comp== 1){
        puts ("YES\n0");
        return 0;
    }
    if (n==1){
        puts ("YES\n1\n1 1");
        return 0;
    }
    puts ("YES");
    cout << comp << endl;
    for (int i=1;i<=n;i ++){
        for (int j=1;j<=n;j++)
            if (d[i]!=2 && d[j]!=2 && par[i]!=par[j]){
                d[i]++; d[j] ++;
                res.push_back (Pair (min(i,j), max(i,j)));
                Union (par[i],par[j]);
            }
    }
    for (int i=1, x1=-1;i<= n;i ++)
        if (d[i]== 1){
            if (x1==-1)
                x1= i;
            else
                res.push_back (Pair(x1,i));
        }
    
    sort (res.begin(), res.end());
    for (int i=0;i< (int)res.size();i ++)
        cout << res[i].first << ' ' << res[i].second << endl;

    return 0;
}