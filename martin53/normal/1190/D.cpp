#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;

int n;
pair<int/*x*/,int/*y*/> inp[nmax];

int help[nmax];
void compress_x()
{
    for(int i=1;i<=n;i++)
    {
        help[i]=inp[i].first;
    }
    sort(help+1,help+n+1);

    for(int i=1;i<=n;i++)
    {
        inp[i].first=lower_bound(help+1,help+n+1,inp[i].first)-help;
    }
}
bool cmp(pair<int/*x*/,int/*y*/> a,pair<int/*x*/,int/*y*/> b)
{
    if(a.second!=b.second)return a.second>b.second;
    return a.first<b.first;
}
int tree[nmax*4];

void update(int node,int l,int r,int pos)
{
    if(l==r)
    {
        tree[node]=1;
        return;
    }
    int av=(l+r)/2;
    if(pos<=av)update(node*2,l,av,pos);
    else update(node*2+1,av+1,r,pos);
    tree[node]=tree[node*2]+tree[node*2+1];
}
int query(int node,int l,int r,int lq,int rq)
{
    //cout<<"query "<<node<<" "<<l<<" "<<r<<" "<<lq<<" "<<rq<<endl;

    if(l==lq&&r==rq)return tree[node];
    int av=(l+r)/2,ret=0;

    if(lq<=av)ret=ret+query(node*2,l,av,lq,min(av,rq));
    if(av<rq)ret=ret+query(node*2+1,av+1,r,max(av+1,lq),rq);
    return ret;
}
int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i%i",&inp[i].first,&inp[i].second);

    compress_x();

    sort(inp+1,inp+n+1,cmp);

    long long output=0;
    for(int i=1;i<=n;i++)
    {
        int j=i;
        while(j<=n&&inp[i].second==inp[j].second)j++;
        j--;

        //cout<<i<<" "<<j<<endl;
        for(int k=i;k<=j;k++)
            update(1,1,n,inp[k].first);

        long long diff=query(1,1,n,1,n);
        output=output+diff*(diff+1)/2;

        int prev=1;

        for(int k=i;k<=j;k++)
        {
            //add(prev,inp[k].first-1);
            if(prev<=inp[k].first-1)
            {
                diff=query(1,1,n,prev,inp[k].first-1);
                output=output-diff*(diff+1)/2;
            }
            prev=inp[k].first+1;
        }

        if(prev<=n)
        {
            diff=query(1,1,n,prev,n);
            output=output-diff*(diff+1)/2;
        }

        i=j;
    }

    printf("%lld\n",output);
    return 0;
}