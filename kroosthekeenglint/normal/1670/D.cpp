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
int ans[100005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int a=0,b=0,c=0;
    int sum=0;
    int i;
    for (i=0;sum<=1000000000;)
    {
        ans[i]=sum;
        sum+=2*(b+c);
        a++;
        i++;
        ans[i]=sum;
        sum+=2*(a+c);
        b++;
        i++;
        ans[i]=sum;
        sum+=2*(a+b);
        c++;
        i++;
    }
    int t;
    scanf("%d",&t);
    int zu;
    for (zu=0;zu<t;zu++)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",lower_bound(ans,ans+i,n)-ans);
    }
    return 0;
}