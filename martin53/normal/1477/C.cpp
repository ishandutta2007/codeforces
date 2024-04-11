#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n;
pair<int,int> inp[nmax];

long long sq(long long x)
{
    return x*x;
}
long long dst(int i,int j)
{
    return sq(inp[i].first-inp[j].first)+sq(inp[i].second-inp[j].second);
}

int perm[nmax];
bool used[nmax];

int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i%i",&inp[i].first,&inp[i].second);

    int a=1,b=2;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(dst(a,b)<dst(i,j))
            {
                a=i;
                b=j;
            }

    perm[1]=a;
    perm[2]=b;

    used[a]=1;
    used[b]=1;

    int prv=b;

    for(int t=3;t<=n;t++)
    {
        int mx=-1;
        for(int j=1;j<=n;j++)
            if(used[j]==0)
            {
                if(mx==-1)mx=j;
                else if(dst(prv,j)>dst(prv,mx))mx=j;
            }
        used[mx]=1;
        perm[t]=mx;

        prv=mx;
    }

    for(int i=1;i<=n;i++)printf("%i ",perm[i]);
    printf("\n");

    return 0;
}