#include <bits/stdc++.h>

using namespace std;
int vit[10],st[10],dr[10],cr[10],rz[10];
struct ura
{
    int i,j;
}q[1000003][10];
char v[1001][1001];
int oc[1001][1001],d[1001][1001];
const int dx[]={0,0,1,-1};
const int dy[]={-1,1,0,0};
int main()
{
    long long p,add=1,t,h,n,i,j,mn=100003LL*100003LL,k,mx=0,tot,m,obj,cnt=0,cnti=0,s=0,nri=0,b=0,a2,b2,a3,b3;
    char c;
    cin>>n>>m>>p;
    for(i=1;i<=p;++i)
        cin>>vit[i];
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
        {
            cin>>v[i][j];
            if(v[i][j]=='#')
                oc[i][j]=-1;
            else
            if(v[i][j]!='.')
            {
                oc[i][j]=v[i][j]-'0';
                d[i][j]=1;
                q[++dr[v[i][j]-'0']][v[i][j]-'0'].i=i;
                q[  dr[v[i][j]-'0']][v[i][j]-'0'].j=j;
            }
        }
    for(i=1;i<=p;++i)
        st[i]=1;
    while(1)
    {
        for(i=1;i<=p;++i)
            if(st[i]<=dr[i])
                break;
        if(i==p+1)
            break;
        for(int cur=1;cur<=p;++cur)
        {
            cr[cur]+=vit[cur];
            while(st[cur]<=dr[cur] && d[q[st[cur]][cur].i][q[st[cur]][cur].j]<=cr[cur])
            {
                int ic=q[st[cur]][cur].i;
                int jc=q[st[cur]][cur].j;
                for(i=0;i<=3;++i)
                {
                    int in=ic+dx[i];
                    int jn=jc+dy[i];
                    if(in==0 || jn==0 || in==n+1 || jn==m+1)
                        continue;
                    if(!oc[in][jn])
                    {
                        oc[in][jn]=cur;
                        d[in][jn]=1+d[ic][jc];
                        q[++dr[cur]][cur].i=in;
                        q[  dr[cur]][cur].j=jn;
                    }
                }
                ++st[cur];
            }
        }
    }
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            if(oc[i][j]>=1)
                ++rz[oc[i][j]];
    for(i=1;i<=p;++i)
        cout<<rz[i]<<' ';
    return 0;
}