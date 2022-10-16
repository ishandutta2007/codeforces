#include <bits/stdc++.h>

using namespace std;

struct ura
{
    int c,l,r,id;
}v[200005];
int t[200005];
int tata (int pz)
{
    if(t[pz]==0 || t[pz]==pz)
        return pz;
    return t[pz]=tata(t[pz]);
}
int v0[200005],v1[200005];
bool cmp (ura a, ura b)
{
    return a.l<b.l;
}
void join (int a, int b)
{
    a=tata(a);
    b=tata(b);
    t[b]=a;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long tt,i,n,k,d,m,j=0,p,K,cat=0;
    cin>>tt;
    while(tt--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            t[i]=0;
        for(i=1;i<=n;++i)
        {
            cin>>v[i].c>>v[i].l>>v[i].r;
            v[i].id=i;
        }
        sort(v+1,v+n+1,cmp);
        int nr0=0,nr1=0;
        for(i=1;i<=n;++i)
        {
            if(v[i].c==0)
            {
                int mx=1;
                for(j=1;j<=nr1;++j)
                {
                    if(v[v1[j]].r<v[i].l)
                        continue;
                    join(v[i].id,v[v1[j]].id);
                    if(v[v1[j]].r>v[v1[mx]].r)
                        mx=j;
                }
                v1[1]=v1[mx];
                if(v[v1[1]].r<v[i].l)
                    nr1=0;
                nr1=min(nr1,1);
                v0[++nr0]=i;
            }
            else
            {
                int mx=1;
                for(j=1;j<=nr0;++j)
                {
                    if(v[v0[j]].r<v[i].l)
                        continue;
                    join(v[i].id,v[v0[j]].id);
                    if(v[v0[j]].r>v[v0[mx]].r)
                        mx=j;
                }
                v0[1]=v0[mx];
                if(v[v0[1]].r<v[i].l)
                    nr0=0;
                nr0=min(nr0,1);
                v1[++nr1]=i;
            }
        }
        int cnt=0;
        for(i=1;i<=n;++i)
            if(i==tata(i))
                ++cnt;
        cout<<cnt<<'\n';
    }
    return 0;
}