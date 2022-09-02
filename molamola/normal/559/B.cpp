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
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()

char A[200020], B[200020];

bool dfs(int La, int Lb, int sz){
    if(sz % 2 == 1){
        for(int i=0;i<sz;i++)if(A[La+i] != B[Lb+i])return false;
        return true;
    }
    if(dfs(La, Lb, sz/2))return dfs(La + sz/2, Lb + sz/2, sz/2);
    else return dfs(La+sz/2, Lb, sz/2) && dfs(La, Lb+sz/2, sz/2);
}

int main() {
    scanf("%s%s",A,B);
    int len = (int)strlen(A);
    printf("%s", dfs(0, 0, len) ? "YES" : "NO");
    return 0;
}