#include <bits/stdc++.h>
using namespace std;
map <int,bool>viz;
int q[1000006];
int dst[1000006];
int v[200005];
int rzf[200005];
int main()
{
    long long n,t,i,j,k=0,pas=1<<20,m,mx=0,sc,rz=0;
    cin>>n>>m;
    int st=1,dr=0;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        viz[v[i]]=1;
        q[++dr]=v[i];
        dst[dr]=0;
    }
    while(st<=n+m)
    {
        int nc=q[st];
        int dstc=dst[st++];
        rz+=dstc;
        viz[nc]=1;
        if(st>n+1)
        {
            rzf[st-n-1]=nc;
        }
        if(!viz[nc-1])
        {
            q[++dr]=nc-1;
            dst[dr]=dstc+1;
            viz[nc-1]=1;
        }
        if(!viz[nc+1])
        {
            q[++dr]=nc+1;
            dst[dr]=dstc+1;
            viz[nc+1]=1;
        }
    }
    cout<<rz<<'\n';
    for(i=1;i<=m;++i)
        cout<<rzf[i]<<' ';
    return 0;
}