#include <bits/stdc++.h>

using namespace std;
int rz[100003];
int v[100003],fv[100003],ord[100003],first[100003],last[100003];
int cnt[100003];
int minglobal;
const int bucket=2714;
struct ura
{
    int pz,l,r,k,t;
};
struct upd
{
    int pz,val,oldval;
};
vector<ura>qrys;
vector<upd>upds;
bool cmp (ura a, ura b)
{
    if(a.l/bucket<b.l/bucket)
        return true;
    if(a.l/bucket>b.l/bucket)
        return false;

    if(a.r/bucket<b.r/bucket)
        return true;
    if(a.r/bucket>b.r/bucket)
        return false;

    return a.t<b.t;
}
void add (int val)
{
    int vlc=fv[val];
    ++fv[val];
    ++cnt[vlc+1];
    --cnt[vlc];
    ord[last[vlc]]++;
    last[vlc]--;
    first[vlc+1]=last[vlc]+1;
    if(cnt[vlc+1]==1)
        last[vlc+1]=last[vlc]+1;
}
void rem (int val)
{
    int vlc=fv[val];
    --fv[val];
    ++cnt[vlc-1];
    --cnt[vlc];
    ord[first[vlc]]--;
    first[vlc]++;
    last[vlc-1]=first[vlc]-1;
    if(cnt[vlc-1]==1)
        first[vlc-1]=last[vlc-1];
}
int getans (int k, int n)
{
    int rz=1000011;
    for(int i=1;i<=n;++i)
    {
        i=last[ord[i]];
        if(i-k+1>=1 && ord[i-k+1])
            rz=min(rz,ord[i]-ord[i-k+1]);
    }
    if(rz==1000011)
        return -1;
    return rz;
}
void updadd(int l, int r, int t)
{
    int pz=upds[t].pz;
    int vl=upds[t].val;
    if(l<=pz && pz<=r)
    {
        rem(v[pz]);
        add(vl);
    }
    v[pz]=vl;
}
void updrem(int l, int r, int t)
{
    int pz=upds[t].pz;
    int vl=upds[t].oldval;
    if(l<=pz && pz<=r)
    {
        rem(v[pz]);
        add(vl);
    }
    v[pz]=vl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long t,n,m,i,j,s;
    cin>>n>>m;
    for(i=1;i<=n;++i)
        cin>>v[i];
    int cntc=0;
    for(i=1;i<=m;++i)
    {
        int a,b,c,d;
        cin>>a>>b>>c;
        if(a==1)
        {
            cin>>d;
            qrys.push_back({++cntc,b,c,d,upds.size()-1});
        }
        else
        {
            upds.push_back({b,c,v[b]});
            v[b]=c;
        }
    }
    first[0]=1;
    last[0]=n;
    sort(qrys.begin(),qrys.end(),cmp);
    int L=0,R=-1,T=upds.size()-1;
    for(int i=0;i<qrys.size();++i)
    {
        int l=qrys[i].l;
        int r=qrys[i].r;
        int t=qrys[i].t;
        while(R<r)
            add(v[++R]);
        while(l<L)
            add(v[--L]);
        while(r<R)
            rem(v[R--]);
        while(L<l)
            rem(v[L++]);
        while(T<t)
            updadd(l,r,++T);
        while(t<T)
            updrem(l,r,T--);
        rz[qrys[i].pz]=getans(qrys[i].k,n);
    }
    for(i=1;i<=cntc;++i)
        cout<<rz[i]<<'\n';
    return 0;
}