#include <bits/stdc++.h>

using namespace std;
vector <int> v[100003];
int fv[100003];
int cst[3][100003];
int vn[100003];
int vcur[100003];
int vbest[100003];
int dfs (int pz,int val)
{
    fv[pz]=val;
    for(int i=0;i<v[pz].size();++i)
        if(!fv[v[pz][i]])
            dfs(v[pz][i],val+1);
}
int main()
{
    int d,k,i,j,t,n;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>cst[0][i];
    for(i=1;i<=n;++i)
        cin>>cst[1][i];
    for(i=1;i<=n;++i)
        cin>>cst[2][i];
    for(i=1;i<n;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(i=1;i<=n;++i)
    {
        if(v[i].size()>2)
        {
            cout<<-1;
            return 0;
        }
    }
    for(i=1;i<=n;++i)
    {
        if(v[i].size()==1)
        {
            dfs(i,1);
            break;
        }
    }
    for(i=1;i<=n;++i)
        vn[fv[i]]=i;
    long long mn=999999000000999LL;
    for(int a=0;a<=2;++a)
        for(int b=0;b<=2;++b)
        {
            if(a==b)
                continue;
            long long sc=0;
            sc=cst[a][vn[1]]+cst[b][vn[2]];
            int pra=a,prb=b;
            vcur[1]=a;
            vcur[2]=b;
            for(i=3;i<=n;++i)
            {
                int nou=3-pra-prb;
                sc+=cst[nou][vn[i]];
                pra=prb;
                prb=nou;
                vcur[i]=nou;
            }
            if(sc<mn)
            {
                mn=sc;
                for(i=1;i<=n;++i)
                    vbest[i]=vcur[i];
            }
        }
    cout<<mn<<'\n';
    for(i=1;i<=n;++i)
        fv[vn[i]]=vbest[i];
    for(i=1;i<=n;++i)
        cout<<fv[i]+1<<' ';
    return 0;
}