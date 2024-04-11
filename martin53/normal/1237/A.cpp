#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n,inp[nmax];
int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    int now=1;

    for(int i=1;i<=n;i++)
        if(inp[i]%2==0)inp[i]=inp[i]/2;
        else
        {
            inp[i]=(inp[i]+now)/2;
            now=-now;
        }

    for(int i=1;i<=n;i++)printf("%i ",inp[i]);

    return 0;
}