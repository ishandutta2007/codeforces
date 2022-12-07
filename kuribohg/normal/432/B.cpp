#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<cstdlib>
#include<stack>
#include<set>
#include<map>
#include<utility>
using namespace std;
int n,a[100010],b[100010],in1[100010],in2[100010];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&in1[i],&in2[i]);
        a[in1[i]]++,b[in2[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d ",n-1+a[in2[i]]);
        printf("%d\n",2*(n-1)-(n-1+a[in2[i]]));
    }
    return 0;
}