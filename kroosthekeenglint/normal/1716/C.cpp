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
int a[5][200005];
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
        //int n = 2;
        int i,j;
        for (i=0;i<2;i++)
        {
            for (j=0;j<m;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        int time_1 = 0, time_2 = 0;
        for (i=1;i<m;i++)
        {
            time_1 ++;
            if (time_1 <= a[0][i])
            {
                time_1 = a[0][i] + 1;
            }
        }
        for (i--;i>=0;i--)
        {
            time_1++;
            if (time_1 <= a[1][i])
            {
                time_1 = a[1][i] + 1;
            }
        }
        for (i=0;i<m;i++)
        {
            time_2 ++;
            if (time_2 <= a[1][i])
            {
                time_2 = a[1][i] + 1;
            }
        }
        for (i--;i>=1;i--)
        {
            time_2++;
            if (time_2 <= a[0][i])
            {
                time_2 = a[0][i] + 1;
            }
        }
        int min_time = min(time_1, time_2);
        int time_3 = 0;
        for (i=0;i<m;i++)
        {
            if (i%2==0)
            {
                min_time = min(min_time, max(time_3 + (m-i)*2 - 1, time_1 - i)); 
            }
            else
            {
                min_time = min(min_time, max(time_3 + (m-i)*2 + 1, time_2 - i + 1)); 
                time_3 ++;
                if (time_3 <= a[1][i-1])
                {
                    time_3 = a[1][i-1] + 1;
                }
                time_3 ++;
                if (time_3 <= a[1][i])
                {
                    time_3 = a[1][i] + 1;
                }
                time_3 ++;
                if (time_3 <= a[0][i])
                {
                    time_3 = a[0][i] + 1;
                }
                time_3 ++;
                if (time_3 <= a[0][i+1])
                {
                    time_3 = a[0][i+1] + 1;
                }
            }
        }
        printf("%d\n",min_time);
    }
    return 0;
}