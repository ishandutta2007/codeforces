#include <bits/stdc++.h>
using namespace std;
int rz[500005];
vector<int>v[500005];
vector<int>c[500005];
struct muchie /// si eu ma mir ca nu e ura
{
    int a,b,c;
}vi[500005];
bool cmp (muchie a, muchie b)
{
    if(a.a<b.a)
        return 1;
    if(a.a>b.a)
        return 0;
    if(a.b<b.b)
        return 1;
    if(a.b>b.b)
        return 0;
    return a.c<b.c;
}
int q[500005];
int dst[500005];
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,i,j,m,k,t;
    cin>>n>>m;
    for(i=1;i<=m;++i)
    {
        cin>>vi[i].a>>vi[i].b>>vi[i].c;
        ++vi[i].c;
    }
    sort(vi+1,vi+m+1,cmp);
    for(i=1;i<=m;)
    {
        int s=0;
        for(j=i;vi[j].a==vi[i].a && vi[j].b==vi[i].b && j<=m;++j)
            s|=vi[j].c;
        v[vi[i].b].push_back(vi[i].a);
        c[vi[i].b].push_back(s);
        i=j;
    }
    int st=1,dr=1;
    q[1]=n;
    dst[n]=1;
    while(st<=dr)
    {
        int nc=q[st++];
        for(i=0;i<v[nc].size();++i)
        {
            int nn=v[nc][i];
            if(dst[nn])
                continue;
            int cc=c[nc][i];
            if(cc==3)
            {
                dst[nn]=1+dst[nc];
                q[++dr]=nn;
            }
            if(cc==1)
            {
                if(rz[nn]==1)
                {
                    dst[nn]=1+dst[nc];
                    q[++dr]=nn;
                }
                else
                    rz[nn]=2;
            }
            if(cc==2)
            {
                if(rz[nn]==2)
                {
                    dst[nn]=1+dst[nc];
                    q[++dr]=nn;
                }
                else
                    rz[nn]=1;
            }
        }
    }
    cout<<dst[1]-1<<'\n';
    for(i=1;i<=n;++i)
    {
        if(rz[i])
            --rz[i];
        cout<<rz[i];
    }
    return 0;
}