#include <iostream>
#include <algorithm>
using namespace std;
struct ura
{
    long long p,c,pz;
}v[100005];
long long mx[12],k,rez[100005];
bool cmp (ura a, ura b)
{
    if(a.p<b.p)
        return true;
    return false;
}
void update (int poz)
{
    for(int i=k;i>=poz;--i)
        mx[i]=mx[i-1];
}
int main()
{
    long long n,i,j,a,s=0;
    cin>>n>>k;
    for(i=1;i<=n;++i)
        cin>>v[i].p;
    for(i=1;i<=n;++i)
    {
        cin>>v[i].c;
        v[i].pz=i;
    }
    sort(v+1,v+n+1,cmp);
    for(i=1;i<=n;++i)
    {
        s=0;
        for(j=1;j<=k;++j)
            s+=mx[j];
        rez[v[i].pz]=s+v[i].c;
        a=v[i].c;
        for(j=1;j<=k;++j)
        {
            if(a>mx[j])
            {
                update(j+1);
                mx[j]=a;
                break;
            }
        }
    }
    for(i=1;i<=n;++i)
        cout<<rez[i]<<' ';
    return 0;
}