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

int d[1010][1010], C[1010][1010], A[1010][1010];

const int M = 1e9+7;

int main()
{
    int i, j, t;
    C[0][0] = 1;
    for(i=1;i<=1005;i++)C[0][i] = ((ll)C[0][i-1] * i) % M;
    for(i=1;i<=1005;i++){C[i][0] = 1;for(j=1;j<=1005;j++){
            C[i][j] = ((ll)C[i][j-1] * (i+j)) % M;
        }
    }
    d[0][0] = 1;
    d[1][0] = 0; d[1][1] = 1;
    for(i=2;i<=1005;i++){
        d[i][0] = 0;
        for(j=1;j<=min(i,50);j++)d[i][j] = (d[i-j][j-1] + d[i-j][j]) % M;
    }
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d%d",&n,&k);
        ll ans = 0;
        for(i=1;i<=n;i++)ans += ((ll)d[i][k] * C[n-i][k]) % M;
        printf("%lld\n",ans%M);
    }
    return 0;
}