#include <bits/stdc++.h>
using namespace std;
int st[300003],dr[300003],val[300003],vf[600003],curTime;
int str[300003][19];
vector<int>v[300003];
const int bucket=600;
short cntBucket[1003],fv[600003];
int rzf[300003];
int L=1,R=0;
struct ura
{
    int l,r,a,b;
    int vf,pz;
}qs[300003];
void dfs (int pz, int t)
{
    str[pz][0]=t;
    st[pz]=++curTime;
    vf[curTime]=val[pz];
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        dfs(v[pz][i],pz);
    }
    dr[pz]=++curTime;
    vf[curTime]=val[pz];
}
bool estr (int a, int b)
{
    return (st[a]<st[b] && dr[b]<dr[a]);
}
int lca (int a, int b)
{
    int put2=18;
    while(put2>=0)
    {
        if(!estr(str[a][put2],b))
            a=str[a][put2];
        --put2;
    }
    a=str[a][0];
    return a;
}
bool cmp (ura a, ura b)
{
    if(a.l/bucket==b.l/bucket)
        return a.r<b.r;
    else
        return a.l<b.l;
}
void add (int vlc)
{
    vlc=vf[vlc];
    fv[vlc]=1-fv[vlc];
    if(fv[vlc]==0)
        --cntBucket[vlc/bucket];
    else
        ++cntBucket[vlc/bucket];
}
int getAns (int l, int r)
{
    int i;
    for(i=(l-1)/bucket+1;i<(r+1)/bucket;++i)
    {
        if(cntBucket[i])
            break;
    }
    if(i<(r+1)/bucket)
    {
        for(int j=i*bucket;j<(i+1)*bucket;++j)
            if(fv[j])
                return j;
        return -2;
    }
    for(i=l;i<=min(r,l+bucket);++i)
        if(fv[i])
            return i;
    for(i=r;i>=max(l,r-bucket);--i)
        if(fv[i])
            return i;
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long q,m,i,j,n,l,r,t;
    cin>>n>>m;
    for(i=1;i<=n;++i)
        cin>>val[i];
    for(i=1;i<n;++i)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,1);
    for(int put2=1;put2<=18;++put2)
        for(i=1;i<=n;++i)
            str[i][put2]=str[str[i][put2-1]][put2-1];
    for(i=1;i<=m;++i)
    {
        cin>>qs[i].l>>qs[i].r>>qs[i].a>>qs[i].b;
        if(qs[i].l==qs[i].r)
        {
            qs[i].pz=i;
            qs[i].l=qs[i].r=st[qs[i].l];
            continue;
        }
        qs[i].vf=0;
        qs[i].pz=i;
        if(st[qs[i].l]<st[qs[i].r] && dr[qs[i].r]<dr[qs[i].l])
            qs[i].l=st[qs[i].l],qs[i].r=st[qs[i].r];
        else if(st[qs[i].r]<st[qs[i].l] && dr[qs[i].l]<dr[qs[i].r])
            qs[i].l=st[qs[i].l],qs[i].r=st[qs[i].r],swap(qs[i].l,qs[i].r);
        else if(st[qs[i].l]<st[qs[i].r])
            qs[i].vf=lca(qs[i].l,qs[i].r),qs[i].l=dr[qs[i].l],qs[i].r=st[qs[i].r];
        else
            qs[i].vf=lca(qs[i].l,qs[i].r),qs[i].l=st[qs[i].l],qs[i].r=dr[qs[i].r],swap(qs[i].l,qs[i].r);
    }
    sort(qs+1,qs+m+1,cmp);
    for(i=1;i<=m;++i)
    {
        while(R<qs[i].r)
            add(++R);
        while(qs[i].l<L)
            add(--L);
        while(qs[i].r<R)
            add(R--);
        while(L<qs[i].l)
            add(L++);
        if(qs[i].vf)
            add(st[qs[i].vf]);
        rzf[qs[i].pz]=getAns(qs[i].a,qs[i].b);
      //  cout<<getAns(qs[i].a,qs[i].b)<<'\n';
        if(qs[i].vf)
            add(st[qs[i].vf]);
    }
    for(i=1;i<=m;++i)
        cout<<rzf[i]<<'\n';
    return 0;
}