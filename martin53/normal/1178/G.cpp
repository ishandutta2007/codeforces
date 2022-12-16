#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42,BLOCK=sqrt(nmax/log(nmax));

int n,q;

int order[nmax],in[nmax],out[nmax];

vector<int> adj[nmax];
int parent[nmax];

int sum_a[nmax],sum_b[nmax];

int mem_a[nmax],mem_b[nmax];

int t;

void dfs(int node)
{
    t++;
    in[node]=t;

    sum_a[t]=mem_a[node];
    sum_b[t]=mem_b[node];

    sum_a[t]+=sum_a[in[parent[node]]];
    sum_b[t]+=sum_b[in[parent[node]]];

    for(auto k:adj[node])
        dfs(k);

    out[node]=t;
}

pair<int/*a*/,long long/*b*/> lines[nmax/BLOCK+42][BLOCK+42];
int pointer[nmax];

int to_push[nmax],when_to_rebuild[nmax];

pair<long long,pair<long long,long long> > meet(pair<int,long long> a,pair<int,long long> b)
{
    long long high=(b.second-a.second),low=(a.first-b.first);

    return {high/low,{high%low,low}};
}
bool check(pair<int,long long> prv,pair<int,long long> test,pair<int,long long> k)
{
    pair<long long,pair<long long,long long> > le=meet(prv,k),ri=meet(test,k);
    //check if le>=ri

    if(le.first!=ri.first)return le.first>ri.first;

    return le.second.first*ri.second.second>=le.second.second*ri.second.first;
}
void compress(int which)
{
    sort(lines[which],lines[which]+pointer[which]);

    int help_pointer=0;

    for(int i=0;i<pointer[which];i++)
    {
        pair<int/*a*/,long long/*b*/> k=lines[which][i];

        while(help_pointer>=1&&lines[which][help_pointer-1].second<=k.second)help_pointer--;

        while(help_pointer>=2&&check(lines[which][help_pointer-2],lines[which][help_pointer-1],k))help_pointer--;

        lines[which][help_pointer]=k;
        help_pointer++;
    }

    pointer[which]=help_pointer;
}

int mem_pointer[nmax];

void rebuild(int which)
{
    for(int i=which*BLOCK;i<(which+1)*BLOCK;i++)
        sum_a[i]+=to_push[which];

    to_push[which]=0;

    when_to_rebuild[which]=2e9;
    pointer[which]=0;

    for(int i=which*BLOCK;i<(which+1)*BLOCK;i++)
        if(sum_a[i]>=0)lines[which][pointer[which]++]={sum_b[i],1LL*sum_a[i]*sum_b[i]};
        else
        {
            lines[which][pointer[which]++]={-sum_b[i],1LL*(-sum_a[i])*sum_b[i]};
            when_to_rebuild[which]=min(when_to_rebuild[which],-sum_a[i]);
        }
    compress(which);

    mem_pointer[which]=0;
}
void slow(int l,int r,int val)
{
    for(int j=l;j<=r;j++)
        sum_a[j]+=val;
}
void upd(int which,int val)
{
    to_push[which]+=val;

    if(to_push[which]>=when_to_rebuild[which])rebuild(which);
}
void update(int l,int r,int val)
{
    int from=l/BLOCK,to=r/BLOCK;

    if(from==to)
    {
        slow(l,r,val);

        rebuild(from);
        return;
    }

    slow(l,from*BLOCK+BLOCK-1,val);
    slow(to*BLOCK,r,val);

    rebuild(from);
    rebuild(to);

    for(int j=from+1;j<to;j++)
        upd(j,val);
}

long long slow_query(int l,int r)
{
    //cout<<"slow query "<<l<<" "<<r<<endl;

    long long outp=0;

    for(int j=l;j<=r;j++)
        outp=max(outp,1LL*abs(sum_a[j])*abs(sum_b[j]));

    return outp;
}

long long eval(long long x,pair<int,long long> line)
{
    return x*line.first+line.second;
}
long long query(int l,int r)
{
    int from=l/BLOCK,to=r/BLOCK;

    long long outp=0;

    if(from==to)
    {
        rebuild(from);

        outp=max(outp,slow_query(l,r));
        return outp;
    }

    rebuild(from);
    rebuild(to);

    outp=max(outp,slow_query(l,from*BLOCK+BLOCK-1));
    outp=max(outp,slow_query(to*BLOCK,r));

    for(int j=from+1;j<to;j++)
    {
        while(mem_pointer[j]+1<pointer[j]&&eval(to_push[j],lines[j][mem_pointer[j]])<=eval(to_push[j],lines[j][mem_pointer[j]+1]))mem_pointer[j]++;

        outp=max(outp,eval(to_push[j],lines[j][mem_pointer[j]]));

        /*
        for(int i=0;i<pointer[j];i++)
        {
            pair<int,long long> w=lines[j][i];

            outp=max(outp,1LL*w.first*to_push[j]+w.second);

            //cout<<j<<" -> "<<w.first<<" "<<to_push[j]<<" "<<w.second<<endl;
            //assert(1LL*w.first*to_push[j]+w.second>=0);
        }
        */
    }

    return outp;
}

mt19937 rng(42);
int main()
{
    scanf("%i%i",&n,&q);
    /*
    n=2e5;
    q=1e4;
    */

    for(int i=2;i<=n;i++)
    {
        scanf("%i",&parent[i]);

        //parent[i]=rng()%(i-1)+1;

        adj[parent[i]].push_back(i);
    }

    for(int i=1;i<=n;i++)scanf("%i",&mem_a[i]);
        //mem_a[i]=rng()%100-rng()%100;

    for(int i=1;i<=n;i++)scanf("%i",&mem_b[i]);
        //mem_b[i]=rng()%100-rng()%100;

    dfs(1);

    for(int i=1;i<=n;i++)sum_b[i]=abs(sum_b[i]);

    int from=1/BLOCK,to=n/BLOCK;

    for(int i=from;i<=to;i++)
        rebuild(i);

    /*
    for(int i=0;i<=n/BLOCK;i++)
        cout<<i<<" -> "<<pointer[i]<<endl;
    */

    for(int i=1;i<=q;i++)
    {
        int type;

        scanf("%i",&type);
        //type=2;

        if(type==1)
        {
            int node,val;
            scanf("%i%i",&node,&val);

            update(in[node],out[node],val);
        }
        else
        {
            int node;

            scanf("%i",&node);

            //node=1;

            long long outp=query(in[node],out[node]);

            printf("%lld\n",outp);
        }
        /*
        for(int j=1;j<=n;j++)
            cout<<j<<" -> "<<sum_a[j]<<" "<<sum_b[j]<<endl;
        */
    }
    return 0;
}