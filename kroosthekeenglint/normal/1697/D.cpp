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
char a[10005];
char next_c[15];
int b[35];
bool check(int mid, int sum, int i)
{
    printf("? 2 %d %d\n",b[mid]+1,i+1);
    fflush(stdout);
    int ans;
    scanf("%d",&ans);
    if (ans + mid == sum)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    int sum=0;
    for (i=0;i<n;i++)
    {
        int l=0,r=sum-1;
        for (;l<=r;)
        {
            int mid=(l+r)/2;
            if (check(mid, sum, i))
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        if (r==-1)
        {
            printf("? 1 %d\n", i+1);
            fflush(stdout);
            b[sum]=i;
            sum++;
            scanf("%s",next_c);
            a[i]=next_c[0]; 
        }
        else
        {
            a[i]=a[b[r]];
            b[r]=i;
            sort(b,b+sum);
        }
    }
    printf("! %s\n",a);
    fflush(stdout);
    return 0;
}