#include <stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

vector <int> E[3030];

int d[3030][3030];
int n, m;
int que[3030], *fr, *re;
int s1, t1, l1, s2, t2, l2;

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int x, y;
        scanf("%d%d",&x,&y);
        E[x].push_back(y);
        E[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        fr = re = que;
        *fr++ = i;
        while(fr != re){
            int t = *re++;
            for(int j=0;j<(int)E[t].size();j++){
                int u = E[t][j];
                if(d[i][u] == 0 && u != i)d[i][u] = d[i][t] + 1, *fr++ = u;
            }
        }
    }
    scanf("%d%d%d%d%d%d", &s1, &t1, &l1, &s2, &t2, &l2);
    if(d[s1][t1] > l1 || d[s2][t2] > l2){printf("-1");return 0;}
    int ans = m - d[s1][t1] - d[s2][t2];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(d[s1][i] + d[i][j] + d[j][t1] <= l1 && d[s2][i] + d[i][j] + d[j][t2] <= l2){
                ans = max(ans, m - (d[s1][i] + d[s2][i] + d[j][t1] + d[j][t2] + d[i][j]));
            }
            if(d[s1][i] + d[i][j] + d[j][t1] <= l1 && d[s2][j] + d[i][j] + d[i][t2] <= l2){
                ans = max(ans, m - (d[s1][i] + d[s2][j] + d[j][t1] + d[i][t2] + d[i][j]));
            }
        }
    }
    printf("%d",ans);
    return 0;
}