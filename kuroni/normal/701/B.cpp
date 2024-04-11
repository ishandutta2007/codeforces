#include<bits/stdc++.h>
using namespace std;
main()
{
    ios_base::sync_with_stdio(0);
    bool row[100001],col[100001];
    long long i=0,n,m,x,y,rep,r=0,c=0;
    memset(row,0,sizeof(row));
    memset(col,0,sizeof(col));
    for(cin>>n>>m,rep=n*n;i<m;i++)
    {
        cin>>x>>y;
        r+=!row[x],c+=!col[y];
        rep-=n*2-2-row[x]*(n-1)-col[y]*(n-1)-(col[y]?0:r-1)-(row[x]?0:c-1)+(!row[x]&&!col[y]);
        row[x]=true,col[y]=true;
        cout<<rep<<" ";
    }
}