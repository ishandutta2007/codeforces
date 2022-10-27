#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10 , inf = 2e9;
int n;
pair<int,int> b[maxn];
struct pa{
    int val;
    int res;
    pa() : val(inf), res(-1) {}
    pa(int x, int y) : val(x), res(y) {}
}go[maxn][3];
int color;
int c[maxn];

int main(){
    scanf("%d", &n);
    for(int i = 1 ;i <= n; i++){
        scanf("%d", &b[i].first);
        b[i].second = i;
    }
    sort(b + 1 , b + 1 + n);
    go[1][0] = pa(-b[1].first, 1);
    for(int i = 2 ; i <= n ; i ++){
        for(int j = 0 ;j < 3 ; j ++){
            if(j == 0){
                if(go[i-1][2].val != inf && go[i-1][2].val - b[i].first < go[i][0].val){
                    go[i][0] = pa(go[i-1][2].val - b[i].first, 1);
                }
            }
            else if(j == 1){
                if(go[i-1][0].val != inf && go[i-1][0].val + b[i].first < go[i][1].val){
                    go[i][1] = pa(go[i-1][0].val + b[i].first, 2);
                }
            }
            else if(j == 2){
                if(go[i-1][1].val != inf && go[i-1][1].val + (b[i].first - b[i-1].first) < go[i][2].val){
                    go[i][2] = pa(go[i-1][1].val + (b[i].first - b[i-1].first), 3);
                }
                if(go[i-1][2].val != inf && go[i-1][2].val + (b[i].first - b[i-1].first) < go[i][2].val){
                    go[i][2] = pa(go[i-1][2].val + (b[i].first - b[i-1].first), go[i-1][2].res + 1);
                }
            }
        }
    }
    int ans = go[n][2].val;
    int now = n;
    while(true){
        if(now <= 0) break;
        int togo = go[now][2].res;
        ++color;
        for(int j = 0 ;j < togo ; j ++){
            c[b[now - j].second] = color;
        }
        now -= togo;
    }
    printf("%d %d\n", ans, color);
    for(int i = 1 ; i <= n ; i++)
        printf("%d ", c[i]);
}