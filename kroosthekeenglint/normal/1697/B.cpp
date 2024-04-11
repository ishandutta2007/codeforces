#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<memory>
#include<time.h>
#include<math.h>
#include<bitset>
#include<fstream>
#include<sstream>
#include<stdio.h>
#include<utility>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[200005];
long long sum[200005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    int n,q;
    scanf("%d%d",&n,&q);
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    for (i=n;i>=1;i--)
    {
        sum[i-1]=sum[i]+a[i-1];
    }
    for (i=0;i<q;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        cout<<sum[n-x]-sum[n-x+y]<<"\n";
    }
    return 0;
}