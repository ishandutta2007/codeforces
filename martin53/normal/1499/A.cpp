#include<bits/stdc++.h>
using namespace std;

bool can(int k1,int k2,int w)
{
    int ret=k1/2+k2/2;

    if(k1%2&&k2%2)ret++;

    return ret>=w;
}
void solve()
{
    int n,k1,k2;
    int w,b;

    scanf("%i%i%i%i%i",&n,&k1,&k2,&w,&b);

    if(can(k1,k2,w)&&can(n-k1,n-k2,b))printf("YES\n");
    else printf("NO\n");
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        solve();
    }

    return 0;
}