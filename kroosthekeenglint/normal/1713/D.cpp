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
int winner[1<<18];
int query(int x,int y)
{
    printf("? %d %d\n",x+1,y+1);
    fflush(stdout);
    int t;
    scanf("%d",&t);
    return t;
}
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
        for (i=0;i<(1<<n);i++)
        {
            winner[i] = i;
        }
        for (;;)
        {
            if (n==1)
            {
                int t = query(winner[0], winner[1]);
                if (t == 1)
                {
                    printf("! %d\n",winner[0]+1);
                }
                else
                {
                    printf("! %d\n",winner[1]+1);
                }
                fflush(stdout);
                break;
            }
            for (i=0;i<(1<<n);i+=4)
            {
                int t = query(winner[i], winner[i+2]);
                if (t == 0)
                {
                    winner[i / 2] = winner[i+1];
                    winner[i / 2 + 1] = winner[i+3];
                }
                else if (t == 1)
                {
                    winner[i / 2] = winner[i];
                    winner[i / 2 + 1] = winner[i+3];
                }
                else if (t == 2)
                {
                    winner[i / 2] = winner[i+2];
                    winner[i / 2 + 1] = winner[i+1];
                }
            }
            n--;
        }
    }
    return 0;
}