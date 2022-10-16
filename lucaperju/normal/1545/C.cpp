#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int rz[1005],n;
vector<int>v[1005];
struct ura
{
    int pz,val;
};
vector<ura>vc;
bool cmp (ura a, ura b)
{
    return a.val<b.val;
}
int fvc[1005];
int mat[1005][505];
bool auinc (int a, int b, int n)
{
    for(int i=1;i<=n;++i)
        if(mat[a][i]==mat[b][i])
            return true;
    return false;
}
void set_pos (int pz, int val);
void set_1 (int pz)
{
    for(int k=1;k<=n+n;++k)
    {
        if(k==pz)
            continue;
        if(auinc(k,pz,n))
        set_pos(k,2);
    }
}
void set_pos1 (int pz, int val) // 1 = in set, 2 = not in set
{
    rz[pz]=val;
    if(val==1)
        set_1(pz);
}
void dfs (int pz)
{
    for(int i=0;i<v[pz].size();++i)
    {
        if(rz[v[pz][i]]==0)
        {
            //rz[v[pz][i]]=3-rz[pz];
            set_pos1(v[pz][i],3-rz[pz]);
            dfs(v[pz][i]);
        }
    }
}
void add_edge (int a, int b)
{
    if(rz[a] && !rz[b])
        set_pos(b,3-rz[a]);
    else if(rz[b] && !rz[a])
        set_pos(a,3-rz[b]);
    v[a].push_back(b);
    v[b].push_back(a);
}
void set_pos (int pz, int val) // 1 = in set, 2 = not in set
{
    set_pos1(pz,val);
    dfs(pz);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int q,m,i,j,l,r,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n+n;++i)
        {
            for(j=1;j<=n;++j)
                cin>>mat[i][j];
            rz[i]=0;
            v[i].clear();
        }
        for(int col=1;col<=n;++col)
        {
            vc.clear();
            for(i=1;i<=n+n;++i)
                if(rz[i]==1)
                    fvc[mat[i][col]]=1;
            for(i=1;i<=n+n;++i)
            {
                if(fvc[mat[i][col]]==1 && rz[i]==0)
                {
                    set_pos(vc[i].pz,2);
                }
            }
            for(i=1;i<=n;++i)
                fvc[i]=0;
            for(i=1;i<=n+n;++i)
                if(!rz[i])
                    vc.push_back({i,mat[i][col]});
            sort(vc.begin(),vc.end(),cmp);
            for(i=0;i<vc.size();++i)
            {
                if(i==vc.size()-1 || vc[i].val!=vc[i+1].val)
                {
                    if(i==0 || vc[i].val!=vc[i-1].val)
                    {
                        set_pos(vc[i].pz,1);
                        for(int k=1;k<=n+n;++k)
                        {
                            if(k==vc[i].pz)
                                continue;
                            if(auinc(k,vc[i].pz,n))
                                set_pos(k,2);
                        }
                    }
                    else if(i==1 || vc[i-1].val!=vc[i-2].val)
                    {
                        add_edge(vc[i].pz,vc[i-1].pz);
                    }
                }
            }
        }
        long long rzc=1;
        for(i=1;i<=n+n;++i)
        {
            if(!rz[i])
            {
                rzc=rzc*2LL%mod;
                set_pos(i,1);
            }
        }
        cout<<rzc<<'\n';
        for(i=1;i<=n+n;++i)
            if(rz[i]==1)
                cout<<i<<' ';
        cout<<'\n';
    }
    return 0;
}