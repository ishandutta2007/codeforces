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
int a[155];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int zu;
    for (zu=0;zu<t;zu++)
    {
        int i;
        char x;
        memset(a,0,sizeof(a));
        int ans = -1;
        for (i=0;i<4;i++)
        {
            cin>>x;
            a[x]++;
            if (a[x] == 1)
            {
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}