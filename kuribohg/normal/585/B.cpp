#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100010;
int T,n,m;
char str[3][MAXN];
bool ok[3][MAXN];
bool notTrain(int x,int y)
{
    if(y>=n) return true;
    return str[x][y]<'A'||str[x][y]>'Z';
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<3;i++) scanf("%s",str[i]);
        memset(ok,false,sizeof(ok));
        for(int i=0;i<3;i++)
            if(str[i][0]=='s') ok[i][0]=true;
        for(int i=1;i<n;i++)
        {
            if(ok[0][i-1]&&notTrain(0,3*i-2)&&notTrain(0,3*i)&&notTrain(0,3*i-1)&&notTrain(0,3*i-2)) ok[0][i]=true;
            if(ok[1][i-1]&&notTrain(1,3*i-2)&&notTrain(0,3*i)&&notTrain(0,3*i-1)&&notTrain(0,3*i-2)) ok[0][i]=true;
            if(ok[1][i-1]&&notTrain(1,3*i-2)&&notTrain(2,3*i)&&notTrain(2,3*i-1)&&notTrain(2,3*i-2)) ok[2][i]=true;
            if(ok[2][i-1]&&notTrain(2,3*i-2)&&notTrain(2,3*i)&&notTrain(2,3*i-1)&&notTrain(2,3*i-2)) ok[2][i]=true;
            if(ok[0][i-1]&&notTrain(0,3*i-2)&&notTrain(1,3*i)&&notTrain(1,3*i-1)&&notTrain(1,3*i-2)) ok[1][i]=true;
            if(ok[1][i-1]&&notTrain(1,3*i-2)&&notTrain(1,3*i)&&notTrain(1,3*i-1)&&notTrain(1,3*i-2)) ok[1][i]=true;
            if(ok[2][i-1]&&notTrain(2,3*i-2)&&notTrain(1,3*i)&&notTrain(1,3*i-1)&&notTrain(1,3*i-2)) ok[1][i]=true;
        }
        if(ok[0][n-1]||ok[1][n-1]||ok[2][n-1]) puts("YES");
        else puts("NO");
    }
    return 0;
}