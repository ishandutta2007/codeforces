#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42,kmax=320;

int n,m,q;
int left_end[nmax];

int query(int at_least,int up_to,int covered_to_now,int start_from)
{
    for(int i=start_from;i<=up_to;i++)
    {
        if(left_end[i]>=at_least&&left_end[i]<=covered_to_now)covered_to_now=max(covered_to_now,i);
    }
    return covered_to_now;
}

int max_covered[nmax][kmax];

int BLOCK_SIZE;

vector<int> adj[nmax];

int dp[nmax];

stack<int> active,idle;
int bck(int low,int high)
{
    active=idle;
    //if u<v and dp[u]>=dp[v], v is useless
    for(int i=high;i>=low;i--)
    {
        int mx_possible=0;
        for(auto k:adj[i])
            if(k<=high)mx_possible=max(mx_possible,k);

        dp[i]=i;
        int now=i;
        while(active.size()&&active.top()<=mx_possible)
        {
            now=active.top();
            active.pop();
        }
        dp[i]=dp[now];
        active.push(i);
        //cout<<i<<" -> "<<mx_possible<<" "<<now<<endl;
    }

    return dp[low];
}
int main()
{
    scanf("%i%i",&n,&m);

    int l,r;
    for(int i=1;i<=m;i++)
    {
        scanf("%i%i",&l,&r);
        left_end[r]=l;
        adj[l].push_back(r);
    }

    BLOCK_SIZE=sqrt(n);

    for(int i=1;i*BLOCK_SIZE<=n;i++)
    {
        //cout<<i<<" "<<i*BLOCK_SIZE<<endl;
        bck(1,i*BLOCK_SIZE);
        //for(int j=1;j<=n;j++)cout<<dp[j]<<" ";cout<<endl;

        for(int j=1;j<=i*BLOCK_SIZE;j++)
            max_covered[j][i]=dp[j];
    }

    scanf("%i",&q);

    for(int i=1;i<=q;i++)
    {
        scanf("%i%i",&l,&r);

        int start_from=r/BLOCK_SIZE*BLOCK_SIZE+1;
        if(start_from<=l)printf("%i\n",query(l,r,l,l));
        else
        {
            int known=max_covered[l][r/BLOCK_SIZE];
            printf("%i\n",query(l,r,known,start_from));
        }
    }
    return 0;
}