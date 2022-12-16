#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42,mod=1e9+7,off=1<<17;

long long my_pow(long long a,long long b)
{
    long long ret=1;

    while(b)
    {
        if(b%2)ret=ret*a%mod;
        b=b/2;
        a=a*a%mod;
    }
    return ret;
}
long long inv(long long a)
{
    return my_pow(a,mod-2);
}
int n,q;
int inp[nmax];

vector< int > primes;

int tree[100][(1<<18)+42];
int mem[nmax];

void build(int id,int node,int l,int r)
{
    for(int i=1;i<=n;i++)
        tree[id][i+off-1]=mem[i];

    for(int i=off-1;i>=0;i--)
        tree[id][i]=max(tree[id][2*i],tree[id][2*i+1]);
}
int query(int id,int node,int l,int r,int lq,int rq)
{
    //cout<<id<<" "<<lq<<" "<<rq<<" -> ";

    lq=lq+off-1;
    rq=rq+off-1;

    int ret=0;

    while(lq<=rq)
    {
        ret=max(ret,tree[id][lq]);
        lq=(lq+1)/2;

        ret=max(ret,tree[id][rq]);
        rq=(rq-1)/2;
    }

    //cout<<ret<<endl;

    return ret;
}

int help[nmax];

pair<int/*prv*/,int/*id*/> seen[nmax];

vector< int/*id*/ > merge_tree[nmax*4];
vector< int > pref[nmax*4];//product of tree prefix

void build_merge(int node,int l,int r)
{
    if(l==r)
    {
        merge_tree[node].push_back(seen[l].second);
        pref[node].push_back(help[seen[l].second]);

        return;
    }

    int av=(l+r)/2;

    build_merge(node*2,l,av);
    build_merge(node*2+1,av+1,r);

    merge_tree[node]=merge_tree[node*2];

    for(auto k:merge_tree[node*2+1])merge_tree[node].push_back(k);

    sort(merge_tree[node].begin(),merge_tree[node].end());

    long long cur=1;

    for(auto k:merge_tree[node])
    {
        cur=cur*help[k]%mod;
        pref[node].push_back(cur);
    }

}

int query_merge(int node,int l,int r,int lq,int rq,int lower,int upper)
{
    if(l==lq&&r==rq)
    {
        int lst_valid=upper_bound(merge_tree[node].begin(),merge_tree[node].end(),upper)-merge_tree[node].begin();
        lst_valid--;

        int frst_valid=lower_bound(merge_tree[node].begin(),merge_tree[node].end(),lower)-merge_tree[node].begin();

        //cout<<"found "<<frst_valid<<" "<<lst_valid<<endl;

        if(frst_valid>lst_valid)return 1;

        long long ret=pref[node][lst_valid];

        if(frst_valid)ret=ret*inv(pref[node][frst_valid-1])%mod;

        return ret;
    }

    int av=(l+r)/2;

    long long ret=1;

    if(lq<=av)ret=ret*query_merge(node*2,l,av,lq,min(av,rq),lower,upper)%mod;
    if(av<rq)ret=ret*query_merge(node*2+1,av+1,r,max(av+1,lq),rq,lower,upper)%mod;

    return ret;
}
int ask_query(int l,int r)
{
    //cout<<"l= "<<l<<" r= "<<r<<endl;

    long long ret=1;

    for(int i=0;i<primes.size();i++)
    {
        int cur=query(i,1,1,n,l,r);

        //cout<<i<<" -> "<<primes[i]<<" "<<cur<<endl;

        for(int t=1;t<=cur;t++)
            ret=ret*primes[i]%mod;
    }

    int to=lower_bound(seen+1,seen+n+1,make_pair(l,0))-seen;
    to--;

    if(to==0)return ret;

    //cout<<"query "<<query_merge(1,1,n,1,to)<<" "<<ret<<endl;

    ret=ret*query_merge(1,1,n,1,to,l,r)%mod;

    return ret;
}
int main()
{
    for(int i=2;i*i<nmax;i++)
    {
        bool ok=1;

        for(int j=2;j*j<=i&&ok;j++)
            if(i%j==0)ok=0;

        if(ok)primes.push_back(i);
    }

    scanf("%i",&n);

    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);
    }


    for(int j=0;j<primes.size();j++)
    {
        for(int i=1;i<=n;i++)
        {
            int deg=0;

            while(inp[i]%primes[j]==0)
            {
                inp[i]=inp[i]/primes[j];
                deg++;
            }
            //if(deg)cout<<i<<" "<<primes[j]<<" -> "<<deg<<endl;

            mem[i]=deg;
            //if(deg)cout<<i<<" -> "<<mem[i]<<endl;
        }

        build(j,1,1,n);
    }

    for(int i=1;i<=n;i++)help[i]=inp[i];

    //cout<<"help: ";for(int i=1;i<=n;i++)cout<<help[i]<<" ";cout<<endl;

    scanf("%i",&q);

    map<int,int> prv={};
    for(int i=1;i<=n;i++)
    {
        seen[i]={prv[help[i]],i};
        prv[help[i]]=i;
    }

    sort(seen+1,seen+n+1);

    //cout<<"prv: ";for(int i=1;i<=n;i++)cout<<seen[i].first<<" "<<seen[i].second<<"\t";cout<<endl;

    build_merge(1,1,n);

    int last=0,x,y;

    for(int i=1;i<=q;i++)
    {
        scanf("%i%i",&x,&y);

        int l=(x+last)%n+1;
        int r=(y+last)%n+1;

        if(l>r)swap(l,r);

        //cout<<"l= "<<l<<" r= "<<r<<endl;

        last=ask_query(l,r);

        printf("%i\n",last);
    }
    return 0;
}