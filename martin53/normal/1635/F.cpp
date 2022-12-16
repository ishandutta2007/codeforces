#include<bits/stdc++.h>
using namespace std;

const int nmax=3e5+42;

int n,q;

pair<int,int> inp[nmax];

vector< pair<long long, int> > active[nmax];

vector< pair<int,long long> > tree[4*nmax],help;

void compress(int node)
{
    if(tree[node].size()==0)return;

    sort(tree[node].begin(),tree[node].end());

    help={};

    help.push_back(tree[node][0]);

    for(auto w:tree[node])
        if(help.back().second>w.second)help.push_back(w);

    tree[node]=help;
}

void build(int node,int l,int r)
{
    if(l==r)
    {
        for(auto w:active[l])
            tree[node].push_back({w.second,w.first});

        compress(node);

        return;
    }

    int av=(l+r)/2;

    build(node*2,l,av);
    build(node*2+1,av+1,r);

    tree[node]=tree[node*2];

    for(auto w:tree[node*2+1])
        tree[node].push_back(w);

    compress(node);
}

pair<long long, int > eval(int i,int j)
{
    return {1LL*(inp[j].first-inp[i].first)*(inp[i].second+inp[j].second),j};
}

stack<int> st;

void prec()
{
    st.push(1);

    for(int i=2;i<=n;i++)
    {
        while(st.size()&&inp[st.top()].second>inp[i].second)st.pop();

        if(st.size())active[st.top()].push_back(eval(st.top(),i));

        st.push(i);
    }

    while(st.size())st.pop();

    st.push(n);

    for(int i=n-1;i>=1;i--)
    {
        while(st.size()&&inp[st.top()].second>inp[i].second)st.pop();

        if(st.size())active[i].push_back(eval(i,st.top()));

        st.push(i);
    }

    build(1,1,n);
}

long long output;

int r_barrier;

void query(int node,int l,int r,int lq,int rq)
{
    if(l==lq&&r==rq)
    {
        int pos=upper_bound(tree[node].begin(),tree[node].end(),make_pair(r_barrier+1,-1LL))-tree[node].begin();
        pos--;

        if(pos>=0)output=min(output,tree[node][pos].second);
        return;
    }

    int av=(l+r)/2;

    if(lq<=av)query(node*2,l,av,lq,min(av,rq));
    if(av<rq)query(node*2+1,av+1,r,max(av+1,lq),rq);
}

int main()
{
    scanf("%i%i",&n,&q);

    for(int i=1;i<=n;i++)scanf("%i%i",&inp[i].first,&inp[i].second);

    prec();

    for(int i=1;i<=q;i++)
    {
        int l,r;
        scanf("%i%i",&l,&r);

        output=5e18;

        r_barrier=r;

        query(1,1,n,l,r);

        printf("%lld\n",output);
    }

    return 0;
}