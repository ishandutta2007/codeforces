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
char a[200005];
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
        scanf("%s",a);
        int i;
        int last_num=-1;
        int sum=0;
        int cnt=0;
        for (i=0;i<n;i+=2)
        {
            if (a[i]==a[i+1])
            {
                if (a[i]-'0' != last_num)
                {
                    last_num = a[i]-'0';
                    sum++;
                }
            }
            else
            {
                cnt++;
            }
        }
        if (sum==0)
        {
            sum++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}