#include <bits/stdc++.h>
using namespace std;
const int maxn=600005;
const int maxlog=21;
char s[maxn];
int n,logn,rk[maxlog][maxn],sa[maxlog][maxn],sz[maxn],b[maxn],t[maxn],h[maxn],fa[maxn];
long long ans[maxn],x[maxn],y[maxn],z[maxn];
int father(int x) { return (x==fa[x])?x:(fa[x]=father(fa[x])); }
inline bool cmp(const int &x,const int &y)
{
    return h[x]>h[y];
}
inline void init_sa()
{
    register int i,j,k;
    register bool flag;
    for(logn=1;(1<<logn)<n;logn++);
    for(i=0;i<128;i++)
        sz[i]=0;
    for(i=0;i<n;i++)
        sz[s[i]]++;
    for(i=1;i<128;i++)
        sz[i]+=sz[i-1];
    for(i=n-1;i>=0;i--)
        rk[0][i]=sz[s[i]-1];
    for(i=1;i<=logn;i++)
    {
        for(j=0;j<=n;j++)
            sz[j]=0;
        for(j=0;j<n;j++)
            t[j]=(j+(1<<(i-1))<n)?rk[i-1][j+(1<<(i-1))]+1:0;
        for(j=0;j<n;j++)
            sz[t[j]]++;
        for(j=1;j<=n;j++)
            sz[j]+=sz[j-1];
        for(j=n-1;j>=0;j--)
            b[--sz[t[j]]]=j;
        for(j=0;j<n;j++)
            sz[j]=0;
        for(j=0;j<n;j++)
            sz[rk[i-1][j]]++;
        for(j=1;j<n;j++)
            sz[j]+=sz[j-1];
        for(j=n-1;j>=0;j--)
            sa[i][rk[i][b[j]]=--sz[rk[i-1][b[j]]]]=b[j];
        flag=true;
        for(j=1;j<n;j++)
            if(rk[i-1][sa[i][j-1]]==rk[i-1][sa[i][j]] && t[sa[i][j-1]]==t[sa[i][j]])
                rk[i][sa[i][j]]=rk[i][sa[i][j-1]],flag=false;
        if(flag)
        {
            for(i++;i<=logn;i++)
            {
                memcpy(rk[i],rk[i-1],sizeof(int)*n);
                memcpy(sa[i],sa[i-1],sizeof(int)*n);
            }
            break;
        }
    }
    h[0]=-1;
    for(i=0;i<n;i++) t[i]=i;
    for(i=0,k=0;i<n;i++)
    {
        if(k) k--;
        if(!rk[logn][i]) continue;
        j=sa[logn][rk[logn][i]-1];
        while(s[i+k]==s[j+k]) k++;
        h[rk[logn][i]]=k;
    }
    sort(t,t+n,cmp);
}
int main()
{
    int p,q,r,m;
    register int i,j;
    // scanf("%d%d%d",&p,&q,&r); n=p+q+r+2; m=min(p,min(q,r));
    // scanf("%s%s%s",s,s+p+1,s+p+q+2); s[p]='+'; s[p+q+1]='-';
    scanf("%s",s),p=strlen(s),s[p]='+';
    scanf("%s",s+p+1),q=strlen(s+p+1),s[p+q+1]='-';
    scanf("%s",s+p+q+2),r=strlen(s+p+q+2);
    n=p+q+r+2; m=min(p,min(q,r));
    init_sa();
    for(i=0;i<n;i++)
    {
        fa[i]=i; x[i]=y[i]=z[i]=0;
        if(sa[logn][i]<p) x[i]=1;
        else if(sa[logn][i]<=p+q) y[i]=1;
        else z[i]=1;
    }
    // printf(" 0: %s\n",s+sa[logn][0]);
    // for(i=1;i<n;i++)
    //     printf("%d\n%2d: %s\n",h[i],i,s+sa[logn][i]);
    ans[m+1]=0;
    for(i=0;i<n;i++) fa[i]=i;
    for(i=m,j=0;i>=1;i--)
    {
        ans[i]=ans[i+1];
        for(;j<n && h[t[j]]>=i;j++)
        {
            father(t[j]-1); father(t[j]);
            // printf("%d %d\n",t[j]-1,t[j]);
            ans[i]-=x[fa[t[j]]]*y[fa[t[j]]]*z[fa[t[j]]];
            ans[i]-=x[fa[t[j]-1]]*y[fa[t[j]-1]]*z[fa[t[j]-1]];
            x[fa[t[j]]]+=x[fa[t[j]-1]];
            y[fa[t[j]]]+=y[fa[t[j]-1]];
            z[fa[t[j]]]+=z[fa[t[j]-1]];
            fa[fa[t[j]-1]]=fa[t[j]];
            ans[i]+=x[fa[t[j]]]*y[fa[t[j]]]*z[fa[t[j]]];
        }
    }
    for(i=1;i<m;i++) printf("%I64d ",ans[i]%1000000007);
    printf("%I64d\n",ans[i]%1000000007);
    return 0;
}