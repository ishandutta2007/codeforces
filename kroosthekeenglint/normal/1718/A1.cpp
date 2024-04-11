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
        int i;
        int now_xor = 0;
        int ans = 0;
        set<int> s;
        s.insert(0);
        for (i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            if (x==0)
            {
                s.clear();
                now_xor = 0;
                s.insert(0);
                continue;
            }
            if (s.find(x ^ now_xor) == s.end())
            {
                now_xor ^= x;
                s.insert(now_xor);
                ans++;
            }
            else
            {
                s.clear();
                now_xor = 0;
                s.insert(0);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}