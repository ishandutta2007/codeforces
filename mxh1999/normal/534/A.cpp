#include<bits/stdc++.h>
using namespace std;

#define maxn 5010
int n,m;
bool a[maxn];
int ans[maxn];

int main()
{
    scanf("%d",&n);
    if (n==1||n==2) printf("1\n1\n");
    else if(n==3) printf("2\n1 3\n");
    else
    {
        printf("%d\n",n);
        for (int i=2;i<=n;i+=2) printf("%d ",i);
        for (int i=1;i<=n;i+=2) printf("%d ",i);
    }
    return 0;
}