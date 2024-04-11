#include <iostream>
#include <vector>
using namespace std;
vector <int> v[100002];
long long n,viz[100002],m,cst[100002],rsp[100002];
void citire ()
{
    int a,b;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>cst[i];
    for(int i=1;i<=m;++i)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
}
void dfs (int poz,int val)
{
    viz[poz]=val;
    for(int i=0;i<v[poz].size();i++)
        if(!viz[v[poz][i]])
            dfs(v[poz][i],val);
}
int main()
{
    long long i,poz,s=0,j=1,cr;
    citire();
    for(i=1;i<=n;i++)
        if(!viz[i])
            dfs(i,j++);
    --j;
    for(i=1;i<=j;++i)
        rsp[i]=-1;
    for(i=1;i<=n;++i)
    {
        cr=viz[i];
        if(cst[i]<rsp[cr] || rsp[cr]==-1)
            rsp[cr]=cst[i];
    }
    for(i=1;i<=j;++i)
        s+=rsp[i];
    cout<<s;
    return 0;
}