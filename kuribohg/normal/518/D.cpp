#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=2010;
int n,t;
double p,f[MAXN][MAXN],ans;
int main()
{
    scanf("%d%lf%d",&n,&p,&t);
    f[0][0]=1;
    for(int i=0;i<t;i++)
    {
        for(int j=0;j<n;j++)
            f[i+1][j+1]+=p*f[i][j],
            f[i+1][j]+=(1-p)*f[i][j];
        f[i+1][n]+=f[i][n];
    }
    for(int i=0;i<=n;i++)
        ans+=i*f[t][i];
    printf("%.010lf\n",ans);
    return 0;
}