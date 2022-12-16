#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n,inp[nmax];
void solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=2;i<=n;i++)
        if(max(inp[i-1],inp[i])-min(inp[i-1],inp[i])>=2)
        {
            printf("YES\n");
            printf("%i %i\n",i-1,i);
            return;
        }
    printf("NO\n");
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