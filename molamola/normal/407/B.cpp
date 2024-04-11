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

ll d[1010];
int p[1010];

int main()
{
    int n;
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++){
        scanf("%d",p+i);
    }
    for(i=1;i<=n;i++){
        d[i] = 2;
        ll s = 0;
        for(int j=i-1;j>=p[i];j--)s += d[j];
        d[i] = (d[i] + s) % (int)(1e9 + 7);
    }
    ll sum = 0;
    for(i=1;i<=n;i++)sum = (sum + d[i]) % (int)(1e9+7);
    printf("%lld",sum);
    return 0;
}