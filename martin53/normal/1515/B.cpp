#include<bits/stdc++.h>
using namespace std;

bool sq(int val)
{
    int k=sqrt(val);

    while((k+1)*(k+1)<=val)k++;

    return k*k==val;
}
void solve()
{
    int n;
    scanf("%i",&n);

    if((n%2==0&&sq(n/2))||(n%4==0&&sq(n/4)))
    {
        printf("YES\n");
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
        t--;

        solve();
    }

    return 0;
}