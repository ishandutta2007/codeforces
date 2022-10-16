#include <bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
struct ura
{
    int a,b,pz;
}v[200003];
int rz[200003];
bool cmp (ura a, ura b)
{
    return a.a<b.a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,n,i,j,k,m;
    long long x1,y1,x2,y2;
    cin>>t;
    while(t--)
    {
        long long w,h;
        cin>>n;
        for(i=1;i<=n;++i)
        {
            cin>>v[i].a>>v[i].b;
            if(v[i].a>v[i].b)
                swap(v[i].a,v[i].b);
            v[i].pz=i;
        }
        sort(v+1,v+n+1,cmp);
        int bst=1,bstc=1;
        for(i=1;i<=n;++i)
        {
            if(v[i].a!=v[i-1].a)
                bst=bstc;
            if(v[bst].a<v[i].a && v[bst].b<v[i].b)
                rz[v[i].pz]=v[bst].pz;
            else
                rz[v[i].pz]=-1;
            if(v[i].b<v[bstc].b)
                bstc=i;
        }
        for(i=1;i<=n;++i)
            cout<<rz[i]<<' ';
        cout<<'\n';
    }
    return 0;
}