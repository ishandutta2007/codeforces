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

int n, m, K;
int inp[2520][2520];
int p1[10], p2[10];
ll ans;

#define Get(a,b,c,d) (inp[c][d]-inp[c][b-1]-inp[a-1][d]+inp[a-1][b-1])

void solve(int d,int l,int u,int r)
{
    if(d==u&&l==r){
        ans += Get(d,l,u,r)==K;
        return;
    }
    if(u-d > r-l){
        int mid = (u+d)>>1;
        int i, j, k;
        for(i=l;i<=r;i++){
            for(j=0;j<=K;j++)p1[j] = mid - d + 1, p2[j] = u - mid;
            for(j=i;j>=l;j--){
                for(k=0;k<=K;k++)while(p1[k]&&Get(mid-p1[k]+1,j,mid,i) > k)p1[k]--;
                for(k=0;k<=K;k++)while(p2[k]&&Get(mid+1,j,mid+p2[k],i) > k)p2[k]--;
                for(k=0;k<=K;k++)ans += (ll)(k?p1[k]-p1[k-1]:p1[0]) * (k!=K?p2[K-k] - p2[K-k-1]:p2[0]);
            }
        }
        solve(d,l,mid,r);
        solve(mid+1,l,u,r);
    }
    else{
        int mid = (l+r)>>1;
        int i, j, k;
        for(i=d;i<=u;i++){
            for(j=0;j<=K;j++)p1[j] = mid - l + 1, p2[j] = r - mid;
            for(j=i;j>=d;j--){
                for(k=0;k<=K;k++)while(p1[k]&&Get(j,mid-p1[k]+1,i,mid) > k)p1[k]--;
                for(k=0;k<=K;k++)while(p2[k]&&Get(j,mid+1,i,mid+p2[k]) > k)p2[k]--;
                for(k=0;k<=K;k++)ans += (ll)(k?p1[k]-p1[k-1]:p1[0]) * (k!=K?p2[K-k] - p2[K-k-1]:p2[0]);
            }
        }
        solve(d,l,u,mid);
        solve(d,mid+1,u,r);
    }
}

int main()
{
    scanf("%d%d%d",&n,&m,&K);
    int i;
    char ch[2520];
    for(i=1;i<=n;i++){
        scanf("%s",ch+1);
        for(int j=1;j<=m;j++)inp[i][j] = inp[i-1][j] + inp[i][j-1] - inp[i-1][j-1] + ch[j] - '0';
    }
    solve(1, 1, n, m);
    printf("%lld",ans);
    return 0;
}