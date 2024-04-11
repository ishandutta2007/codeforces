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
void dfs(int n)
{
    n--;
    if (n == -1)
    {
        return;
    }
    int i = sqrt(n);
    if (i*i != n)
    {
        i++;
    }
    dfs(i*i - n);
    int j;
    for (j = i*i - n; j<= n; j++)
    {
        a[j] = i * i - j;
    }
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t;
    scanf("%d",&t);
    int i;
    for (i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        dfs(n);
        int i;
        for (i=0;i<n;i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
    }
    return 0;
}