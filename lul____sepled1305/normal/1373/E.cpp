/**I love Ithea.**/
#include<bits/stdc++.h>
using namespace std;
const int N = 5e7+10;
int T,i,j;
int precal[N];
long long dp[200];
map<int, long long> mp;
vector<int> v;

void makedp(int node)
{
    int i, cur;
    long long mini = 1e18;
    for(i=0;i<9;i++)
    {
        cur = 2*i+1;
        if(node-cur>=0 && (node-cur)%2==0 && mp.count((node-cur)/2))
        {
            mini = min(mini,mp[(node-cur)/2]*10+i);
        }
    }
    cur = 9;
    if(node-cur>=0 && dp[node-cur]!=-1)
    {
        mini = min(dp[node-cur]*10+9,mini);
    }
    if(mini == 1e18)
        dp[node] = -1;
    else
        dp[node] = mini;
}

int main()
{
    /**ios_base::sync_with_stdio(false);
    cin.tie(NULL);**/

    for(i=0;i<N;i++)
    {
        int cur = i;
        while(cur!=0)
        {
            precal[i]+=cur%10;
            cur/=10;
        }
    }

    for(i=0;i<=9;i++)
        mp.insert({i,i});

    long long cur = 10;
    for(i=1;i<=17;i++)
    {
        for(j=1;j<=9;j++)
        {
            mp.insert({9*i+j,(j+1)*cur-1});
        }
        cur*=10;
    }

    for(i=0;i<200;i++)
        dp[i]=-1;

    for(i=0;i<200;i++)
    {
        if(dp[i]==-1)
            makedp(i);
    }

    cin>>T;
    while(T--)
    {
        int n,k;
        cin>>n>>k;
        if(k==0)
        {
            while(n>9)
                n-=9,v.push_back(9);
            v.push_back(n);
            while(!v.empty())
            {
                cout<<v.back();
                v.pop_back();
            }
            cout<<"\n";
        }
        else if(k>=2)
        {
            int cur = 0;
            for(i=0;i<=k;i++)
                cur+=precal[i];
            bool pass = false;
            for(i=0;i<1e6;i++)
            {
                if(cur==n)
                {
                    pass = true;
                    cout<<i<<"\n";
                    break;
                }
                else
                {
                    cur+=precal[i+k+1];
                    cur-=precal[i];
                }
            }
            if(!pass)
                cout<<"-1\n";
        }
        else if(k==1)
        {
            cout<<dp[n]<<"\n";
        }
    }

    return 0;
}