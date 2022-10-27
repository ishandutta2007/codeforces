#include<bits/stdc++.h>
using namespace std;
int const inf = 5e8;
struct P{
    int mv, re;
    P(): mv(inf), re(inf) {}
    P(int x, int y): mv(x) , re(y) {}
    friend bool operator < (const P & x , const P & y){
        return x.mv == y.mv ? x.re < y.re : x.mv < y.mv;
    }
    P operator + (const P & x){
        return P(mv + x.mv, re + x.re);
    }
};
int const nax = 334;

int dx[] = {-2, -1, 1, 2,  2,  1, -1, -2};
int dy[] = { 1,  2, 2, 1, -1, -2, -2, -1};
///knight moves

int n;
int trans(int x, int y, int z){
    return x * n  * 3 + y * 3 + z;
    //no collision
}
P dist[nax][nax]; /// minimum number of moves from state a to b
P dp[nax][3];
pair<int, int> pos[128];

int main(){
    scanf("%d", &n);
    for(int i = 1 ;i  <= n ; i ++){
        for(int j = 1 ;j <= n ;j ++){
            int x;
            scanf("%d", &x);
            pos[x] = {i, j};
        }
    }
    for(int i = 0; i < nax ; i ++){
        dist[i][i] = P(0, 0);
    }
    auto inside = [&](int i, int j){
        return i <= n && i >= 1 && j <= n && j >= 1;
    };
    for(int i = 1 ;i <= n ; i ++){
        for(int j = 1; j <= n ;j ++){
            // knight's move
            for(int x = 0 ; x < 8 ; x ++){
                int nx = i + dx[x];
                int ny = j + dy[x];
                if(inside(nx, ny))
                 dist[trans(i, j , 0)][trans(nx, ny, 0)] = P(1, 0);
            }
        /// bishop ?
            for(int x = -n + 1  ; x <= n - 1 ; x ++){
                int nx = i + x;
                int ny = j + x; /// same direction
                if(inside(nx, ny))
                    dist[trans(i, j, 1)][trans(nx, ny, 1)] = P(1, 0);
                ny = j - x;
                if(inside(nx, ny))
                    dist[trans(i, j, 1)][trans(nx, ny, 1)] = P(1, 0);
            }
            /// rook
            for(int x = -n + 1 ; x <= n - 1 ; x ++){
                int nx = i + x;
                int ny = j;
                if(inside(nx, ny))
                    dist[trans(i, j, 2)][trans(nx, ny, 2)] = P(1, 0);
                nx = i;
                ny = j + x;
                if(inside(nx, ny))
                    dist[trans(i, j, 2)][trans(nx, ny, 2)] = P(1, 0);
            }
            /// replace
            for(int x = 0 ; x < 3 ; x ++){
            for(int y = 0 ; y < 3 ; y ++){
                if(x != y)
                    dist[trans(i, j, x)][trans(i, j, y)] = P(1, 1);
            }
            }
        }
    }
    for(int k = 0 ; k < nax ; k ++){
        for(int i = 0 ; i < nax ; i ++){
            for(int j = 0 ;j < nax ; j ++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    //fprintf(stderr, "%d %d\n", dist[trans(1, 1, 0)][trans(3, 2, 0)].mv, dist[trans(1, 1, 0)][trans(3, 2, 0)].re );
    dp[1][0] = dp[1][1] = dp[1][2] = P(0, 0);
    for(int i = 2 ; i <= n * n ; i ++){
        for(int j = 0; j < 3 ;j ++ )
            for(int k = 0 ; k < 3 ; k ++){
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + dist[trans(pos[i - 1].first, pos[i - 1].second, k)][trans(pos[i].first, pos[i].second, j)]);
                ///fucking long line
            }
    }
    //cerr << dp[2][0].mv << ' ' << dp[2][0].re << endl;
    P res = min({dp[n * n][0], dp[n * n][1], dp[n * n][2]});
    printf("%d %d\n", res.mv, res.re);
}