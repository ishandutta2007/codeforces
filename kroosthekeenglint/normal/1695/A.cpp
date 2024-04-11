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
        int n,m;
        scanf("%d%d",&n,&m);
        int i,j;
        int max_ans=-1000000007;
        int max_i=-1,max_j=-1;
        for (i=0;i<n;i++)
        {
            for (j=0;j<m;j++)
            {
                int x;
                scanf("%d",&x);
                if (x>max_ans)
                {
                    max_i=i;
                    max_j=j;
                    max_ans=x;
                }
            }
        }
        printf("%d\n",max(n-max_i,max_i+1)*max(m-max_j,max_j+1));
    }
    return 0;
}