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
 *
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

const int maxN= 200+5;

bool mark[maxN];
int n, maxDiam;
int far[maxN], par[maxN];
vector <int> adj[maxN];

inline void bfs (int root){
    queue <int> q;
    memset(par,0,sizeof par);
    
    q.push (root);
    par[root]= -1;
    while (!q.empty()){
        int v=q.front();
        for (int i=0;i< (int)adj[v].size();i ++){
            int tmp=adj[v][i];
            if (par[tmp]==0){
                par[tmp]= v;
                q.push (tmp);
            }
        }
        q.pop();
    }
}
/**********************************/
inline void dfs (int v){
    mark[v]= true;
    int max1=-1, max2=-1;
    for (int i=0;i< (int)adj[v].size();i ++){
        int tmp= adj[v][i];
        if (!mark[tmp]){
            dfs (tmp);
            if (max1 < far[tmp]){
                max2= max1;
                max1= far[tmp];
            }
            else if (max2 < far[tmp])
                max2= far[tmp];
        }
    }
    far[v]= max1+1;
    maxDiam= max (maxDiam, max1+max2+2);
}
/**********************************/
int main(){
    scanf ("%d", &n);
    for (int i=1;i< n;i ++){
        int x,y;
        scanf ("%d%d", &x,&y);
        adj[x].push_back (y);
        adj[y].push_back (x);
    }   
    int res=0;
    for (int i=1;i<=n;i ++){
        bfs (i);
        for (int j=i+1;j<=n;j++){
            int cur=j, l1=0;
            while (cur!=-1){
                l1 ++;
                mark[cur]= true;
                cur= par[cur];
            }
            l1 --;
            maxDiam= 0;
            for (int z=1;z<=n;z ++)
                if (!mark[z])
                    dfs (z);
            res= max (res, l1*maxDiam);
            memset (mark,false, sizeof mark);
        }
    }
    printf ("%d\n", res);

    return 0;
}