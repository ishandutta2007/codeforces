#include<bits/stdc++.h>
using namespace std;

const int nmax=1e3+42;

int n,k;

pair<int,int> inp[nmax];

bool side(pair<int,int> a,int b)
{
    return a.first<=b&&b<=a.second;
}
bool meet(pair<int,int> a,pair<int,int> b)
{
    if(a.first>a.second)swap(a.first,a.second);
    if(b.first>b.second)swap(b.first,b.second);

    return side(a,b.first)!=side(a,b.second)&&side(b,a.first)!=side(b,a.second);
}
int solve()
{
    scanf("%i%i",&n,&k);

    set<int> on={};

    for(int i=1;i<=k;i++)
    {
        scanf("%i%i",&inp[i].first,&inp[i].second);
        on.insert(inp[i].first);
        on.insert(inp[i].second);
    }

    vector<int> other={};

    for(int i=1;i<=2*n;i++)
    {
        if(on.count(i)==0)other.push_back(i);
    }

    for(int i=k+1;i<=n;i++)
    {
        inp[i]={other[i-(k+1)],other[i-(k+1)+(n-k)]};
    }

    int outp=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(meet(inp[i],inp[j]))outp++;

    return outp;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        printf("%i\n",solve());
    }

    return 0;
}