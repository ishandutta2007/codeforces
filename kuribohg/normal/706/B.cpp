#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int n,q,a[100010];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    scanf("%d",&q);
    while(q--)
    {
        int x;
        scanf("%d",&x);
        printf("%d\n",upper_bound(a+1,a+n+1,x)-a-1);
    }
    return 0;
}