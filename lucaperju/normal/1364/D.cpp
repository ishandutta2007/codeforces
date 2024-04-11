#include <bits/stdc++.h>
 
using namespace std;
int t[100005][19];
vector <int> v[100005];
int a[200005],b[200005];
int viz[100005],niv[100005],st[100005],dr[100005],tmp;
void dfs (int pz)
{
    st[pz]=++tmp;
    viz[pz]=1;
    for(int i=0;i<v[pz].size();++i)
    {
        if(!viz[v[pz][i]])
        {
            t[v[pz][i]][0]=pz;
            niv[v[pz][i]]=niv[pz]+1;
            dfs(v[pz][i]);
        }
    }
    dr[pz]=++tmp;
}
int nod;
int lca (int a, int b)
{
    int pas=17;
    if((st[a]<st[b] && dr[a]>dr[b]) || (st[b]<st[a] && dr[a]<dr[b]))
    {
        if(st[a]<st[b])
            nod=a;
        else
            nod=b;
        return 1+max(niv[a],niv[b])-min(niv[a],niv[b]);
    }
    int pa=a;
    while(pas)
    {
        int pan=t[pa][pas];
        if(st[pan]>st[b] || dr[pan]<dr[b])
            pa=pan;
        pas--;
    }
    int pan=t[pa][pas];
    if(st[pan]>st[b] || dr[pan]<dr[b])
        pa=pan;
    int nod=t[pa][0];
    return 1+niv[a]-niv[nod]+niv[b]-niv[nod];
}
int cycf[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    unsigned long long m,k,i,j,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0,n;
    cin>>n>>m>>k;
    for(i=1;i<=m;++i)
    {
        int x,y;
        cin>>x>>y;
        a[i]=x;
        b[i]=y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    t[1][0]=1;
    niv[1]=1;
    dfs(1);
    j=0;
    for(i=1;i<=m;++i)
    {
        if(t[a[i]][0]!=b[i] && t[b[i]][0]!=a[i])
        {
            a[++j]=a[i];
            b[j]=b[i];
        }
    }
    m=j;
    if(m==0)
    {
        cout<<"1\n";
        int cnt0=0,cnt1=0;
        for(i=1;i<=n;++i)
        {
            if(niv[i]%2==0)
                ++cnt0;
            else
                ++cnt1;
        }
        int cnt=(k+1)/2;
        for(i=1;i<=n;++i)
        {
            if(cnt0>cnt1 && niv[i]%2==0 && cnt)
            {
                cout<<i<<' ';
                --cnt;
            }
            else if(cnt1>=cnt0 && niv[i]%2==1 && cnt)
            {
                cout<<i<<' ';
                --cnt;
            }
        }
        return 0;
    }
    for(j=1;j<=17;++j)
        for(i=1;i<=n;++i)
            t[i][j]=t[t[i][j-1]][j-1];
    int mn=n,pz=1;
    for(i=1;i<=m;++i)
    {
        int dstc=lca(a[i],b[i]);
        if(dstc<mn)
            mn=dstc,pz=i;
    }
    int af=a[pz],bf=b[pz];
    lca(af,bf);
    int pa;
    i=0;
    for(pa=af;pa!=nod;pa=t[pa][0])
        cycf[++i]=pa;
    cycf[++i]=nod;
    i=mn+1;
    for(pa=bf;pa!=nod;pa=t[pa][0])
        cycf[--i]=pa;
    if(mn<=k)
    {
        cout<<"2\n";
        cout<<mn<<'\n';
        for(i=1;i<=mn;++i)
            cout<<cycf[i]<<' ';
    }
    else
    {
        cout<<"1\n";
        for(i=1;i<=(k+1)/2*2;i+=2)
            cout<<cycf[i]<<' ';
    }
    return 0;
}