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
int a[100005],b[100005];
int anti_a[100005];
bool vis[100005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
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
            a[i]--;
            anti_a[a[i]]=i;
        }
        for (i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
            b[i]--;
            b[i]=anti_a[b[i]];
        }
        for (i=0;i<n;i++)
        {
            vis[i]=false;
        }
        int cnt=0;
        long long sum=0;
        for (i=0;i<n;i++)
        {
            if (vis[i])
            {
                continue;
            }
            int now=i;
            int num=0;
            for (;;)
            {
                vis[now]=true;
                now=b[now];
                num++;
                if (now==i)
                {
                    break;
                }
            }
            for (num-=2;num>=0;num-=2)
            {
                sum+=(n-1-cnt*2)*2;
                cnt++;
            }
        }
        cout<<sum<<"\n";
    }
    return 0;
}