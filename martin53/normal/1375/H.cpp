#include<bits/stdc++.h>
using namespace std;

const int nmax=(1<<12)+42,MX=2.2e6;

int inp[nmax],where[nmax];

vector<int> tree[nmax*4];

void build(int node,int l,int r)
{
    for(int i=l;i<=r;i++)
        tree[node].push_back(where[i]);

    /*sorted ids of numbers between l and r*/

    sort(tree[node].begin(),tree[node].end());

    if(l==r)return;

    int av=(l+r)/2;

    build(node*2,l,av);
    build(node*2+1,av+1,r);
}

pair<int,int> outp[MX];
int pointer;

map< pair<int,int>,int > mem[nmax*4];

int query(int node,int lq,int rq)
{
    int le=lower_bound(tree[node].begin(),tree[node].end(),lq)-tree[node].begin();
    int ri=upper_bound(tree[node].begin(),tree[node].end(),rq)-tree[node].begin()-1;

    if(le>ri)return 0;
    if(le==ri)return tree[node][le];

    if(mem[node].count({le,ri}))return mem[node][{le,ri}];

    int mem_lhs=query(node*2,lq,rq);
    int mem_rhs=query(node*2+1,lq,rq);

    if(mem_lhs==0)return mem_rhs;
    if(mem_rhs==0)return mem_lhs;

    pointer++;
    outp[pointer]={mem_lhs,mem_rhs};

    mem[node][{le,ri}]=pointer;
    return pointer;
}

int query_id[MX];
int main()
{
    int n,q;

    scanf("%i%i",&n,&q);

    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);
        where[inp[i]]=i;
    }

    build(1,1,n);

    pointer=n;

    for(int i=1;i<=q;i++)
    {
        int l,r;

        scanf("%i%i",&l,&r);

        query_id[i]=query(1,l,r);
    }

    printf("%i\n",pointer);
    for(int i=n+1;i<=pointer;i++)
        printf("%i %i\n",outp[i].first,outp[i].second);

    for(int i=1;i<=q;i++)printf("%i\n",query_id[i]);

    return 0;
}