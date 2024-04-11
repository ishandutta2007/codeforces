#include <bits/stdc++.h>
using namespace std;
int rz[1003][1003];
struct ura
{
    int val,pz;
}v[1003];
bool cmp (ura a, ura b)
{
    return a.val<b.val;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n,i,j;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i].val;
        v[i].pz=i;
    }
    sort(v+1,v+n+1,cmp);
    for(i=1;i<=n;++i)
    {
        int pzc=i+1;
        int pz=v[i].pz;
        for(j=pzc-1;j>=1;--j)
        {
            if(v[i].val)
            {
                --v[i].val;
                rz[j][pz]=1;
            }
        }
        for(j=pzc+1;j<=n+1;++j)
        {
            if(v[i].val)
            {
                --v[i].val;
                rz[j][pz]=1;
            }
        }
    }
    cout<<n+1<<'\n';
    for(i=1;i<=n+1;++i)
    {
        for(j=1;j<=n;++j)
            cout<<rz[i][j];
        cout<<'\n';
    }
}