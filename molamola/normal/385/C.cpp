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

int chk[10000010];
bool isp[10000010];
int db[10000010];
ll sum[10000010];

int main()
{
    int n;
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        chk[x]++;
    }
    for(i=2;i<=10000000;i++){
        if(isp[i])continue;
        for(int j=i;j<=10000000;j+=i){
            if(chk[j])db[i]+=chk[j];
            isp[j] = true;
        }
    }
    for(i=2;i<=10000000;i++)sum[i] = sum[i-1] + db[i];
    int m;
    scanf("%d",&m);
    while(m--){
        int x, y;
        scanf("%d%d",&x,&y);
        if(x>1e7)x=1e7;
        if(y>1e7)y=1e7;
        printf("%lld\n",sum[y] - sum[x-1]);
    }
    return 0;
}