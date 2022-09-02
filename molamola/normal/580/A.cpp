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

int n, d[100010], p[100010];

int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;i++)scanf("%d",p+i);
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(p[i] >= p[i-1])d[i] = d[i-1] + 1;
        else d[i] = 1;
        ans = max(ans, d[i]);
    }
    printf("%d",ans);
    return 0;
}