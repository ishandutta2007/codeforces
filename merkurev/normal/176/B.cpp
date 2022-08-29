#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

char c1[1005];
char c2[1005];
int k;
int num[2][1005];
int sum[2];
int inf=1000000007;

int main()
{

    scanf("%s%s%d",c1,c2,&k);

    int l=strlen(c1);
    int t=0;
    num[0][0]=1;
    sum[0]=1;

    for (int i=0;i<k;i++)
    {
        int nxtsum=0;
        for (int j=0;j<l;j++)
        {
            int curnxtval=sum[t]-num[t][j];
            if (curnxtval<0)
                curnxtval+=inf;
            nxtsum+=curnxtval;
            num[t^1][j]=curnxtval;
            if (nxtsum>inf)
                nxtsum-=inf;
        }
        sum[t^1]=nxtsum;
        t^=1;
    }
    int ans=0;
    for (int i=0;i<l;i++)
    {
        bool good=true;
        for (int j=0;j<l && good;j++)
            if (c1[j]!=c2[(i+j)%l])
                good=false;
        if (good)
        {
            ans+=num[t][i];
            if (ans>inf)
                ans-=inf;
        }
    }
    printf("%d",ans);


    return 0;
}