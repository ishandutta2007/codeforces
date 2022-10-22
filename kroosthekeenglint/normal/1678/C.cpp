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
int cnt[5005][5005];
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
        }
        for (i=0;i<n;i++)
        {
            int j;
            cnt[i][0]=0;
            for (j=0;j<n;j++)
            {
                if (a[i]>a[j])
                {
                    cnt[i][j+1]=cnt[i][j]+1;
                }
                else
                {
                    cnt[i][j+1]=cnt[i][j];
                }
            }
        }
        long long ans=0;
        for (i=1;i<n-2;i++)
        {
            int j;
            for (j=i+1;j<n-1;j++)
            {
                ans += cnt[j][i] * (a[i]-1-cnt[i][j+1]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}