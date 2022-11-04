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
#include <cstdio>
#include <vector>

using namespace std;

const int maxN= 15+3;
const int INF = 1000*1000*1000;

bool mark[maxN];
int n,e,res,add=INF;
int deg[maxN], match[maxN];
int dis[maxN][maxN];
vector <int> odd;

inline void backtrack (int v){
    if (v==(int)odd.size()){
        int sum=0;
        for (int i=0;i< (int)odd.size();i ++)
            sum+= dis[odd[i]][odd[match[i]]];
        add= min(add, sum/2);
        return;
    }
    if (mark[v]==true){
        backtrack (v+1);
        return;
    }

    for (int i=v+1;i< (int)odd.size();i ++){
        if (!mark[i]){
            match[v]= i; match[i]= v;
            mark[v]= mark[i]= true;
            backtrack (v+1);
            mark[v]= mark[i]= false;
        }
    }
}
/***************************************/
int main(){
    scanf ("%d%d", &n, &e);

    for (int i=1;i<=n;i ++)
        for (int j=1;j<=n;j ++)
            dis[i][j]= INF;
    for (int i=1;i<=n;i ++)
        dis[i][i]= 0;
    
    for (int i=1;i<=e;i ++){
        int x,y,w;
        scanf ("%d%d%d", &x, &y, &w);
        dis[x][y]= dis[y][x]= min (dis[x][y], w); 
        deg[x]++; deg[y]++;
        res+= w;
    }
    
    for (int k=1;k<=n;k ++)
        for (int i=1;i<=n;i ++)
            for (int j=1;j<=n;j ++)
                dis[i][j]= min (dis[i][j], dis[i][k] + dis[k][j]);

    for (int i=1;i<=n;i ++)
        if (deg[i]>0){
            if (dis[1][i]==INF){
                printf ("-1\n");
                return 0;
            }
            if (deg[i] & 1)
                odd.push_back (i);
        }

    backtrack (0);
    printf ("%d\n", res+add);

    return 0;
}