#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
typedef long long LL;
int n,a[100010][51],b[100010],K,x,y,t;
bool used[100010][51];
int main()
{
    scanf("%d%d%d",&x,&y,&n);
    n--;
    while((K+1)*(K+1)<=n) K++;
    if((n-K)&1) a[K][1]=1;
    for(int i=2;i<=K;i++)
    {
        LL p=i;
        while(p<=n) b[i]++,p*=(LL)i;
    }
    for(int i=2;i<=K;i++) if(b[i]!=b[i+1]) used[i][b[i]]=true;
    for(int j=40;j>0;j--)
        for(int i=K;i>=2;i--)
            if(b[i]>=j&&!used[i][j])
            {
                if(j+1>b[i]) a[i][j]=a[i+1][j]^1;
                else if(b[i+1]<j) a[i][j]=a[i][j+1]^1;
                else
                {
                    if(a[i+1][j]==1&&a[i][j+1]==1) a[i][j]=0;
                    else a[i][j]=1;
                }
            }
    while(x==1)
    {
        t^=1;
        if((1LL<<y)>n) puts("Missing");
        else if(a[2][y]==0) puts(t==1?"Masha":"Stas");
        else {y++;continue;}
        return 0;
    }
    if(x>K)
    {
        if((n-x)&1) puts("Masha");
        else puts("Stas");
    }
    else if(a[x][y]==1) puts("Masha");
    else puts("Stas");
    return 0;
}