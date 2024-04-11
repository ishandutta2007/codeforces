#include <bits/stdc++.h>
using namespace std;
int aib[200005];
int lsb (int x)
{
    return x&-x;
}
int query (int pz)
{
    int rz=0;
    for(int i=pz;i>0;i-=lsb(i))
        rz+=aib[i];
    return rz;
}
void update (int pz,int val)
{
    for(int i=pz;i<=200000;i+=lsb(i))
        aib[i]+=val;
}
char v[200005];
vector<int>pz[30];
int jc[30];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,rz=0,s=0,k,n,m;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        pz[v[i]-'a'+1].push_back(i);
    }
    for(int dr=n;dr>=1;--dr)
    {
        int ic=n-dr+1;
        int cc=v[dr]-'a'+1;
        int pzc=pz[cc][jc[cc]++];
        rz+=pzc-ic+query(pzc);
        update(pzc,-1);
        update(1,1);
    }
    cout<<rz<<'\n';
    return 0;
}