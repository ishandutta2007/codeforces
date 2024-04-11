#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,x[5],y[5];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(x[i]!=x[j]&&y[i]!=y[j])
            {
                printf("%d\n",(max(x[i],x[j])-min(x[i],x[j]))*(max(y[i],y[j])-min(y[i],y[j])));
                return 0;
            }
    puts("-1");
    return 0;
}