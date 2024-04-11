#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n,x[nmax],y[nmax];

void solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&x[i]);
    for(int i=1;i<=n;i++)scanf("%i",&y[i]);

    sort(x+1,x+n+1);
    sort(y+1,y+n+1);

    for(int i=1;i<=n;i++)printf("%i ",x[i]);printf("\n");
    for(int i=1;i<=n;i++)printf("%i ",y[i]);printf("\n");
}
int main()
{
    int t;
    scanf("%i",&t);
    for(int i=1;i<=t;i++)
        solve();
    return 0;
}