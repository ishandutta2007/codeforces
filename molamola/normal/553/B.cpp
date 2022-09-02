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

ll F[55];
int n, ans[55];
ll K;

int main() {
    F[0] = F[1] = 1;
    for(int i=2;i<=52;i++)F[i] = F[i-1] + F[i-2];
    scanf("%d%lld",&n,&K);
    for(int i=1;i<=n;){
        if(K <= F[n-i])ans[i] = i, i = i+1;
        else ans[i] = i+1, ans[i+1] = i, K -= F[n-i], i = i+2;
    }
    for(int i=1;i<=n;i++)printf("%d ", ans[i]);
    return 0;
}