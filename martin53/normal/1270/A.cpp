#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n,k1,k2,le[nmax],ri[nmax];
void solve()
{
    scanf("%i%i%i",&n,&k1,&k2);
    for(int i=1;i<=k1;i++)scanf("%i",&le[i]);
    for(int i=1;i<=k2;i++)scanf("%i",&ri[i]);

    int mx=0;
    for(int i=1;i<=k1;i++)mx=max(mx,le[i]);

    int other=0;
    for(int i=1;i<=k2;i++)other=max(other,ri[i]);

    if(mx<other)printf("NO\n");
    else printf("YES\n");
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