#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=200010;
int n;
unsigned int f[2][50010];
char a[MAXN];
int main()
{
    scanf("%d%s",&n,a+1);
    f[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        int now=i&1,pre=now^1,x=min(i,n-i);
        int start=(i&1)?1:2;
        if(a[i]=='?') f[now][0]=f[pre][1];
        else f[now][0]=0;
        if(a[i]!='?')
        {
            for(int j=start;j<=x;j+=2)
                f[now][j]=f[pre][j-1];
        }
        else
        {
            for(int j=start;j<=x;j+=2)
                f[now][j]=25*f[pre][j-1]+f[pre][j+1];
        }
    }
    printf("%u\n",f[n&1][0]);
    return 0;
}