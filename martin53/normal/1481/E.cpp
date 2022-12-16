#include<bits/stdc++.h>
using namespace std;

const int nmax=5e5+42;

int n,inp[nmax],dp[nmax];

map<int, vector<int> > seen;

int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<=n;i++)
    {
        seen[inp[i]].push_back(i);
    }

    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1];

        if(seen[inp[i]].back()==i)
        {
            int cur=seen[inp[i]].size();

            cur=cur+dp[seen[inp[i]][0]-1];

            dp[i]=max(dp[i],cur);
        }

        //cout<<i<<" -> "<<dp[i]<<endl;
    }

    int outp=dp[n];

    for(auto w:seen)
    {
        for(int i=0;i<w.second.size();i++)
        {
            int pos=w.second[i];

            int cur=dp[pos-1]+w.second.size()-i;

            outp=max(outp,cur);
        }
    }

    printf("%i\n",n-outp);

    return 0;
}