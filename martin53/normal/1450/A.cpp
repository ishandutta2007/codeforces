#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;
int n;
char inp[nmax];

void solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)cin>>inp[i];

    sort(inp+1,inp+n+1);

    for(int i=1;i<=n;i++)printf("%c",inp[i]);printf("\n");
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