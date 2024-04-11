#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[200005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t;
    scanf("%d",&t);
    int zu;
    for (zu=0;zu<t;zu++)
    {
        int n;
        scanf("%d",&n);
        int i;
        long long sum=0;
        int flag=0;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if (i==n-1)
            {
                continue;
            }
            sum+=a[i];
            if (a[i]!=0)
            {
                flag=1;
            }
            if ((a[i]==0)&&(flag==1))
            {
                sum++;
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}