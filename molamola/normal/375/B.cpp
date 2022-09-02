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

vector <Pi> v;

bool inp[5050][5050];
int p[5050][5050],q[5050][5050];
int ans;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int i,j;
    char ch[5050];
    for(i=1;i<=n;i++){
        scanf("%s",ch+1);
        for(j=1;j<=m;j++){
            inp[i][j]=ch[j]=='1';
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(inp[i][j])p[i][j]=p[i][j-1]+1;
            else p[i][j]=0;
        }
    }
    for(i=1;i<=n;i++)for(j=1;j<=m;j++)q[j][p[i][j]]++;
    for(j=1;j<=m;j++){
        int c=0;
        for(i=j;i;i--){
            c+=q[j][i];
            ans=max(ans,i*c);
        }
    }
    printf("%d",ans);
    return 0;
}