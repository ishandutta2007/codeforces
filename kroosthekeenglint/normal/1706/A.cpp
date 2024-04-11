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
char a[55]; 
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int zu;
    int t;
    scanf("%d",&t);
    for (zu=0;zu<t;zu++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int i;
        for (i=0;i<m;i++)
        {
            a[i]='B';
        }
        a[m]='\0';
        for (i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            x--;
            x=min(x,m-x-1);
            if (a[x]=='A')
            {
                x=m-x-1;
            }
            a[x]='A';
        }
        printf("%s\n",a);
    }
    return 0;
}