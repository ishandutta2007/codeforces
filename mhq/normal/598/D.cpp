#include <bits/stdc++.h>
using namespace std;
int n,m,k;

int f[1001][1001];

int ans[1001][1001];

char x;
int u[1001][1001];
int dx[]={0,0,1,-1};
int dy[]={-1,1,0,0};
int num;
int sum[1000000+10];
int id [1002][1002];

int bfs(int x,int y) {
    queue< pair<int,int> > q;
    q.push(make_pair(x,y));
    u[x][y]=1;
    int cur=0;
    while( !q.empty() ){
        x=q.front().first;
        y=q.front().second;
        q.pop();
        id[x][y] = num;
        cur += ans[x][y];
        for(int k=0; k < 4; ++k ){
            int nx=x+dx[k];
            int ny=y+dy[k];
            if( nx < 1 || ny < 1|| nx > n||ny > m || u[nx][ny] || f[nx][ny] == 1) continue;
            q.push(make_pair(nx,ny));
            u[nx][ny] = 1;
        }
    }
    return cur;
}

int main() {
   //freopen("input.txt", "r", stdin);
   //freopen("output.txt","w",stdout);
   ios_base::sync_with_stdio(false);
   scanf("%d%d%d\n",&n,&m,&k);
   for ( int i = 1; i <= n; i++) {
        for ( int j = 1; j <= m; j++) {
            x = getchar();
            if ( x == '.' ) {
                f[i][j] = 0;
            }
            else f[i][j] = 1;
        }
        if ( i + 1 <= n) getchar();
   }
   for ( int i = 1; i <= n; i++) {
        for ( int j = 1; j <= m; j++) {
            if ( f[i][j] == 0) {
                ans[i][j] = f[i-1][j] + f[i+1][j] + f[i][j-1] + f[i][j+1];
            }
        }
   }

   for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
        if( u[i][j] ) continue;
        ++num;
        sum[num] = bfs(i,j);
     }
   }
   for ( int i = 0; i < k; i++) {
        int x,y;
        scanf("%d",&x);
        scanf("%d",&y);
        printf("%d\n", sum[id[x][y]]);
   }

   return 0;
}