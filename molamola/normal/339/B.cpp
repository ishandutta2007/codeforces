#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
using namespace std;

int p[100010];
int n,m;
__int64 ans;
int now;

int main()
{
//  freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    int i;
    for(i=1;i<=m;i++)scanf("%d",p+i);
    for(i=1;i<=m;i++){
        if(now<=p[i]){now=p[i];continue;}
        else{ans+=n;now=p[i];}
    }
    printf("%I64d",ans+now-1);
    return 0;
}