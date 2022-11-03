#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
const int maxlogn=20;
int n,l[maxn],r[maxn],m,pos[maxn];
char s[maxn],t[maxn];
int sa[maxn],rk[maxn],h[maxn],sz[maxn];
int minn[maxlogn][maxn],logn;
inline int query(int i,int j)
{
    int k;
    if(i>j) swap(i,j); j--;
    for(k=0;(2<<k)<j-i+1;k++);
    return min(minn[k][i],minn[k][j-(1<<k)+1]);
}
inline bool check(int l1,int r1,int l2,int r2)
{
    if(r1-l1!=r2-l2) return false;
    if(l1==l2) return true;
    return query(rk[l1-1]+1,rk[l2-1]+1)>=r1-l1+1;
}
inline void SA(char *s,int n)
{
    int i,*x=rk,*y=h,m=128,k,p,j; s[n]='\0';
    for(i=0;i<m;i++) sz[i]=0;
    for(i=0;i<n;i++) sz[x[i]=s[i]]++;
    for(i=1;i<m;i++) sz[i]+=sz[i-1];
    for(i=n-1;i>=0;i--) sa[--sz[x[i]]]=i;
    for(k=1;;k<<=1)
    {
        for(i=n-k/**/,p=0;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++)
            if(sa[i]>=k)
                y[p++]=sa[i]-k;
        for(i=0;i<m;i++) sz[i]=0;
        for(i=0;i<n;i++) sz[x[i]]++;
        for(i=1;i<m;i++) sz[i]+=sz[i-1];
        for(i=n-1;i>=0;i--) sa[--sz[x[y[i]]]]=y[i];
        swap(x,y);
        for(x[sa[0]]=0,i=1,p=1;i<n;i++)
            x[sa[i]]=(y[sa[i]]==y[sa[i-1/**/]] && (sa[i]</**/n-k)==(sa[i-1]<n-k) && (sa[i]>=n-k || y[sa[i]+k]==y[sa[i-1]+k]))?p-1:(p++);
        if(p>=n) break; /**/
        m=p;/**/
    }
    for(i=0;i<n;i++) rk[sa[i]]=i;
    for(h[0]=p=0,i=0;i<n;i++)
    {
        if(p) p--;
        if(!rk[i]) continue;
        while(s[i+p]==s[sa[rk[i]-1]+p]) p++;
        h[rk[i]]=p;
    }
    for(i=1;i<=n;i++) minn[0][i]=h[i];
    for(logn=0;(1<<(logn+1))<=n;logn++);
    for(i=1;i<=logn;i++)
        for(j=1;j+i-1<=n;j++)
            minn[i][j]=min(minn[i-1][j],minn[i-1][j+(1<<(i-1))]);
}
int main()
{
    int q,i,l1,r1,l2,r2;
    scanf("%d%s",&n,s+1),s[0]=s[n+1]='\0';
    for(i=1;i<=n;i++) l[i]=(s[i]==s[i-1])?l[i-1]:i;
    for(i=n;i>=1;i--) r[i]=(s[i]==s[i+1])?r[i+1]:i;
    m=0,t[0]='\0';
    for(i=1;i<=n;i++)
    {
        t[++m]=s[i],pos[i]=m;
        if(t[m]=='1' && t[m-1]=='1') m-=2;
    }
    SA(t+1,m);
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d%d",&l1,&l2,&i),r1=l1+i-1,r2=l2+i-1;
        if(r[l1]>=r1 || r[l2]>=r2)
        {
            printf("%s\n",(r[l1]>=r1 && r[l2]>=r2 && s[l1]==s[l2])?"Yes":"No");
            continue;
        }
        if(s[l1]=='1')
        {
            if((r[l1]-l1+1)%2==1)
                if(s[l2]=='0' || (r[l2]-l2+1)%2==0)
                {
                    printf("No\n");
                    continue;
                }
                else l1=r[l1]+1,l2=r[l2]+1;
            else if(s[l2]=='0' || (r[l2]-l2+1)%2==0)
            {
                l1=r[l1]+1;
                if(s[l2]=='1') l2=r[l2]+1;
            }
            else
            {
                printf("No\n");
                continue;
            }
        }
        else if(s[l2]=='1')
        {
            if(s[l2]=='0' || (r[l2]-l2+1)%2==0)
            {
                if(s[l2]=='1') l2=r[l2]+1;
            }
            else
            {
                printf("No\n");
                continue;
            }
        }
        if(s[r1]=='1')
        {
            if((r1-l[r1]+1)%2==1)
                if(s[r2]=='0' || (r2-l[r2]+1)%2==0)
                {
                    printf("No\n");
                    continue;
                }
                else r1=l[r1]-1,r2=l[r2]-1;
            else if(s[r2]=='0' || (r2-l[r2]+1)%2==0)
            {
                r1=l[r1]-1;
                if(s[r2]=='1') r2=l[r2]-1;
            }
            else
            {
                printf("No\n");
                continue;
            }
        }
        else if(s[r2]=='1')
        {
            if(s[r2]=='0' || (r2-l[r2]+1)%2==0)
            {
                if(s[r2]=='1') r2=l[r2]-1;
            }
            else
            {
                printf("No\n");
                continue;
            }
        }
        // printf("%s %d %d %d %d\n",t+1,pos[l1],pos[r1],pos[l2],pos[r2]);
        printf("%s\n",check(pos[l1],pos[r1],pos[l2],pos[r2])?"Yes":"No");
    }
    return 0;
}