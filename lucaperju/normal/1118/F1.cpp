#include <bits/stdc++.h>

using namespace std;
long long cmmdc (long long a, long long b)
{
    long long r;
    while(b)
    {r=a%b;a=b;b=r;}
    return a;
}
int t[300005],ct1[300005],ct2[300005],val[300005],viz[300005];
vector <int> v[300005];
void dfs (int poz)
{
    int s1=0,s2=0;
    viz[poz]=1;
    if(val[poz]==1)
        ++s1;
    if(val[poz]==2)
        ++s2;
    for(int i=0;i<v[poz].size();++i)
    {
        if(viz[v[poz][i]])
            continue;
        dfs(v[poz][i]);
        s1+=ct1[v[poz][i]];
        s2+=ct2[v[poz][i]];
    }
    ct1[poz]=s1;
    ct2[poz]=s2;
}
int main()
{
    long long i,j=0,n,pz=-1,s=0,x,y,z,a,b,c,m,pr,cnt=0,mx=0,mxx=0,x1,y1,x2,y2,cx=0,cy=0,nr1=0,nr2=0;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>val[i];
        if(val[i]==1)
            ++nr1;
        if(val[i]==2)
            ++nr2;
    }
    for(i=1;i<n;++i)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    for(i=2;i<=n;++i)
    {
        if(ct1[i]==0 && ct2[i]==nr2 || ct2[i]==0 && ct1[i]==nr1)
            ++s;
    }
    cout<<s;
}