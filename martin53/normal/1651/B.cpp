#include<bits/stdc++.h>
using namespace std;

const int MX=1e9;

vector<long long> outp={};

void solve()
{
    int n;
    scanf("%i",&n);

    if(n<=outp.size())
    {
        printf("YES\n");
        for(int j=0;j<n;j++)
            printf("%lld ",outp[j]);
        printf("\n");
        return;
    }
    else printf("NO\n");
}

int main()
{
    long long num=1;

    while(num<=MX)
    {
        outp.push_back(num);
        num=num*3;
    }

    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        solve();
    }

    return 0;
}