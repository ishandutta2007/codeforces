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
char a[100005];
bool b[135];
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
        int m;
        scanf("%d",&m);
        scanf("%s",a);
        int n;
        scanf("%d",&n);
        int i;
        for (i='a';i<='z';i++)
        {
            b[i]=false;
        }
        for (i=0;i<n;i++)
        {
            static char s[4];
            scanf("%s",s);
            b[s[0]]=true;
        }
        int last_max=-1;
        int sum=0;
        for (i=0;a[i]!='\0';i++)
        {
            if (b[a[i]])
            {
                if (last_max!=-1)
                {
                    sum++;
                }
                last_max=max(last_max,sum);
                sum=0;
            }
            else
            {
                sum++;
            }
        }
        if (last_max==-1)
        {
            last_max=0;
        }
        printf("%d\n",last_max);
    }
    return 0;
}