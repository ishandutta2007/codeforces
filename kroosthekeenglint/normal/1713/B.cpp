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
        int n;
        scanf("%d",&n);
        int i;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        int flag = 0;
        for (i=1;i<n;i++)
        {
            if ((a[i] > a[i-1]) && (flag == 1))
            {
                flag = 2;
            }
            else if ((a[i] < a[i-1]) && (flag == 0))
            {
                flag = 1;
            }
        }
        if (flag == 2)
        {
            puts("NO");
        }
        else
        {
            puts("YES");
        }
    }
    return 0;
}