#include <bits/stdc++.h>
using namespace std;
vector<int>v[100015];
vector<long long>co[100015];
long long cst[100015],h[100015],k;
bool viz[100015];
void shift_up (int poz)
{
    while(poz>1 && cst[h[poz]]<cst[h[poz/2]])
    {
        swap(h[poz],h[poz/2]);
        poz>>=1;
    }
}
void shift_down (int poz)
{
    while(poz*2<k && cst[h[poz]]>min(cst[h[poz*2]],cst[h[poz*2+1]]))
    {
        if(cst[h[poz*2]]<cst[h[poz*2+1]])
        {
            swap(h[poz],h[poz*2]);
            poz<<=1;
        }
        else
        {
            swap(h[poz],h[poz*2+1]);
            poz<<=1;
            ++poz;
        }
    }
    if(poz*2==k && cst[h[poz]]>cst[h[poz*2]])
        swap(h[poz],h[poz*2]);
}
void dijkstra ()
{
    int nc,nn,i;
    viz[1]=1;
    h[++k]=1;
    while(k)
    {
        nc=h[1];
        swap(h[1],h[k]);
        --k;
        shift_down(1);
        viz[nc]=0;
        for(i=0;i<v[nc].size();++i)
        {
            nn=v[nc][i];
            if(cst[nn]>cst[nc]+co[nc][i])
            {
                cst[nn]=cst[nc]+co[nc][i];
                if(!viz[nn])
                {
                    h[++k]=nn;
                    shift_up(k);
                    viz[nn]=1;
                }
            }
        }
    }
}
struct ura
{
    int x,y,pz;
}vc[100005];
void add_edge(int a, int b, int c)
{
    v[a].push_back(b);
    v[b].push_back(a);
    co[a].push_back(c);
    co[b].push_back(c);
}
long long dist (long long a, long long b, long long x, long long y)
{
    if(a<x)
        swap(a,x);
    if(b<y)
        swap(b,y);
    return a-x+b-y;
}
long long dist1 (long long a, long long b, long long x, long long y)
{
    if(a<x)
        swap(a,x);
    if(b<y)
        swap(b,y);
    return min(a-x,b-y);
}
bool cmpx (ura a, ura b)
{
    return a.x<b.x;
}
bool cmpy (ura a, ura b)
{
    return a.y<b.y;
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,k=0,n,q,m,ans=0,sx,sy,fx,fy;
    cin>>n>>m;
    cin>>sx>>sy>>fx>>fy;
    for(i=1;i<=m+2;++i)
        cst[i]=20000000000LL;
    for(i=1;i<=m;++i)
    {
        cin>>vc[i].x>>vc[i].y;
        vc[i].pz=i+2;
    }
    add_edge(1,2,dist(sx,sy,fx,fy));
    for(i=1;i<=m;++i)
    {
        add_edge(1,vc[i].pz,dist1(sx,sy,vc[i].x,vc[i].y));
        add_edge(2,vc[i].pz,dist(fx,fy,vc[i].x,vc[i].y));
    }
    sort(vc+1,vc+m+1,cmpx);
    for(i=1;i<m;++i)
        add_edge(vc[i].pz,vc[i+1].pz,dist1(vc[i].x,vc[i].y,vc[i+1].x,vc[i+1].y));
    sort(vc+1,vc+m+1,cmpy);
    for(i=1;i<m;++i)
        add_edge(vc[i].pz,vc[i+1].pz,dist1(vc[i].x,vc[i].y,vc[i+1].x,vc[i+1].y));
    cst[1]=0;
    dijkstra();
    cout<<cst[2]<<'\n';
    return 0;
}