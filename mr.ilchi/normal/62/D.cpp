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

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int maxN= 100+5;

bool mark[maxN];
bool flag[maxN][maxN];
int n,m;
int t[3000];
queue <int> Q;

inline int dfs (int v){
    mark[v]= true; int ret=0;
    for (int i=1;i<=n;i ++){
        if (!mark[i] && flag[v][i]){
            ret+= dfs (i);
        }
        ret+= flag[v][i];
    }
    return ret;
}
/********************************/
inline void tour (int v, int cnt){
    Q.push (v);
    for (int i=1;i<=n;i ++){
        if (flag[v][i]){
            flag[v][i]= flag[i][v]= false;
            memset (mark, false, sizeof mark);
            int d= dfs (i);
            if (2*cnt-2 == d){
                tour (i, cnt-1);
                return;
            }
            flag[v][i]= flag[i][v]= true;
        }
    }
}
/********************************/
int main(){
    scanf ("%d%d", &n, &m);
    for (int i=0;i<=m;i ++){
        scanf ("%d", &t[i+1]);
    }
    flag[t[m]][t[m+1]]= flag[t[m+1]][t[m]]= true;
    int pos= -1, next=-1;
    for (int i=(m-1);i>=1;i --){
        int v= t[i];
        flag[v][t[i+1]]= flag[t[i+1]][v]= true;
        for (int j=t[i+1]+1;j<=n;j ++){
            if (flag[v][j]){
                flag[v][j]= flag[j][v]= false;
                memset (mark, false, sizeof mark);
                dfs (j);
                bool no= false;
                for (int z=i+1;z<=m+1;z++)
                    if (!mark[t[z]]){
                        no= true; break;
                    }
                
                if (!no){
                    pos=i; next=j;
                    break;
                }
                flag[v][j]= flag[j][v]= true;
            }
        }
        if (next!=-1){
            break;
        }
    }
    if (next==-1){
        cout << "No solution" << endl;
        return 0;
    }
    tour(next, m-pos);
    while (!Q.empty()){
        t[++pos]= Q.front(); Q.pop();
    }
    for (int i=1;i<=m+1;i ++)
        cout << t[i] << ' ';
    cout << endl;

    return 0;
}