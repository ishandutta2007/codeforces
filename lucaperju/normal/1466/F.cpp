#include <bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
int t[500003];
int cnt[500003];
long long rz=1;
int tata (int pz)
{
    if(t[pz]==0 || t[pz]==pz)
        return pz;
    return t[pz]=tata(t[pz]);
}
vector<int>sf;
void join (int a, int b)
{
    int ta=tata(a);
    int tb=tata(b);
    int vlc=(cnt[ta]|cnt[tb]);
    t[ta]=tb;
    cnt[tb]=vlc;
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,n,i,j,k,m;
    long long x1,y1,x2,y2,rz=1;
    cin>>m>>n;
    for(i=1;i<=m;++i)
    {
        int a,b,c;
        cin>>a;
        if(a==1)
        {
            cin>>b;
            int tc=tata(b);
            if(cnt[tc])
                continue;
            cnt[tc]=1;
            rz=(rz*2LL)%mod;
            sf.push_back(i);
        }
        else
        {
            cin>>b>>c;
            int t1=tata(b);
            int t2=tata(c);
            if(t1==t2 || cnt[t1]==1 && cnt[t2]==1)
                continue;
            join(t1,t2);
            rz=(rz*2LL)%mod;
            sf.push_back(i);
        }
    }
    cout<<rz<<' '<<sf.size()<<'\n';
    for(i=0;i<sf.size();++i)
        cout<<sf[i]<<' ';
    return 0;
}