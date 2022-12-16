#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

long long cnt(vector<int> given)
{
    sort(given.begin(),given.end());

    int n=given.size();

    if(n%2==1)return 1;
    return given[n/2]-given[n/2-1]+1;
}

long long solve()
{
    int n;
    scanf("%i",&n);

    vector< int > seen[2]={{},{}};

    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%i%i",&x,&y);
        seen[0].push_back(x);
        seen[1].push_back(y);
    }

    return cnt(seen[0])*cnt(seen[1]);
}

int main()
{
    int t;
    scanf("%i",&t);
    while(t)
    {
        t--;
        printf("%lld\n",solve());
    }

    return 0;
}