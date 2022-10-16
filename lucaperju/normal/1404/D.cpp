#include <bits/stdc++.h>
using namespace std;
int v[1000006];
vector<int>p[500005];
int rz[1000006],k,n;
vector<int>compc[500005];
int next (int pz)
{
    return p[v[pz]][0]+p[v[pz]][1]-pz;
}
int opus (int pz)
{
    if(pz<=n)
        return pz+n;
    else
        return pz-n;
}
void dfs(int pz)
{
    compc[k].push_back(pz);
    if(!rz[opus(pz)])
    {
        rz[opus(pz)]=-rz[pz];
        dfs(opus(pz));
    }
    if(!rz[next(pz)])
    {
        rz[next(pz)]=-rz[pz];
        dfs(next(pz));
    }
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    int i;
    if(n%2==0)
    {
        cout<<"First\n";
        for(i=1;i<=n;++i)
            cout<<i<<' ';
        for(i=1;i<=n;++i)
            cout<<i<<' ';
        cout<<'\n';
        cout.flush();
        int a;
        cin>>a;
        return 0;
    }
    cout<<"Second\n";
    cout.flush();
    for(i=1;i<=2*n;++i)
    {
        cin>>v[i];
        p[v[i]].push_back(i);
    }
    for(i=1;i<=n;++i)
    {
        if(rz[i])
            continue;
        rz[i]=1;
        ++k;
        dfs(i);
        dfs(i+n);
    }
    long long sumc=0;
    for(i=1;i<=2*n;++i)
    {
        if(rz[i]==1)
            sumc+=i;
    }
    if(sumc%(2*n)!=0)
    {
        for(i=1;i<=2*n;++i)
            rz[i]=-rz[i];
    }
    for(i=1;i<=2*n;++i)
        if(rz[i]==1)
            cout<<i<<' ';
    cout<<'\n';
    cout.flush();
    cin>>i;
    return 0;
}