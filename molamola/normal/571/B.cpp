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

int n, p[300030], k;
int d[5050][5050];

int main(){
    scanf("%d%d",&n, &k);
    for(int i=0;i<n;i++)scanf("%d",p+i);
    sort(p, p+n);
    int a = n / k;
    int b = n - k * a;
    int c = k - b;
    d[0][0] = 0;
    for(int i=0;i<=c;i++){
        for(int j=0;j<=b;j++){
            if(i || j)d[i][j] = 2e9 + 10;
            if(i != 0)d[i][j] = min(d[i][j], d[i-1][j] + p[a*(i+j)+j-1] - p[a*(i-1+j)+j]);
            if(j != 0)d[i][j] = min(d[i][j], d[i][j-1] + p[a*(i+j)+j-1] - p[a*(i+j-1)+j-1]);
        }
    }
    printf("%d", d[c][b]);
    return 0;
}