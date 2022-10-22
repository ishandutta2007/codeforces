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
int a[1005];
char s1[100005],s2[100005];
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
        scanf("%s%s",s1,s2);
        int i;
        for (i=0;i<=1000;i++)
        {
            a[i] = 0;
        }
        for (i=0;i<n;i++)
        {
            char x = s1[i];
            char y = s2[n-i-1];
            if (x > y)
            {
                swap(x,y);
            }
            a[(x-'a')*26+y-'a']^=1;
        }
        int cnt = 0;
        for (i=0;i<=1000;i++)
        {
            if (a[i] == 1)
            {
                if (i%26 == i/26)
                {
                    cnt++;
                }
                else
                {
                    cnt += 3; 
                }
            }
        }
        if (cnt <= 1)
        {
            puts("YES");
        }
        else
        {
            puts("NO");
        }
    }
    return 0;
}