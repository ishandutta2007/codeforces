#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int n,inp[nmax];

long long outp[nmax];

void print(bool type)
{
    if(type==0)printf("NO\n");
    else
    {
        printf("YES\n");

        for(int i=1;i<=n;i++)
            printf("%lld ",outp[i]);
    }
    exit(0);
}
int main()
{
    scanf("%i",&n);

    bool only_zero=1,diff=0;

    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);

        if(inp[i])only_zero=0;

        if(inp[i]!=inp[1])diff=1;
    }

    inp[0]=inp[n];

    if(only_zero)
    {
        for(int i=1;i<=n;i++)outp[i]=1;

        print(1);
    }

    if(diff==0)print(0);

    int mx=0;

    for(int i=1;i<=n;i++)
        mx=max(mx,inp[i]);

    int id=-1;
    for(int i=1;i<=n;i++)
        if(inp[i-1]!=mx&&inp[i]==mx)id=i;

    outp[id]=mx*20;
    for(int  i=id-1;i>=1;i--)outp[i]=outp[i+1]+inp[i];

    outp[n+1]=outp[1];

    for(int i=n;i>id;i--)outp[i]=outp[i+1]+inp[i];

    outp[id]=mx;

    print(1);

    return 0;
}