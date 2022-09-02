#include<stdio.h>
#include<algorithm>
using namespace std;

int n,m;
int inp[110];
char ch[20][2],mode[20];
int dp[1<<20],p[20];
bool chk[1<<20];

int dfs(int x,int bit)
{
    if(chk[bit])return dp[bit];
    chk[bit]=1;
    if(bit+1 == (1<<m))return 0;
    int tmp = (mode[x]==2?1:-1)*1e8;
    for(int i=0;i<m;i++){
        if(bit&(1<<i))continue;
        int a = dfs(x+1,bit|(1<<i));
        if(mode[x]==2){
            if(ch[x][0]=='b')tmp=min(tmp,a);
            else tmp=min(tmp,a-inp[i]);
        }
        else{
            if(ch[x][0]=='b')tmp=max(tmp,a);
            else tmp=max(tmp,a+inp[i]);
        }
    }
    return dp[bit]=tmp;
}

int main(){
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)scanf("%d",inp+i);
    sort(inp,inp+n);
    reverse(inp,inp+n);
    scanf("%d",&m);
    for(i=0;i<m;i++)scanf("%s %d\n",ch[i],mode+i);
    printf("%d",dfs(0,0));
    return 0;
}