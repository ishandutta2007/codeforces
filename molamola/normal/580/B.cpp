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

int n, d;
Pi p[100010];
ll sum[100010];
ll ans;

int main(){
    scanf("%d%d",&n,&d);
    for(int i=0;i<n;i++)scanf("%d%d",&p[i].Fi,&p[i].Se);
    sort(p, p+n);
    for(int i=0;i<n;i++)sum[i] = p[i].Se;
    for(int i=1;i<n;i++)sum[i] += sum[i-1];
    for(int i=0, j=0;i<n;i++){
        while(j != n && p[i].Fi - p[j].Fi >= d)++j;
        ans = max(ans, sum[i] - (j ? sum[j-1] : 0));
    }
    printf("%lld",ans);
    return 0;
}