#include<bits/stdc++.h>
using namespace std;

const int nmax=4e5+42;

int n;

pair<int,int> inp[nmax];//a, c

long long dp[nmax];

long long tree[2][4*nmax];

void update(int where,int node,int l,int r,int pos,long long new_state)
{
    if(l==r)
    {
        tree[where][node]=new_state;
        return;
    }

    int av=(l+r)/2;

    if(pos<=av)update(where,node*2,l,av,pos,new_state);
    else update(where,node*2+1,av+1,r,pos,new_state);

    tree[where][node]=min(tree[where][node*2],tree[where][node*2+1]);
}

long long query(int where,int node,int l,int r,int lq,int rq)
{
    if(l==lq&&r==rq)return tree[where][node];

    int av=(l+r)/2;

    long long ret=1e18;

    if(lq<=av)ret=min(ret,query(where,node*2,l,av,lq,min(av,rq)));
    if(av<rq)ret=min(ret,query(where,node*2+1,av+1,r,max(av+1,lq),rq));

    return ret;
}

long long qr(int where,int l,int r)
{
    if(l>r)return 1e18;

    return query(where,1,1,n,l,r);
}
long long eval()
{
    dp[n]=0;

    for(int i=n;i>=0;i--)
    {
        int ok=i,not_ok=n+1;

        while(not_ok-ok>1)
        {
            int av=(ok+not_ok)/2;

            if(inp[i].second>=inp[av].first-inp[i].first)ok=av;
            else not_ok=av;
        }

        //cout<<"i= "<<i<<" ok= "<<ok<<endl;

        dp[i]=1e18;

        dp[i]=min(dp[i],qr(0,i+1,ok));

        dp[i]=min(dp[i],qr(1,ok+1,n)-inp[i].first-inp[i].second);

        if(i==n)dp[i]=0;

        update(0,1,1,n,i,dp[i]);
        update(1,1,1,n,i,dp[i]+inp[i].first);

        /*
        cout<<i<<" -> "<<dp[i]<<endl;
        cout<<"---"<<endl;
        */
    }

    return dp[1];
}

int main()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)scanf("%i%i",&inp[i].first,&inp[i].second);

    sort(inp+1,inp+n+1);

    long long outp=0;
    for(int i=1;i<=n;i++)outp+=inp[i].second;

    outp+=eval();

    printf("%lld\n",outp);

    return 0;
}