#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int n,q,inp[nmax];

pair<int,int> given[nmax];

int tree[4*nmax];

void update(int node,int l,int r,int lq,int rq,int val)
{
    if(l==lq&&r==rq)
    {
        tree[node]=max(tree[node],val);
        return;
    }

    int av=(l+r)/2;

    if(lq<=av)update(node*2,l,av,lq,min(av,rq),val);
    if(av<rq)update(node*2+1,av+1,r,max(av+1,lq),rq,val);
}

int query(int node,int l,int r,int pos)
{
    if(l==r)return tree[node];

    int ret=tree[node];

    int av=(l+r)/2;

    if(pos<=av)ret=max(ret,query(node*2,l,av,pos));
    else ret=max(ret,query(node*2+1,av+1,r,pos));

    return ret;
}

map<int, vector<int> > seen;

int jump[nmax];

int eval(int l)
{
    int r=l-1;

    for(int j=1;j<l;j++)
        if(jump[j])
        {
            if(jump[j]<l)return n;

            r=max(r,jump[j]);
        }

    for(int j=l;j<=n;j++)
        if(jump[j])r=max(r,j);

    //cout<<"eval "<<l<<" -> "<<r<<endl;

    return r-l+1;
}

int pref_max[nmax],suff_max[nmax];

int solve()
{
    scanf("%i%i",&n,&q);

    for(int i=1;i<=4*n;i++)
        tree[i]=0;

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<=q;i++)
    {
        int lq,rq;

        scanf("%i%i",&lq,&rq);

        update(1,1,n,lq,rq,rq);
    }

    seen={};

    for(int i=1;i<=n;i++)
        seen[inp[i]].push_back(i);

    for(int i=1;i<=n;i++)
    {
        int MX=query(1,1,n,i);

        MX=max(MX,i);

        int pos=upper_bound(seen[inp[i]].begin(),seen[inp[i]].end(),MX)-seen[inp[i]].begin();
        pos--;

        //cout<<i<<" -> "<<pos<<endl;

        if(seen[inp[i]][pos]==i)jump[i]=0;
        else jump[i]=seen[inp[i]][pos];
    }

    //for(int i=1;i<=n;i++)cout<<jump[i]<<" ";cout<<endl;

    int check_to=n;

    for(int i=1;i<=n;i++)
    {
        int pos=lower_bound(seen[inp[i]].begin(),seen[inp[i]].end(),i)-seen[inp[i]].begin();

        //cout<<"i= "<<i<<" pos= "<<pos<<endl;

        //if(pos)cout<<"\t jump "<<jump[seen[inp[i]][pos-1]]<<endl;

        if(pos&&jump[seen[inp[i]][pos-1]]>=i)
        {
            check_to=min(check_to,i);
        }
    }

    //cout<<"check= "<<check_to<<endl;

    for(int i=1;i<=n;i++)
    {
        pref_max[i]=pref_max[i-1];

        if(jump[i])pref_max[i]=max(pref_max[i],jump[i]);
    }

    for(int j=n;j>=1;j--)
    {
        suff_max[j]=0;

        if(j<n)suff_max[j]=suff_max[j+1];

        if(jump[j])suff_max[j]=max(suff_max[j],j);
    }

    int outp=n;

    for(int l=1;l<=check_to;l++)
    {
        //cout<<l<<" "<<pref_max[l-1]<<" "<<suff_max[l]<<endl;

        outp=min(outp,max(pref_max[l-1],suff_max[l])-l+1);
    }

    outp=max(outp,0);

    return outp;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        printf("%i\n",solve());
    }

    return 0;
}