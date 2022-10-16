#include <bits/stdc++.h>

using namespace std;
int dst[105][105];
int q[105],viz[105];
vector <int> v[105];
int bfs (int pz)
{
    int st=1,dr=1;
    q[st]=pz;
    viz[pz]=1;
    while(st<=dr)
    {
        int nod=q[st];
        for(int i=0;i<v[nod].size();++i)
        {
            int nn=v[nod][i];
            if(!viz[nn])
                viz[nn]=1,q[++dr]=nn,dst[pz][nn]=1+dst[pz][nod];
        }
        ++st;
    }
}
int p[1000006];
int rz[1000006];
int main()
{
    ios_base::sync_with_stdio(0);
    long long l,r,n,m,i,j,mx1=0,mx2=0,s=0,cntm1=0,cnt1=0,cnt=0;
    cin>>n;
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
        {
            char a;
            cin>>a;
            dst[i][j]=a-'0';
            if(a=='1')
                v[i].push_back(j);
        }
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=n;++j)
            viz[j]=0;
        bfs(i);
    }
    cin>>m;
    for(i=1;i<=m;++i)
        cin>>p[i];
    i=1;
    rz[++cnt]=p[1];
    while(i<m)
    {
        int pas=1<<20,k=i;
        while(pas)
        {
            if(k+pas<=m && dst[p[i]][p[k+pas]]==k+pas-i)
                k+=pas;
            pas>>=1;
        }
        i=k;
        rz[++cnt]=p[i];
    }
    cout<<cnt<<'\n';
    for(i=1;i<=cnt;++i)
        cout<<rz[i]<<' ';
	return 0;
}