#include <bits/stdc++.h>
using namespace std;
#define N 110
#define M 10010
struct node
{
    int w, v;
    void pr() {
        printf("[%d , %d]\n", w, v);
    }
}p[N];
bool cmp(node a, node b){
    return a.v > b.v;
}
int dp[M][N], n;
bool reach[M][N];
void gao(int km, int wt, int V) 
{
    memset(dp, 0, sizeof(dp));
    memset(reach, false, sizeof(reach));
    reach[0][0] = true;
    for(int i = 0;i < n;i++) {
        int v = p[i].v, w = p[i].w;
        for(int j = V;j >= v;j--) 
            for(int k = min(km, i+1);k >= 1;k--) if(reach[j-v][k-1]){
                reach[j][k] = true;
                dp[j][k] = max(dp[j][k], dp[j-v][k-1] + w);
        }
    }
    int ans = 0;
    for(int j = wt;j <= V;j++)
        ans = max(ans, dp[j][km]);
    ans = wt - ans;
    printf("%d %d\n", km, ans);
}
int main()
{
    while(~scanf("%d", &n)) {
        int wt = 0;
        for(int i = 0;i < n;i++) {
            scanf("%d", &p[i].w);
            wt += p[i].w;
        }
        for(int i = 0;i < n;i++)
            scanf("%d", &p[i].v);
        sort(p, p+n, cmp);
        int km = 0, vt = 0;
        for(int i = 0;i < n;i++) {
            vt += p[i].v;
            if(vt >= wt) {
                km = i+1;
                break;
            }
        }
        gao(km, wt, vt);
    }
    return 0;
}