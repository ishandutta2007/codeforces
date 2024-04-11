#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int t[200005];
struct edg
{
    int a,b,cst;
}v[200005];
bool cmp (edg a, edg b)
{
    return a.cst<b.cst;
}
int tata (int a)
{
    if(t[a]==0)
        return a;
    t[a]=tata(t[a]);
    return t[a];
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie();cout.tie();
    long long n,k,i,j=0,cnt=0,s=0,pzs=1,psj=1,cur=0,pz,m,val;
    cin>>n>>m;
    for(i=1;i<=m;++i)
        cin>>v[i].a>>v[i].b>>v[i].cst;
    sort(v+1,v+m+1,cmp);
    for(i=1;i<=m;++i)
    {
        if(i==1 || v[i].cst!=v[i-1].cst)
        {
            for(j=i;v[j].cst==v[i].cst||j==1;++j)
                if(tata(v[j].a)==tata(v[j].b))
                    --cnt;
        }
        if(tata(v[i].a)!=tata(v[i].b))
            t[tata(v[i].a)]=tata(v[i].b),++cur;
        else
            ++cnt;
       /* if(cur==n-1)
        {
            val=v[i].cst;
            break;
        }*/
    }
  /*  for(i=1;i<=n;++i)
        t[i]=0;
    for(i=1;i<=m;++i)
    {
        if(tata(v[i].a)!=tata(v[i].b))
            t[tata(v[i].a)]=tata(v[i].b),++cur;
        if(cur==n-1)
        {
            val=v[i].cst;
            break;
        }
    }*/
    cout<<cnt;
    return 0;
}