#include<bits/stdc++.h>
using namespace std;

const int nmax=20,MX=4e5+42;

int n;
struct info
{
    string line;
    int sum;
    int low;

    map<int, vector<int> > seen;

    int CNT[2*MX];
};

info inp[nmax];

int dp[1<<nmax];

int rec(int sum_plus,int mask)
{
    if(mask==0)return 0;

    if(dp[mask]!=-1)return dp[mask];

    int ret=0;
    for(int i=0;i<n;i++)
        if((mask&(1<<i)))
        {
            if(sum_plus+inp[i].low>=0)
            {
                int from=-sum_plus;
                int take=inp[i].CNT[from+MX];

                ret=max(ret,rec(sum_plus+inp[i].sum,mask-(1<<i))+take);
            }
            else//sum_plus+inp[i].low<0
            {
                int from=-sum_plus-1;
                int up_to=inp[i].seen[from][0];

                int take=lower_bound(inp[i].seen[-sum_plus].begin(),inp[i].seen[-sum_plus].end(),up_to)-inp[i].seen[-sum_plus].begin();
                ret=max(ret,take);
            }
        }

    dp[mask]=ret;
    return ret;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>inp[i].line;

        int pos=0;

        for(auto k:inp[i].line)
        {
            if(k=='(')inp[i].sum++;
            else inp[i].sum--;

            inp[i].low=min(inp[i].low,inp[i].sum);

            inp[i].seen[inp[i].sum].push_back(pos++);

            inp[i].CNT[inp[i].sum+MX]++;
        }
    }

    cout<<rec(0,(1<<n)-1)<<endl;
    return 0;
}