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

int cb[1<<18];
ll d[1<<18][18];
int n, m, k, a[24];
int w[24][24];
ll ans;

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)scanf("%d",a+i);
    for(int i=0;i<k;i++){
        int x, y, c;
        scanf("%d%d%d",&x,&y,&c); --x, --y;
        w[x][y] = c;
    }
    for(int i=1;i<1<<n;i++){
        for(int j=0;j<n;j++)if(1<<j & i){cb[i] = cb[i^1<<j] + 1;break;}
    }
    for(int i=0;i<n;i++)d[1<<i][i] = a[i];
    for(int i=1;i<1<<n;i++){
        if(cb[i] > m)continue;
        
        for(int j=0;j<n;j++){
            if(1<<j & i){
                for(int k=0;k<n;k++){
                    if(1<<k & (i^1<<j))d[i][j] = max(d[i][j], a[j] + d[i^1<<j][k] + w[k][j]);
                }
            }
        }
        if(cb[i] == m)for(int j=0;j<n;j++)if(1<<j&i)ans = max(ans, d[i][j]);
    }
    printf("%lld", ans);
    return 0;
}