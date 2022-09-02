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

int n, m, k;
char change[130];
int top;
int ans[2020];

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    int i, j;
    for(i=1;i<=n;i++){
        char ch[2020];
        scanf("%s",ch+1);
        for(j=1;j<=m;j++){
            if(ch[j] == 'R'){
                if(i + j - 1 <= m)ans[i+j-1]++;
            }
            else if(ch[j] == 'L'){
                if(j-i+1>=1)ans[j-i+1]++;
            }
            else if(ch[j] == 'U'){
                if(i&1)ans[j]++;
            }
        }
    }
    for(i=1;i<=m;i++)printf("%d ",ans[i]);
    return 0;
}