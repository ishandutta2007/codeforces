#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
int m,n;
double ans,p=1;
int main()
{
    scanf("%d%d",&m,&n);
    for(int i=m;i>=1;i--)
    {
        ans+=i*(p-p*pow((i-1)*1.0/i,n));
        p-=p-p*pow((i-1)*1.0/i,n);
    }
    printf("%.15lf\n",ans);
    return 0;
}