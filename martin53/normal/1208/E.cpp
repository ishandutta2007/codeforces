#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42,inf=1e9+42;
int n,inp[nmax];

long long output[nmax],pref[nmax];

int tree[4*nmax];

void build(int node,int l,int r)
{
    if(l==r)
    {
        tree[node]=inp[l];
        return;
    }
    int av=(l+r)/2;

    build(node*2,l,av);
    build(node*2+1,av+1,r);

    tree[node]=max(tree[node*2],tree[node*2+1]);
    //cout<<l<<" "<<r<<" -> "<<tree[node]<<endl;
}
int query(int node,int l,int r,int lq,int rq)
{
    //cout<<"query "<<tree[node]<<" "<<l<<" "<<r<<" "<<lq<<" "<<rq<<endl;
    if(l==lq&&r==rq)return tree[node];
    int av=(l+r)/2,ret=-inf;

    if(lq<=av)ret=max(ret,query(node*2,l,av,lq,min(av,rq)));
    if(av<rq)ret=max(ret,query(node*2+1,av+1,r,max(av+1,lq),rq));

    return ret;
}
int q,w,k;
void brute(int i)
{
    int lq=max(0,i-w+k);
    int rq=min(k+1,i);

    output[i]+=query(1,0,k+1,lq,rq);
    //cout<<i<<" -> "<<query(1,0,k+1,lq,rq)<<endl;
}
int main()
{
    scanf("%i%i",&q,&w);
    for(int t=1;t<=q;t++)
    {
        scanf("%i",&k);
        inp[0]=0;
        inp[k+1]=0;
        for(int j=1;j<=k;j++)
            scanf("%i",&inp[j]);

        build(1,0,k+1);

        for(int i=1;i<=k;i++)
        {
            brute(i);
        }

        for(int i=max(k+1,w-k);i<=w;i++)
        {
            brute(i);
        }

        int low=k+1,high=w-k-1;

        if(low>high)continue;

        int now=query(1,0,k+1,0,k+1);

        //cout<<low<<" to "<<high<<" -> "<<now<<endl;

        pref[low]+=now;
        pref[high+1]-=now;
    }

    for(int i=1;i<=w;i++)
    {
        pref[i]=pref[i]+pref[i-1];
        output[i]=output[i]+pref[i];
    }
    for(int i=1;i<=w;i++)
        printf("%lld\n",output[i]);
}