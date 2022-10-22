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
        int tag_0=1,tag_1=0;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if (a[i]!=0)
            {
                tag_0=0;
                if (tag_1<=1)
                {
                    tag_1=1;
                }
                else
                {
                    tag_1=3;
                }
            }
            else
            {
                if (tag_1==1)
                {
                    tag_1=2;
                }
            }
        }
        if (tag_0==1)
        {
            printf("0\n");
        }
        else if (tag_1!=3)
        {
            printf("1\n");
        }
        else
        {
            printf("2\n");
        }
    } 
    return 0;
}