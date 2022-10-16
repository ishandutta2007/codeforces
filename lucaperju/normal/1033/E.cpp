#include <bits/stdc++.h>
using namespace std;
int query (vector<int> pzs)
{
    if(pzs.size()<=1)
        return 0;
    cout<<"? "<<pzs.size()<<'\n';
    for(int i=0;i<pzs.size();++i)
        cout<<pzs[i]<<' ';
    cout<<'\n';
    cout.flush();
    int a;
    cin>>a;
    return a;
}
bool hasedge (int node, vector<int> pzs)
{
    int a=query(pzs);
    pzs.push_back(node);
    int b=query(pzs);
    return a<b;
}
int findedge (int node, vector<int> pzs)
{
    assert(1<=pzs.size());
    if(pzs.size()==1)
        return pzs[0];
    vector<int>vc;
    for(int i=0;i<pzs.size()/2;++i)
        vc.push_back(pzs[i]);
    if(hasedge(node,vc))
        return findedge(node,vc);
    vc.clear();
    for(int i=pzs.size()/2;i<pzs.size();++i)
        vc.push_back(pzs[i]);
    return findedge(node,vc);
}
vector<int>v[601];
int n;
bool inTree[601],isbad[601];
int col[601];
void dfs (int pz, int t)
{
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        col[v[pz][i]]=1-col[pz];
        dfs(v[pz][i],pz);
    }
}
vector <int> path;

bool dfspath (int t, int pz, int x)
{
    if(pz == x)
    {
		path.push_back(pz);
        return true;
    }
    bool ok = false;
    if(t)
        path.push_back(pz);
    for(int i = 0; i < v[pz].size(); ++i)
    {
        if(v[pz][i] == t)
            continue;
        ok = (ok or dfspath(pz, v[pz][i], x));
    }
    if(t && !ok)
        path.pop_back();
    return ok;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,i,j,m,q,k;
    cin>>n;
    inTree[1]=true;
    for(j=1;j<n;++j)
    {
        vector<int>vc;
        for(i=1;i<=n;++i)
            if(!inTree[i])
                vc.push_back(i);
        for(i=1;i<=n;++i)
        {
            if(inTree[i] && !isbad[i])
            {
                if(hasedge(i,vc))
                {
                    int a=findedge(i,vc);
                    v[a].push_back(i);
                    v[i].push_back(a);
                    inTree[a]=true;
                    break;
                }
                else
                    isbad[i]=true;
            }
        }
    }
    for(i=1;i<=n;++i)
        assert(inTree[i]);
    dfs(1,-1);
    vector<int>vc[2];
    for(i=1;i<=n;++i)
        vc[col[i]].push_back(i);
    if(query(vc[0]) == 0 && query(vc[1]) == 0)
    {
        cout<<"Y "<<vc[0].size()<<'\n';
        for(int i=0;i<vc[0].size();++i)
            cout<<vc[0][i]<<' ';
        cout<<'\n';
        cout.flush();
        return 0;
    }
    if(query(vc[0]) == 0)
        swap(vc[0],vc[1]);
    int a=query(vc[0]);
    assert(0<a);
    vector<int>vc1;
    int x=-1,y;
    for(i=0;i<vc[0].size();++i)
    {
        vc1.clear();
        for(j=0;j<vc[0].size();++j)
        {
            if(i==j)
                continue;
            vc1.push_back(vc[0][j]);
        }
        if(hasedge(vc[0][i],vc1))
        {
            x=vc[0][i];
            break;
        }
    }
    assert(x!=-1);
    y=findedge(x,vc1);
    dfspath(-1,x,y);
    cout<<"N "<<path.size()<<'\n';
    for(int i=0;i<path.size();++i)
        cout<<path[i]<<' ';
    cout<<'\n';
    cout.flush();
    return 0;
}