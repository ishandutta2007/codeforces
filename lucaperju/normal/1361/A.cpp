#include <bits/stdc++.h>

using namespace std;
vector <int> v[500005];
struct ura
{
    int a,i;
}val[500005];
bool cmp (ura a, ura b)
{
    return a.a<b.a;
}
int cnt[500005];
int val1[500005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long m,n,k,t,i,j,mx,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0;
    cin>>n>>m;
    for(i=1;i<=m;++i)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(i=1;i<=n;++i)
    {
        cin>>val[i].a;
        val[i].i=i;
        val1[i]=val[i].a;
    }
    sort(val+1,val+n+1,cmp);
    for(i=1;i<=n;++i)
    {
        int vc=val[i].a;
        int pz=val[i].i;
        if(cnt[pz]!=vc-1)
        {
            cout<<-1;
            return 0;
        }
        for(j=0;j<v[pz].size();++j)
        {
            int nn=v[pz][j];
            if(val1[nn]<vc)
                continue;
            if(val1[nn]==vc)
            {
                cout<<-1;
                return 0;
            }
            if(cnt[nn]==cnt[pz])
                ++cnt[nn];
        }
    }
    for(i=1;i<=n;++i)
        cout<<val[i].i<<' ';
    return 0;
}