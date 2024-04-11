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
const int inf = 1e9+5;

int n,m;
int p[5050][3];
int up[5050];
int tmp[5050][5050];
int now[5050];

int main()
{
    scanf("%d%d",&n,&m);
    int i,c=0;
    for(i=1;i<=n;i++)up[i]=inf;
    for(i=0;i<m;i++){
        int cmd,x,y,z;
        scanf("%d%d%d%d",&cmd,&x,&y,&z);
        if(cmd==1){
            for(int j=x;j<=y;j++)now[j]+=z;
        }
        else{
            ++c;
            int j;
            for(j=x;j<=y;j++){up[j]=min(up[j],z-now[j]);tmp[j][c]=now[j];}
            p[c][0]=x,p[c][1]=y,p[c][2]=z;
        }
    }
    int ans=0;
    for(i=1;i<=c;i++){
        bool flag=false;
        for(int j=p[i][0];j<=p[i][1];j++)if(up[j]+tmp[j][i]==p[i][2])flag=true;
        if(!flag)ans=1;
    }
    if(ans==1){printf("NO");return 0;}
    printf("YES\n");
    for(i=1;i<=n;i++)printf("%d ",(up[i]==inf)?int(1e9):up[i]);
    return 0;
}