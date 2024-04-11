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
        long long sum = 0;
        int i;
        for (i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            sum+=x; 
        }
        int max_ans = 0;
        for (i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            sum+=x; 
            max_ans = max(max_ans, x);
        }
        printf("%lld\n",sum - max_ans);
    }
    return 0;
}