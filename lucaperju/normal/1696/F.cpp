#include <bits/stdc++.h>

using namespace std;

char in[101][101][101];
int t[101][101],fol[101];
int dst[101][101];
int tata (int id, int pz)
{
    if(t[id][pz]==0 || t[id][pz]==pz)
        return pz;
    return t[id][pz]=tata(id,t[id][pz]);
}
vector<pair<int,int> >rz;
int okc=1,n;
void dfs (int pz, int t)
{
    if(!okc)
        return;
    for(int i=1;i<=n;++i)
    {
        if(i==pz || i==t)
            continue;
        if(in[min(i,t)][max(i,t)][pz]=='1')
        {
            if(fol[i])
            {
                okc=0;
                return;
            }
            fol[i]=1;
            rz.push_back(make_pair(pz,i));
            dfs(i,pz);
        }
    }
}
bool verif ()
{
    int i,j,k;
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=n;++j)
        {
            dst[i][j]=1000;
            if(i==j)
                dst[i][j]=0;
        }
    }
    for(i=0;i<n-1;++i)
        dst[rz[i].first][rz[i].second]=dst[rz[i].second][rz[i].first]=1;
    for(k=1;k<=n;++k)
        for(i=1;i<=n;++i)
            for(j=1;j<=n;++j)
                dst[i][j]=min(dst[i][j],dst[i][k]+dst[k][j]);
    for(i=1;i<=n;++i)
        for(j=i+1;j<=n;++j)
            for(k=1;k<=n;++k)
            {
                if(dst[k][j]==dst[k][i] && in[i][j][k]=='0' || dst[k][j]!=dst[k][i] && in[i][j][k]=='1')
                    return false;
            }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int k=0,tt,i,j,m,x,y,ok=1;
    cin>>tt;
    while(tt--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
        {
            for(j=i+1;j<=n;++j)
            {
                cin>>(in[i][j]+1);
            }
        }
        ok=1;
        for(k=1;k<=n;++k)
        {
            for(i=1;i<=n;++i)
                t[k][i]=0;
            for(i=1;i<=n;++i)
            {
                for(j=i+1;j<=n;++j)
                {
                    if(in[i][j][k]=='1')
                    {
                        if(i==k || j==k)
                            ok=0;
                        t[k][tata(k,i)]=tata(k,j);
                    }
                }
            }
            for(i=1;i<=n;++i)
            {
                for(j=i+1;j<=n;++j)
                {
                    if(in[i][j][k]=='1' && tata(k,i)!=tata(k,j))
                        ok=0;
                    if(in[i][j][k]=='0' && tata(k,i)==tata(k,j))
                        ok=0;
                }
            }
            if(!ok)
                break;
        }
        if(!ok)
        {
            cout<<"NO\n";
            continue;
        }
        rz.clear();
        ok=0;
        for(i=2;i<=n;++i)
        {
            okc=1;
            for(j=1;j<=n;++j)
                fol[j]=0;
            rz.push_back(make_pair(1,i));
            fol[1]=fol[i]=1;
            dfs(1,i);
            dfs(i,1);
            if(okc && (int)rz.size()==n-1)
            {
                if(!verif())
                    continue;
                ok=1;
                break;
            }
            rz.clear();
        }
        if(!ok)
            cout<<"NO\n";
        else
        {
            cout<<"YES\n";
            for(i=0;i<n-1;++i)
                cout<<rz[i].first<<' '<<rz[i].second<<'\n';
        }
    }
    return 0;
}