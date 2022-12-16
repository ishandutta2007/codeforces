#include<bits/stdc++.h>
using namespace std;
const int nmax=5e5+42;
int n,a[nmax];
int le[nmax];
int ri[nmax];

vector< int/*index*/ > tree[4*nmax];

int help[nmax];

int inp[nmax];

int nearest_left[nmax],nearest_right[nmax];

bool cmp(int a,int b)
{
    if(nearest_left[a]!=nearest_left[b])return nearest_left[a]<nearest_left[b];
    return nearest_right[a]<nearest_right[b];
}

void build(int node,int l,int r)
{
    if(l==r)
    {
        tree[node].push_back(l);
        return;
    }

    int av=(l+r)/2;
    build(node*2,l,av);
    build(node*2+1,av+1,r);

    int SZ_l=tree[node*2].size(),SZ_r=tree[node*2+1].size();

    for(int i=1;i<=SZ_l;i++)help[i]=tree[node*2][i-1];
    for(int i=SZ_l+1;i<=SZ_l+SZ_r;i++)help[i]=tree[node*2+1][i-SZ_l-1];
    sort(help+1,help+SZ_l+SZ_r+1,cmp);

    int max_right=0;
    for(int i=1;i<=SZ_l+SZ_r;i++)
    {
        if(max_right<nearest_right[help[i]])
        {
            tree[node].push_back(help[i]);
            max_right=nearest_right[help[i]];
        }
    }

    int SZ_final=tree[node].size();
    for(int i=1;i<SZ_final;i++)
        assert(nearest_right[tree[node][i-1]]<=nearest_right[tree[node][i]]);
}
bool solved=0;
void query(int node,int l,int r,int lq,int rq,int lvalue,int rvalue)
{
    if(solved)return;
    if(l==lq&&r==rq)
    {
        if(nearest_left[tree[node][0]]>=lvalue)return;

        int ok=0,not_ok=tree[node].size(),av;

        while(not_ok-ok>1)
        {
            av=(ok+not_ok)/2;
            if(nearest_left[tree[node][av]]<lvalue)ok=av;
            else not_ok=av;
        }
        if(nearest_right[tree[node][ok]]>rvalue)
        {
            cout<<inp[tree[node][ok]]<<endl;
            solved=1;
        }
        return;
    }
    int av=(l+r)/2;
    if(lq<=av)query(node*2,l,av,lq,min(av,rq),lvalue,rvalue);
    if(av<rq)query(node*2+1,av+1,r,max(av+1,lq),rq,lvalue,rvalue);
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cin>>n;
for(int i=1;i<=n;i++)cin>>inp[i];

for(int i=0;i<nmax;i++)le[i]=-1,ri[i]=n+1;
for(int i=1;i<=n;i++)
{
    nearest_left[i]=le[inp[i]];
    le[inp[i]]=i;
}

for(int i=n;i>=1;i--)
{
    nearest_right[i]=ri[inp[i]];
    ri[inp[i]]=i;
}

build(1,1,n);

int q,l,r;
cin>>q;
for(int i=1;i<=q;i++)
{
    cin>>l>>r;
    solved=0;
    query(1,1,n,l,r,l,r);
    if(solved==0)cout<<0<<endl;
}
return 0;
}