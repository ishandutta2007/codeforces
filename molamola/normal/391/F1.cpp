#include<stdio.h>
#include<algorithm>
using namespace std;
#define ll long long
ll d[3030][1510], f[3030][1510], inp[3030];
int n, k;

int main(){
    scanf("%d%d",&n,&k);
    int i;
    for(i=1;i<=n;i++)scanf("%lld",inp+i);
    f[1][0] = -inp[1];
    for(i=1;i<=n;i++)f[i][0] = max(f[i-1][0],-inp[i]);
    for(i=0;i<=k;i++)f[0][i] = -1e18;
    for(i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            d[i][j] = max(d[i-1][j], f[i-1][j]+inp[i]);
            f[i][j] = max(f[i-1][j], d[i-1][j-1]-inp[i]);
        }
    }
    printf("%lld",d[n][k]);
    return 0;
}