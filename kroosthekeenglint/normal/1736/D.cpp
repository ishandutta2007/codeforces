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
        scanf("%d%s",&n,a);
        int i;
        vector<int> rotate;
        rotate.clear();
        char last_num = '0';
        for (i=0;i<2*n;i+=2)
        {
            if (a[i] == a[i+1])
            {
                continue;
            }
            if (a[i] == last_num)
            {
                rotate.push_back(i+1);
            }
            else
            {
                rotate.push_back(i);
            }
            last_num ^= 1;
        }
        if (last_num == '1')
        {
            puts("-1");
        }
        else
        {
            printf("%u",rotate.size());
            for (i=0;i<(int)rotate.size();i++)
            {
                printf(" %d",rotate[i]+1);
            }
            printf("\n");
            for (i=1;i<=n;i++)
            {
                printf("%d ",i*2); 
            }
            printf("\n");
        }
    }
    return 0;
}