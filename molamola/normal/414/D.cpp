#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> Pi;

int m, k, p;
int st[100010], en[200020], nxt[200020];
void addE(int s,int e,int c){nxt[c]=st[s],st[s]=c,en[c]=e;}

int dep[100010];
int cnt[100010];

void dfs(int x,int f)
{
    for(int i=st[x];i;i=nxt[i]){
        if(en[i] != f){dep[en[i]] = dep[x] +1, dfs(en[i], x);}
    }
}

ll sum[100010];

int main()
{
    scanf("%d%d%d",&m,&k,&p);
    int i;
    for(i=1;i<m;i++){
        int x, y;
        scanf("%d%d",&x,&y);
        addE(x, y, i<<1);
        addE(y, x, i<<1|1);
    }
    dfs(1,-1);
    for(i=1;i<=m;i++)cnt[dep[i]] ++;
    cnt[0] = 0;
    for(i=1;i<=m;i++)sum[i] = sum[i-1] + cnt[i];
    ll now = 0;
    int s = 1;
    ll ans = cnt[1];
    for(i=2;i<=m;i++){
        now += sum[i-1] - sum[s-1];
        if(now <= p){
            ans = max(ans, sum[i] - sum[s-1]);
            continue;
        }
        while(now > p){
            now -= (ll)(i-s) * cnt[s];
            s++;
        }
        int t = i-s+1;
        ans = max(ans, sum[i] - sum[s-1] + (p-now)/t);
    }
    printf("%lld",min(ans,(ll)k));
    return 0;
}