#include <bits/stdc++.h>
using namespace std;
int v[100003],ed[100003];
struct ura
{
    int gr,val;
}idk[100003];
bool cmp (ura a, ura b)
{
    return a.val>b.val;
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,n,i,j,k,mod,m;
    long long x1,y1,x2,y2;
    cin>>t;
    while(t--)
    {
        cin>>n;
        long long s=0;
        for(i=1;i<=n;++i)
        {
            ed[i]=0;
            cin>>v[i];
            s+=v[i];
        }
        for(i=1;i<n;++i)
        {
            int a,b;
            cin>>a>>b;
            ++ed[a];
            ++ed[b];
        }
        for(i=1;i<=n;++i)
            idk[i]={ed[i]-1,v[i]};
        sort(idk+1,idk+n+1,cmp);
        cout<<s<<' ';
        j=1;
        for(i=2;i<n;++i)
        {
            while(idk[j].gr==0)
                ++j;
            s+=idk[j].val;
            --idk[j].gr;
            cout<<s<<' ';
        }
        cout<<'\n';
    }
    return 0;
}