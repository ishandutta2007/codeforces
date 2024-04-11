#include<bits/stdc++.h>
using namespace std;

const int nmax=35000+42;

int n,k,inp[nmax];

deque<int> seen[nmax];
int l=1,r=0;
long long cost_now=0;

void extend(int lq,int rq)
{
    while(l>lq)
    {
        l--;

        if(seen[inp[l]].size())cost_now=cost_now+seen[inp[l]][0]-l;

        seen[inp[l]].push_front(l);
    }

    while(r<rq)
    {
        r++;

        if(seen[inp[r]].size())cost_now=cost_now-seen[inp[r]].back()+r;

        seen[inp[r]].push_back(r);
    }

    while(l<lq)
    {
        if(seen[inp[l]].size()>1)cost_now=cost_now+seen[inp[l]][0]-seen[inp[l]][1];

        seen[inp[l]].pop_front();

        l++;
    }

    while(r>rq)
    {
        if(seen[inp[r]].size()>1)cost_now=cost_now-seen[inp[r]].back()+seen[inp[r]][seen[inp[r]].size()-2];

        seen[inp[r]].pop_back();

        r--;
    }

}
int dp[nmax];

int help[nmax];


void dc(int ans_l,int ans_r,int lhs,int rhs)
{
    if(rhs<lhs)return;

    int av=(lhs+rhs)/2;

    int ans_av=-1;

    for(int i=ans_l;i<=ans_r&&i<=av;i++)
    {
        extend(i,av);

        long long cur=dp[i-1]+cost_now;

        if(help[av]>cur)
        {
            help[av]=cur;
            ans_av=i;
        }
    }

    dc(ans_l,ans_av,lhs,av-1);
    dc(ans_av,ans_r,av+1,rhs);
}
void solve()
{
    for(int i=1;i<=n;i++)seen[i]={};

    l=1;
    r=0;
    cost_now=0;

    for(int i=0;i<=n;i++)help[i]=1e9;

    dc(1,n,1,n);

    for(int i=0;i<=n;i++)dp[i]=help[i];
}

int main()
{
    scanf("%i%i",&n,&k);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<=n;i++)dp[i]=1e9;
    dp[0]=0;

    for(int j=1;j<=k;j++)
        solve();

    printf("%i\n",dp[n]);

    return 0;
}