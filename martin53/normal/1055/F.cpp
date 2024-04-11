#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n;
long long k;

vector< pair<int,long long> > adj[nmax];

long long mem[nmax];

void dfs(int node,long long cur)
{
    mem[node]=cur;

    for(auto k:adj[node])
        dfs(k.first,k.second^cur);
}

mt19937 rng(42);

struct info
{
    int LHS,RHS,lq,rq;
};

vector<info> active,help;

void make_info(int LHS,int RHS,int lq,int rq)
{
    if(LHS>RHS||lq>rq)return;

    info cur;

    cur.LHS=LHS;
    cur.RHS=RHS;
    cur.lq=lq;
    cur.rq=rq;

    help.push_back(cur);
}
int main()
{
    scanf("%i%lld",&n,&k);
    /*
    n=1e6;
    k=1LL*n*n;
    */
    for(int i=2;i<=n;i++)
    {
        int par;
        long long cost;

        scanf("%i%lld",&par,&cost);
        /*
        par=rng()%(i-1)+1;
        cost=rng()%(1<<20);
        */
        adj[par].push_back({i,cost});
    }

    dfs(1,0);

    sort(mem+1,mem+n+1);

    make_info(1,n,1,n);
    active=help;
    help={};

    long long outp=0;

    for(int bit=62;bit>=0;bit--)
    {
        int type=0;

        long long cnt=0;

        help={};

        for(auto k:active)
        {
            int lq=k.lq,rq=k.rq,LHS=k.LHS,RHS=k.RHS;

            int bound_zero_LHS=LHS;
            while(((1LL<<bit)&mem[bound_zero_LHS])==0&&bound_zero_LHS<=RHS)bound_zero_LHS++;
            bound_zero_LHS--;

            int bound_zero_lq=lq;
            while(((1LL<<bit)&mem[bound_zero_lq])==0&&bound_zero_lq<=rq)bound_zero_lq++;
            bound_zero_lq--;

            cnt+=1LL*(bound_zero_LHS-LHS+1)*(bound_zero_lq-lq+1);
            cnt+=1LL*(RHS-bound_zero_LHS)*(rq-bound_zero_lq);
        }

        if(cnt>=k)type=0;
        else
        {
            k=k-cnt;
            type=1;
            outp+=(1LL<<bit);
        }

        for(auto k:active)
        {
            int lq=k.lq,rq=k.rq,LHS=k.LHS,RHS=k.RHS;

            int bound_zero_LHS=LHS;
            while(((1LL<<bit)&mem[bound_zero_LHS])==0&&bound_zero_LHS<=RHS)bound_zero_LHS++;
            bound_zero_LHS--;

            int bound_zero_lq=lq;
            while(((1LL<<bit)&mem[bound_zero_lq])==0&&bound_zero_lq<=rq)bound_zero_lq++;
            bound_zero_lq--;

            if(type==0)
            {
                make_info(LHS,bound_zero_LHS,lq,bound_zero_lq);
                make_info(bound_zero_LHS+1,RHS,bound_zero_lq+1,rq);
            }
            else
            {
                make_info(bound_zero_LHS+1,RHS,lq,bound_zero_lq);
                make_info(LHS,bound_zero_LHS,bound_zero_lq+1,rq);
            }
        }

        active=help;
    }
    printf("%lld\n",outp);
    return 0;
}