#include <bits/stdc++.h>

using namespace std;


char v[200005];
int l[200005],r[200005],rz[200005],ord[200005],nxt[200005];
int tc=0;
void dfsinit (int nod)
{
    if(l[nod])
        dfsinit(l[nod]);
    ord[++tc]=nod;
    if(r[nod])
        dfsinit(r[nod]);
}
int solve (int nod, int k)
{
    if(k==0)
        return 0;
    if(k==1)
    {
        if(v[nxt[nod]]>v[nod])
        {
            rz[nod]=1;
            return 1;
        }
        return 0;
    }
    int catt=0;
    int catl=0;
    if(l[nod])
        catl=solve(l[nod],k-1);
    if(catl>0)
    {
        k-=catl;
        --k;
        catt=1+catl;
        rz[nod]=1;
        int catr=0;
        if(r[nod])
            catr=solve(r[nod],k);
        k-=catr;
        catt+=catr;
        return catt;
    }
    else
    {
        if(v[nxt[nod]]<v[nod])
            return 0;
        rz[nod]=1;
        --k;
        ++catt;
        int catr=0;
        if(r[nod])
            catr=solve(r[nod],k);
        k-=catr;
        catt+=catr;
        return catt;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long q,h,n,k,s=0,t,i,j,m;
    cin>>n>>k;
    for(i=1;i<=n;++i)
        cin>>v[i];
    v[n+1]='a'-1;
    for(i=1;i<=n;++i)
        cin>>l[i]>>r[i];
    dfsinit(1);
    ord[n+1]=n+1;
    for(i=n;i>=1;--i)
    {
        if(v[ord[i]]!=v[ord[i+1]])
            nxt[ord[i]]=ord[i+1];
        else
            nxt[ord[i]]=nxt[ord[i+1]];
    }
    solve(1,k);
    for(i=1;i<=n;++i)
    {
        cout<<v[ord[i]];
        if(rz[ord[i]])
            cout<<v[ord[i]];
    }
}