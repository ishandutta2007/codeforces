#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];
int a[nmax];

vector< pair<int,int> > seen;

int in[nmax],wrong;

bool is_wrong(int pos)
{
    if(in[pos]==0)return 1;
    return 0;
}

void solve()
{
    for(int i=1;i<=6;i++)scanf("%i",&a[i]);

    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    wrong=n;

    sort(a+1,a+6+1);
    sort(inp+1,inp+n+1);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=6;j++)
            seen.push_back({inp[i]-a[j],i});

    sort(seen.begin(),seen.end());

    int outp=1e9,pointer=0;

    for(int i=0;i<seen.size();i++)
    {
        wrong=wrong-is_wrong(seen[i].second);

        in[seen[i].second]++;

        wrong=wrong+is_wrong(seen[i].second);

        while(wrong==0)
        {
            outp=min(outp,seen[i].first-seen[pointer].first);

            wrong=wrong-is_wrong(seen[pointer].second);

            in[seen[pointer].second]--;

            wrong=wrong+is_wrong(seen[pointer].second);

            pointer++;
        }

    }

    printf("%i\n",outp);
}

int main()
{
    int t=1;

    while(t)
    {
        t--;
        solve();
    }
    return 0;
}