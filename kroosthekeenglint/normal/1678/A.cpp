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
int a[100005];
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
        int i;
        bool have_0=true;
        int n;
        scanf("%d",&n);
        int ans=n;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        for (i=0;i<n;i++)
        {
            if (a[i]==0)
            {
                have_0=false;
                ans--;
            }
            if ((i!=0)&&(a[i]==a[i-1]))
            {
                have_0=false;
            }
        }
        printf("%d\n",have_0+ans);
    }
    return 0;
}