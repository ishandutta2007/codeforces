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
int a[100005];
int b[100005];
int vis[100005];
const int modo=1000000007;
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
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            b[a[i]]=i;
            vis[i]=false;
        }
        vis[n]=0;
        int now_l = b[0];
        int now_r = b[0]+1;
        int current_mex = 1;
        vis[0] = true;
        int p=1;
        int rest_loc = 0;
        for (i=1;i<n;i++)
        {
            if (b[i]<now_l)
            {
                for (;now_l>b[i];)
                {
                    now_l--;
                    vis[a[now_l]]++;
                    rest_loc++;
                }
            }
            else if (b[i] >= now_r)
            {
                for (;now_r<=b[i];)
                {
                    vis[a[now_r]]++;
                    now_r++;
                    rest_loc++;
                }
            }
            else
            {
                continue;
            }
            current_mex++;
            rest_loc--;
            for (;vis[current_mex];current_mex++)
            {
                p = (long long)p*rest_loc%modo;
                rest_loc--;
            }
        }
        printf("%d\n",p);
    }
    return 0;
}