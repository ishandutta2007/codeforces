#include <bits/stdc++.h>

using namespace std;
vector<int>v[600005];
int dep[600005],viz[600005];
vector<vector<int> > rz;
vector<int>vc;
void dfs (int pz)
{
    viz[pz]=1;
    int ok=0;
    for(int i=0;i<v[pz].size();++i)
    {
        if(!viz[v[pz][i]])
        {
            vc.push_back(v[pz][i]);
            dep[v[pz][i]]=1+dep[pz];
            dfs(v[pz][i]);
            vc.push_back(pz);
        }
        else
        {
            if(dep[v[pz][i]]>dep[pz])
                continue;
            if(dep[v[pz][i]]!=dep[pz]-1 || ok)
            {
                vc.push_back(v[pz][i]);
                vc.push_back(pz);
            }
            else
                ok=1;
        }
    }
}
int mat[3][300005];
char m1[3][300005],m2[3][300005];
int main()
{
    ios_base::sync_with_stdio(false);
    int k=0,t,i,j,n,a,b,m,x,y,ok=1;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>a>>b;
        v[a].push_back(b);
        if(a!=b)
            v[b].push_back(a);
    }
    for(i=1;i<=n+n;++i)
    {
        if((int)v[i].size()>0 && !viz[i])
        {
            dep[i]=1;
            vc.clear();
            dfs(i);
            if((int)vc.size()==2)
            {
                cout<<-1;
                return 0;
            }
            rz.push_back(vc);
        }
    }
    cout<<2<<' '<<n<<'\n';
    int pz=1;
    for(int ind=0;ind<rz.size();++ind)
    {
        int nc=rz[ind].size();
        for(i=0;i<nc/2;++i)
        {
            mat[1][pz+i]=rz[ind][i];
        }
        for(i=nc/2;i<nc;++i)
        {
            mat[2][pz+nc-1-i]=rz[ind][i];
        }
        if(nc%4==2)
        {
            m1[1][pz]='U';
            m1[2][pz]='D';
            for(i=1;i+1<nc/2;i+=2)
            {
                m1[1][pz+i]=m1[2][pz+i]='L';
                m1[1][pz+i+1]=m1[2][pz+i+1]='R';
            }
            m2[1][pz+nc/2-1]='U';
            m2[2][pz+nc/2-1]='D';
            for(i=0;i+1<nc/2;i+=2)
            {
                m2[1][pz+i]=m2[2][pz+i]='L';
                m2[1][pz+i+1]=m2[2][pz+i+1]='R';
            }
        }
        else
        {
            for(i=0;i+1<nc/2;i+=2)
            {
                m1[1][pz+i]=m1[2][pz+i]='L';
                m1[1][pz+i+1]=m1[2][pz+i+1]='R';
            }
            m2[1][pz+nc/2-1]='U';
            m2[2][pz+nc/2-1]='D';
            m2[1][pz]='U';
            m2[2][pz]='D';
            for(i=1;i+1<nc/2;i+=2)
            {
                m2[1][pz+i]=m2[2][pz+i]='L';
                m2[1][pz+i+1]=m2[2][pz+i+1]='R';
            }
        }
        pz+=nc/2;
    }
    for(i=1;i<=2;++i)
    {
        for(j=1;j<=n;++j)
        {
            cout<<mat[i][j]<<' ';
        }
        cout<<'\n';
    }
    for(i=1;i<=2;++i)
    {
        for(j=1;j<=n;++j)
        {
            cout<<m1[i][j];
        }
        cout<<'\n';
    }
    for(i=1;i<=2;++i)
    {
        for(j=1;j<=n;++j)
        {
            cout<<m2[i][j];
        }
        cout<<'\n';
    }
    return 0;
}