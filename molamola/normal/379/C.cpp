#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
#include<queue>
#include<functional>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> Pi;


Pi inp[300010];
int ans[300030];

int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){scanf("%d",&inp[i].X);inp[i].Y=i;}
    sort(inp,inp+n);
    int now=0;
    for(i=0;i<n;i++){
        if(now>=inp[i].X)inp[i].X=++now;
        else now=inp[i].X;
    }
    for(i=0;i<n;i++)ans[inp[i].Y]=inp[i].X;
    for(i=0;i<n;i++)printf("%d ",ans[i]);
    return 0;
}