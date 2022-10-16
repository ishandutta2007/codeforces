#include <bits/stdc++.h>

using namespace std;

std::map< int,std::map<int,int> > mp;
struct ura1
{
    int a,b,c;
}rz[200005];
struct ura
{
    int a,b;
}v[200005];
struct ura2
{
    int a,pz;
};
ura2 xs[200005],ys[200005];
int fv[200005];
bool cmp (ura2 a, ura2 b)
{
    return a.a<b.a;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,i,j;
    cin>>n>>m;
    for(i=1;i<=n;++i)
    {
        cin>>v[i].a>>v[i].b;
        mp[v[i].a][v[i].b]=1;
        xs[i]={v[i].a,i};
        ys[i]={v[i].b,i};
    }
    sort(xs+1,xs+n+1,cmp);
    sort(ys+1,ys+n+1,cmp);
    int pzc=1;
    rz[1]={0,0,1000000001};
    int a=0,b=0;
    i=1,j=1;
    int k=1;
    int okt=0;
    if(n==1000)
        okt=1;
    while(i<=n || j<=n)
    {
        int cc1=1000000001,cc2=1000000001;
        if(i<=n)
            cc1=xs[i].a-a;
        if(j<=n)
            cc2=ys[j].a-b;
        rz[k].c=min(cc1,cc2);
        a+=min(cc1,cc2);
        b+=min(cc1,cc2);
        int ok=1;
        while(ok)
        {
            while(i<=n && xs[i].a<=a)
            {
                ++fv[xs[i].pz];
                if(fv[xs[i].pz]==2)
                {
                    if(xs[i].a==a)
                        ++a;
                    if(v[xs[i].pz].b==b)
                        ++b;
                }
                ++i;
            }
            ok=0;
            while(j<=n && ys[j].a<=b)
            {
                ++fv[ys[j].pz];
                if(fv[ys[j].pz]==2)
                {
                    if(ys[j].a==b)
                        ++b;
                    if(v[ys[j].pz].a==a)
                        ++a,ok=1;
                }
                ++j;
            }
        }
        rz[++k]={a,b,1000000001};
    }
 //   for(i=1;i<=k;++i)
  //      cout<<rz[i].a<<' '<<rz[i].b<<' '<<rz[i].c<<'\n';
    for(i=1;i<=m;++i)
    {
        /*if(i==20 && okt)
        {
            cout<<a<<'|'<<b<<'\n';
        }*/
        int a,b;
        cin>>a>>b;
        if(mp[a][b])
        {
            cout<<"LOSE\n";
            continue;
        }
        int kc=0,pas=1<<18;
        while(pas)
        {
            if(kc+pas<=k && rz[kc+pas].a+rz[kc+pas].b<=a+b)
                kc+=pas;
            pas>>=1;
        }
        if(a-rz[kc].a==b-rz[kc].b && a-rz[kc].a<rz[kc].c)
            cout<<"LOSE\n";
        else
            cout<<"WIN\n";
    }
    return 0;
}