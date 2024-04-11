#include<bits/stdc++.h>
using namespace std;

map<int, vector<int> > seen;

int eval(int cur,int md)
{
    int ret=0;

    for(auto w:seen[cur])
        if(w%2==md)ret++,md=!md;

    return ret;
}

void solve()
{
    seen={};

    int n;
    scanf("%i",&n);

    for(int i=1;i<=n;i++)
    {
        int cur;
        scanf("%i",&cur);

        seen[cur].push_back(i);
    }

    for(int i=1;i<=n;i++)
        printf("%i ",max(eval(i,0),eval(i,1)));

    printf("\n");
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