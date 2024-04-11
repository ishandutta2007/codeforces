#include <bits/stdc++.h>
using namespace std;
vector<int> v[100005];
vector<int> cst[100005];
vector<int> vc;
int viz[100005][3],val[100005][2];
int posibil=1;
double valf[100005];
vector<int> vc1;
void dfs (int pz, int sgn, int vlc)
{
    if(!viz[pz][2])
    {
        viz[pz][2]=1;
        vc.push_back(pz);
    }
    viz[pz][sgn]=1;
    val[pz][sgn]=vlc;
    for(int i=0;i<v[pz].size();++i)
    {
        int nn=v[pz][i];
        if(!viz[nn][1-sgn])
            dfs(nn,1-sgn,cst[pz][i]-vlc);
        else if(viz[nn][1-sgn])
            if(val[nn][1-sgn]!=cst[pz][i]-vlc)
                posibil=0;
    }
}
void solve (int pz)
{
    vc.clear();
    dfs(pz,0,0);
    int fix=0,i,j;
    double a=0;
    for(int k=0;k<vc.size();++k)
    {
        i=vc[k];
        if(viz[i][0] && viz[i][1])
        {
            double vln=(double)(val[i][1]-val[i][0])/2;
            if(fix && a!=vln)
                posibil=0;
            a=vln;
            fix=1;
        }
    }
    if(fix)
    {
        for(int k=0;k<vc.size();++k)
        {
            i=vc[k];
            if(viz[i][0])
                valf[i]=a+val[i][0];
            else
                valf[i]=-a+val[i][1];
        }
        return;
    }
    vc1.clear();
    for(int k=0;k<vc.size();++k)
    {
        i=vc[k];
        if(viz[i][0])
            vc1.push_back(val[i][0]);
        else
            vc1.push_back(-val[i][1]);
    }
    sort(vc1.begin(),vc1.end());
    int sz=vc1.size();
    a=-vc1[sz/2];
    for(int k=0;k<vc.size();++k)
    {
        i=vc[k];
        if(viz[i][0])
            valf[i]=a+val[i][0];
        else
            valf[i]=-a+val[i][1];
    }
    return;
}
int main()
{
    long long n,m,i,j,x,y,k,t,l,r;
    cin>>n>>m;
    for(i=1;i<=m;++i)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back(b);
        v[b].push_back(a);
        cst[a].push_back(c);
        cst[b].push_back(c);
    }
    for(i=1;i<=n;++i)
        if(!viz[i][2])
            solve(i);
    if(!posibil)
    {
        cout<<"NO\n";
        return 0;
    }
    else
    {
        cout<<"YES\n";
        for(i=1;i<=n;++i)
            cout<<valf[i]<<' ';
    }
    return 0;
}