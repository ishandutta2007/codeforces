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

int p[2020][2020];
int chk[2020][2],cnt[2],n;

void dfs(int x)
{
    chk[x][0] = 1;cnt[0]++;
    for(int i=0;i<n;i++)if(!chk[i][0]&&p[x][i])dfs(i);
}

void dfs2(int x)
{
    chk[x][1] = 1;cnt[1]++;
    for(int i=0;i<n;i++)if(!chk[i][1]&&p[i][x])dfs2(i);
}

int main()
{
//  freopen("input.txt","r",stdin);
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)for(j=0;j<n;j++)scanf("%d",p[i]+j);
    dfs(0);
    dfs2(0);
    printf("%s",(cnt[0]==n&&cnt[1]==n)?"YES":"NO");
    return 0;
}