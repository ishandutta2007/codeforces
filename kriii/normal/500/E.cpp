#include <stdio.h>
#include <algorithm>
using namespace std;

int N,p[200005],l[200005];
int go[19][200005],far[19][200005],cost[19][200005];

const int Z = 1<<18;
int mn[Z*2],top[Z*2];

int main()
{
    scanf ("%d",&N);
    for (int i=1;i<=N;i++){
        scanf ("%d %d",&p[i],&l[i]);
    }

    for (int i=N;i>=1;i--){
        int ind = upper_bound(p+i+1,p+N+1,p[i]+l[i]) - p; ind--;

        int r = i, t = p[i] + l[i], x = i+1+Z, y=ind+Z;
        while (x < y){
            if (x & 1){
                if (r < mn[x]){
                    r = mn[x];
                }
                if (t < top[x]){
                    t = top[x];
                }
                x++;
            }
            if (~y & 1){
                if (r < mn[y]){
                    r = mn[y];
                }
                if (t < top[y]){
                    t = top[y];
                }
                y--;
            }
            x >>= 1; y >>= 1;
        } if (x == y){
            if (r < mn[x]){
                r = mn[x];
            }
            if (t < top[x]){
                t = top[x];
            }
        }
        go[0][i] = r;
        far[0][i] = t;
        x = i+Z; mn[x] = r; top[x] = t; x >>= 1;
        while (x){
            mn[x] = max(mn[x*2],mn[x*2+1]);
            top[x] = max(top[x*2],top[x*2+1]);
            x >>= 1;
        }
    }

    for (int k=1;k<19;k++){
        for (int i=N;i>=1;i--){
            int nxt = go[k-1][i];
            if (nxt == N) go[k][i] = N, cost[k][i] = cost[k-1][i];
            else{
                go[k][i] = go[k-1][nxt+1];
                cost[k][i] = cost[k-1][i] + cost[k-1][nxt+1] + p[nxt+1] - far[k-1][i];
                far[k][i] = far[k-1][nxt+1];
            }
        }
    }

    int Q; scanf ("%d",&Q); while (Q--){
        int x,y; scanf ("%d %d",&x,&y);
        int ans = 0;
        for (int k=18;k>=0;k--){
            int nxt = go[k][x];
            if (nxt >= y) continue;
            ans += p[nxt+1] - far[k][x] + cost[k][x];
            x = nxt+1;
        }
        printf ("%d\n",ans);
    }

    return 0;
}