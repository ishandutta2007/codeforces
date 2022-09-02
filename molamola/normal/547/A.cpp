#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()

const ll MOD = 1e9 + 7;

int m, h[2], a[2], x[2], y[2];
int d[2][1000010];
int ans[2][2];

int gc(int x,int y){return y ? gc(y, x%y) : x;}

int main(){
    scanf("%d",&m);
    bool flag = false;
    for(int i=0;i<2;i++){
        scanf("%d%d%d%d",h+i, a+i, x+i, y+i);
        while(h[i] != a[i]){
            d[i][h[i]] = 1;
            int nxt = (int)(((ll)h[i] * x[i] + y[i]) % m);
            if(d[i][nxt]){
                flag = true;
                break;
            }
            h[i] = nxt;
            ans[i][0]++;
        }
        memset(d[i], 0, sizeof d[i]);
        int c = 0, u, tmp = a[i];
        for(u=0;u<=m;u++){
            c++;
            int nxt = (int)(((ll)tmp * x[i] + y[i]) % m);
            if(nxt == a[i]){
                ans[i][1] = c;
                break;
            }
            tmp = nxt;
        }
        if(u == m+1)ans[i][1] = -1;
    }
    if(flag)printf("-1");
    else if(ans[0][1] == -1){
        if(ans[0][0] == ans[1][0])printf("%d", ans[0][0]);
        else if(ans[1][1] != -1 && ans[0][0] >= ans[1][0] && (ans[0][0] - ans[1][0]) % ans[1][1] == 0)printf("%d", ans[0][0]);
        else printf("-1");
    }
    else{
        if(ans[1][1] == -1){
            if(ans[1][0] >= ans[0][0] && (ans[1][0] - ans[0][0]) % ans[0][1] == 0)printf("%d", ans[1][0]);
            else printf("-1");
        }
        else{
            int u;
        for(u=0;u<=m;u++){
            ll t = ans[0][0] + (ll)ans[0][1] * u;
            if(t >= ans[1][0] && (t - ans[1][0]) % ans[1][1] == 0){
                printf("%lld", t);
                break;
            }
        }
        if(u == m+1)printf("-1");
        }
    }
    return 0;
}