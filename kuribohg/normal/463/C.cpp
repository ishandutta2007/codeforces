#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n,bx,by,wx,wy;
long long d1[5010],d2[5010],a[2010][2010];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%I64d",&a[i][j]);
            d1[i+j-1]+=a[i][j],d2[i-j+n]+=a[i][j];
        }
    bx=1,by=1,wx=1,wy=2;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if((i+j)%2==1)
            {
                if(d1[i+j-1]+d2[i-j+n]-a[i][j]>d1[bx+by-1]+d2[bx-by+n]-a[bx][by])
                    bx=i,by=j;
            }
            else
            {
                if(d1[i+j-1]+d2[i-j+n]-a[i][j]>d1[wx+wy-1]+d2[wx-wy+n]-a[wx][wy])
                    wx=i,wy=j;
            }
        }
    printf("%I64d\n",d1[bx+by-1]+d2[bx-by+n]-a[bx][by]+d1[wx+wy-1]+d2[wx-wy+n]-a[wx][wy]);
    printf("%d %d %d %d\n",bx,by,wx,wy);
    return 0;
}