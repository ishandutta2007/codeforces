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

int main() {
    int a[6];for(int i=0;i<6;i++)scanf("%d",a+i);
    int ans = (a[0] + a[1] + a[2]) * (a[0] + a[1] + a[2]) - a[0] * a[0] - a[2] * a[2] - a[4] * a[4];
    printf("%d", ans);
    return 0;
}