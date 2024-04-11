#include<bits/stdc++.h>
using namespace std;

const int nmax=3e5+42;

int n;

int h[nmax];

int b[nmax];

long long dp[nmax];

stack< int > st;

long long pref_mx[nmax];

long long tree[4*nmax];

void update(int node,int l,int r,int pos,long long val)
{
    tree[node]=max(tree[node],val);

    if(l==r)return;

    int av=(l+r)/2;

    if(pos<=av)update(node*2,l,av,pos,val);
    else update(node*2+1,av+1,r,pos,val);
}
long long query(int node,int l,int r,int lq,int rq)
{
    if(l==lq&&r==rq)return tree[node];

    long long ret=-1e18;

    int av=(l+r)/2;

    if(lq<=av)ret=max(ret,query(node*2,l,av,lq,min(av,rq)));
    if(av<rq)ret=max(ret,query(node*2+1,av+1,r,max(av+1,lq),rq));

    return ret;
}
int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&h[i]);

    for(int i=1;i<=n;i++)scanf("%i",&b[i]);

    for(int i=0;i<=n;i++)pref_mx[i]=-1e18;

    for(int i=1;i<4*nmax;i++)
        tree[i]=-1e18;

    update(1,1,n,1,0);

    for(int i=1;i<=n;i++)
    {
        dp[i]=-1e18;

        while(st.size()&&h[st.top()]>h[i])st.pop();

        int prv=0;

        if(st.size())prv=st.top();

        int SZ=st.size();

        if(SZ)dp[i]=max(dp[i],pref_mx[SZ-1]);

        pref_mx[SZ]=-1e18;

        long long val;

        val=b[i]+query(1,1,n,prv+1,i);

        /*
        for(int j=prv+1;j<=i;j++)
            val=max(val,b[i]+dp[j-1]);
        */

        pref_mx[SZ]=val;

        dp[i]=max(dp[i],val);

        if(SZ)pref_mx[SZ]=max(pref_mx[SZ],pref_mx[SZ-1]);

        st.push(i);

        if(i<n)update(1,1,n,i+1,dp[i]);

        //cout<<i<<" -> "<<dp[i]<<endl;

        /*
        cout<<"SZ= "<<SZ<<endl;
        for(int j=1;j<=SZ;j++)cout<<pref_mx[j-1]<<" ";cout<<endl;
        */
    }

    printf("%lld\n",dp[n]);

    return 0;
}