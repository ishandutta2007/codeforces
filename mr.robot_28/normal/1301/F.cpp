#include <bits/stdc++.h>
using namespace std;
#define oo 1000000000
#define mod 998244353
const int N = 1010 , K = 45; 
int n , m , k , r1 , r2 , c1 , c2 , grid[N][N] , ans = 0;
 
int cost[K][N][N];
bool done[K];
 
queue < pair<int,int> > q;
 
int dr[4] = {0 , 1 , 0 , -1};
int dc[4] = {1 , 0 ,-1 ,  0};
 
vector < pair<int,int> > cells[K];
 
void BFS(int col){
    for(int i = 0; i < (int)cells[col].size();i++){
        cost[col][cells[col][i].first][cells[col][i].second] = 0;
        q.push(make_pair(cells[col][i].first,cells[col][i].second));
    }
    for(int i = 1;i <= k;i++) done[i] = false;
    int r , c , nr , nc;
    while(!q.empty()){
        r = q.front().first;
        c = q.front().second;
        q.pop();
        if(!done[grid[r][c]]){
            done[grid[r][c]] = true;
            for(int i = 0 ; i < (int)cells[grid[r][c]].size() ;i++){
                nr = cells[grid[r][c]][i].first;
                nc = cells[grid[r][c]][i].second;
                if(cost[col][nr][nc] == -1){
                    cost[col][nr][nc] = cost[col][r][c] + 1;
                    q.push(make_pair(nr , nc));
                }
            }
        }
        for(int i = 0 ;i < 4;i++){
            nr = r + dr[i];
            nc = c + dc[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && cost[col][nr][nc] == -1){
                cost[col][nr][nc] = cost[col][r][c] + 1;
                q.push(make_pair(nr , nc));
            }
        }
    }
}
 
 
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 0 ;i < n;i++){
        for(int j = 0 ;j < m;j++){
            scanf("%d",&grid[i][j]);
            cells[grid[i][j]].push_back(make_pair(i , j));
        }
    }
    memset(cost,  -1, sizeof(cost));
    for(int i = 1;i <= k;i++)
        BFS(i);
    int q;
    scanf("%d",&q);
    while(q--){
        scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
        r1--,c1--,r2--,c2--;
        ans = abs(r1 - r2) + abs(c1 - c2);
        for(int i = 1;i <= k;i++)
            ans = min(ans , 1 + cost[i][r1][c1] + cost[i][r2][c2]);
        printf("%d\n",ans);
    }
    return 0;
}