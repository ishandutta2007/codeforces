#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

vector<int> seen[nmax];
vector<long long> pref[nmax];

long long outp[nmax];

int u[nmax],s[nmax];
int n;

bool cmp(int a,int b)
{
    return a>b;
}
void solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)
    {
        outp[i]=0;
        seen[i]={};
        outp[i]={};
    }

    for(int i=1;i<=n;i++)scanf("%i",&u[i]);
    for(int i=1;i<=n;i++)scanf("%i",&s[i]);

    for(int i=1;i<=n;i++)
    {
        seen[u[i]].push_back(s[i]);
    }

    for(int i=1;i<=n;i++)
    {
        sort(seen[i].begin(),seen[i].end(),cmp);

        vector<long long> pref={};

        long long sum=0;
        for(auto w:seen[i])
        {
            sum+=w;
            pref.push_back(sum);
        }

        for(int j=1;j<=seen[i].size();j++)
        {
            int use=seen[i].size()/j*j;

            outp[j]+=pref[use-1];
        }
    }

    for(int i=1;i<=n;i++)printf("%lld ",outp[i]);printf("\n");
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