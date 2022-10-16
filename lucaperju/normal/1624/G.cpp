
#include <bits/stdc++.h>

using namespace std;
int t[200005];
int tata (int pz)
{
    if(t[pz]==pz || t[pz]==0)
        return pz;
    return t[pz]=tata(t[pz]);
}
struct ura
{
    int a,b,c;
}v[200005];
vector<int>banned;
void join (int a, int b)
{
    a=tata(a);
    b=tata(b);
    t[a]=b;
}
bool sepoate (int n,int m)
{
    for(int i=1;i<=n;++i)
        t[i]=i;
    for(int i=1;i<=m;++i)
    {
        int ok=1;
        for(int j=0;j<banned.size();++j)
        {
            if(v[i].c&banned[j])
                ok=0;
        }
        if(!ok)
            continue;
        join(v[i].a,v[i].b);
    }
    for(int i=2;i<=n;++i)
        if(tata(i)!=tata(i-1))
            return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int n,l=1,i,r=n-1,cat=0,m;
        cin>>n>>m;
        for(i=1;i<=m;++i)
            cin>>v[i].a>>v[i].b>>v[i].c;
        banned.clear();
        int rz=0;
        for(i=29;i>=0;--i)
        {
            banned.push_back(1<<i);
            if(!sepoate(n,m))
            {
                banned.pop_back();
                rz=(rz|(1<<i));
            }
        }
        cout<<rz<<'\n';
    }

    return 0;
}