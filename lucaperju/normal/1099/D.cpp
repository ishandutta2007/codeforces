#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iomanip>
#include <map>
#include <cmath>
using namespace std;
long long val[100005],valf[100005],oktot;
vector <int> v[100005];
int viz[100005];
void dfs (int poz, long long sc)
{
    viz[poz]=1;
    long long nc=poz,nn,mn=99999999999LL;
    if(val[poz]!=-1)
    {
        if(val[poz]<sc)
            oktot=1;
        valf[poz]=val[poz]-sc;
    }
    for(int i=0;i<v[nc].size();++i)
    {
        nn=v[nc][i];
        if(val[nn]<mn)
            mn=val[nn];
    }
    if(val[poz]==-1 && v[nc].size())
    {
        valf[poz]=mn-sc;
        if(valf[poz]<0)
            oktot=1;
    }
    for(int i=0;i<v[nc].size();++i)
    {
        nn=v[nc][i];
        dfs(nn,sc+valf[nc]);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie();cout.tie();
    long long ci,cc,i,j,s=0,cnt=0,cnt0=0,n,a,k,ok=0;
    cin>>n;
    for(i=2;i<=n;++i)
    {
        cin>>a;
        v[a].push_back(i);
    }
    for(i=1;i<=n;++i)
        cin>>val[i];
    dfs(1,0LL);
    if(oktot)
        cout<<-1;
    else
    {
        for(i=1;i<=n;++i)
            s+=valf[i];
        cout<<s;
    }
}