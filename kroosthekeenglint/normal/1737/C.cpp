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
bool corner(int r,int c,int n)
{
    if ((r == 1) || (c == 1) || (r == n) || (c == n))
    {
        return true;
    }
    return false;
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
        int r1,c1,r2,c2,r3,c3;
        scanf("%d%d%d%d%d%d",&r1,&c1,&r2,&c2,&r3,&c3);
        int x,y;
        scanf("%d%d",&x,&y);
        if (corner(r1,c1,n) && corner(r2,c2,n) && corner(r3,c3,n))
        {
            int r4 = r1^r2^r3;
            int c4 = c1^c2^c3;
            if ((r4 == 2) && (x == 1))
            {
                puts("YES");
            }
            else if ((r4 == n-1) && (x == n))
            {
                puts("YES");
            }
            else if ((c4 == 2) && (y == 1))
            {
                puts("YES");
            }
            else if ((c4 == n-1) && (y == n))
            {
                puts("YES");
            }
            else
            {
                puts("NO"); 
            }
        }
        else
        {
            x%=2;
            y%=2;
            r1%=2;
            c1%=2;
            r2%=2;
            c2%=2;
            r3%=2;
            c3%=2;
            if (((x == r1) && (y == c1)) || ((x == r2) && (y == c2)) || ((x == r3) && (y == c3)))
            {
                puts("YES");
            }
            else
            {
                puts("NO");
            }
        }
    }
    return 0;
}