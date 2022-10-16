#include <bits/stdc++.h>
using namespace std;
struct ura
{
    int a,b,c;
};
vector<ura>rz;
int v[32];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long m=0,i,j,n,l,r;
    cin>>l>>r;
    cout<<"YES\n32 ";
    rz.push_back({1,32,l});
    int vlc=1;
    for(i=32-1;1;--i)
    {
        v[i]=vlc;
        for(j=i+1;j<=31;++j)
            rz.push_back({i,j,v[j]});
        rz.push_back({i,32,1});
        vlc=vlc*2;
        if(vlc>1000000)
            break;
    }
    vlc/=2;
    int sc=l;
    for(j=i;j<=31;++j)
    {
        if(sc+v[j]<=r)
        {
            rz.push_back({1,j,sc});
            sc+=v[j];
        }
    }
    cout<<rz.size()<<'\n';
    for(i=0;i<rz.size();++i)
        cout<<rz[i].a<<' '<<rz[i].b<<' '<<rz[i].c<<'\n';
    return 0;
}