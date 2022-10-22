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
char a[1000005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t;
    scanf("%d",&t);
    int i;
    for (i=0;i<t;i++) 
    {
        scanf("%s",a);
        int sum=0;
        int j;
        for (j=0;a[j]!='\0';j++)
        {
            sum+=(a[j]-'a'+1);
        }
        if (j%2==0)
        {
            printf("Alice %d\n",sum);
        }
        else if (j!=1)
        {
            printf("Alice %d\n",sum-2*(min(a[0],a[j-1])-'a'+1));
        }
        else
        {
            printf("Bob %d\n",sum);
        }
    }
    return 0;
}