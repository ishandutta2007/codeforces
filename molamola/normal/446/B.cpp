#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
#include<queue>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> Pi;

int a[1010][1010];
int n, m, k, p;
priority_queue <int> pq[2];
int mm[2];
int c[1010], r[1010];
ll ans[1000010];

int main()
{
    scanf("%d%d%d%d",&n,&m,&k,&p);
    int i, j;
    for(i=0;i<n;i++)for(j=0;j<m;j++)scanf("%d",a[i]+j);
    for(i=0;i<n;i++)for(j=0;j<m;j++)c[i] += a[i][j], r[j] += a[i][j];
    for(i=0;i<n;i++)pq[0].push(c[i]);
    for(i=0;i<m;i++)pq[1].push(r[i]);
    ll now = 0;
    for(i=1;i<=k;i++){
        int x = pq[0].top();
        now += x;
        ans[i] += now;
        pq[0].pop();
        pq[0].push(x - m*p);
    }
    now = 0;
    for(i=1;i<=k;i++){
        int x = pq[1].top();
        now += x;
        ans[k-i] += now;
        pq[1].pop();
        pq[1].push(x - n*p);
    }
    for(i=1;i<=k;i++){
        ans[i] -= (ll)i*(k-i)*p;
    }
    ll A = -2e18;
    for(i=0;i<=k;i++)A = max(A, ans[i]);
    printf("%lld",A);
    return 0;
}