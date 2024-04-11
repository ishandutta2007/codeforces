#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

void solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    int sum=0;
    for(int i=1;i<=n;i++)
        sum=sum+inp[i];

    if(sum==0)
    {
        printf("NO\n");
        return;
    }

    sort(inp+1,inp+n+1);

    if(sum>0)reverse(inp+1,inp+n+1);

    printf("YES\n");
    for(int i=1;i<=n;i++)printf("%i ",inp[i]);
    printf("\n");
}
int main()
{
    int t;
    scanf("%i",&t);
    while(t)
    {
        solve();
        t--;
    }

    return 0;
}