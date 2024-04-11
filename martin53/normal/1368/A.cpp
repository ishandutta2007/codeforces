#include<bits/stdc++.h>
using namespace std;

void solve()
{
    long long a,b,n;
    scanf("%lld%lld%lld",&a,&b,&n);

    if(a>b)swap(a,b);

    int steps=0;

    while(b<=n)
    {
        a=a+b;
        swap(a,b);
        steps++;
    }

    printf("%i\n",steps);
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