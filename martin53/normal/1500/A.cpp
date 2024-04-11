#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42,MX=5e6+42;

vector< pair<int,int> > seen[MX];

int n;

int inp[nmax];

void push(int i,int j)
{
    for(auto w:seen[inp[i]+inp[j]])
    {
        if(w.first!=i&&w.second!=i&&w.first!=j&&w.second!=j)
        {
            printf("YES\n");

            printf("%i %i %i %i\n",w.first,w.second,i,j);

            exit(0);
        }
    }

    seen[inp[i]+inp[j]].push_back({i,j});
}
int main()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);
    }

    for(int i=2;i<=n;i++)
        for(int j=1;j<i;j++)
            push(i,j);

    printf("NO\n");

    return 0;
}