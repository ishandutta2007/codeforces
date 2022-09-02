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

int n, p[200020];

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",p+i), p[i] += i;
    sort(p, p+n);
    for(int i=0;i<n;i++)p[i] -= i;
    if(!is_sorted(p, p+n))printf(":(");
    else for(int i=0;i<n;i++)printf("%d ", p[i]);
    return 0;
}