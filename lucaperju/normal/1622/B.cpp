#include <bits/stdc++.h>

using namespace std;

int v[200005];
struct ura
{
    int pz,val;
};
int v1[200003];
int rz[200005];
bool cmp (ura a, ura b)
{
    return a.val<b.val;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long q,h,k,s=0,t,i,j,m;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        int cnt=0;
        for(i=1;i<=n;++i)
        {
            char c;
            cin>>c;
            v1[i]=c-'0';
            if(c=='0')
                ++cnt;
        }
        vector<ura>vc;
        for(i=1;i<=n;++i)
        {
            if(v1[i]==0)
            {
                vc.push_back({i,v[i]});
            }
        }
        sort(vc.begin(),vc.end(),cmp);
        for(i=0;i<vc.size();++i)
        {
            rz[vc[i].pz]=i+1;
        }
        vc.clear();
        for(i=1;i<=n;++i)
        {
            if(v1[i]==1)
            {
                vc.push_back({i,v[i]});
            }
        }
        sort(vc.begin(),vc.end(),cmp);
        for(i=0;i<vc.size();++i)
        {
            rz[vc[i].pz]=i+1+cnt;
        }
        for(i=1;i<=n;++i)
            cout<<rz[i]<<' ';
        cout<<'\n';
    }
}