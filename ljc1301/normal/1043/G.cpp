#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
const int maxlog=19;
const int maxsz=30;
int n,suf[maxn][maxsz],minp[maxn],p[maxn],tot,minr[maxn],minl[maxn],minR[maxn];
int lg[maxn],R[2][maxn];
char s[maxn];
struct SA
{
    int h[maxlog][maxn],rk[maxn],sa[maxn];
    inline void build()
    {
        int i,k,l,*x=h[0],*y=rk,m=128;
        for(i=0;i<m;i++) p[i]=0;
        for(i=0;i<n;i++) p[x[i]=s[i]]++;
        for(i=1;i<m;i++) p[i]+=p[i-1];
        for(i=0;i<n;i++) sa[--p[x[i]]]=i;
        for(k=1;;k<<=1)
        {
            for(i=n-k,l=0;i<n;i++) y[l++]=i;
            for(i=0;i<n;i++)
                if(sa[i]>=k)
                    y[l++]=sa[i]-k;
            for(i=0;i<m;i++) p[i]=0;
            for(i=0;i<n;i++) p[x[i]]++;
            for(i=1;i<m;i++) p[i]+=p[i-1];
            for(i=n-1;i>=0;i--) sa[--p[x[y[i]]]]=y[i];
            for(swap(x,y),x[sa[0]]=0,m=1,i=1;i<n;i++)
                x[sa[i]]=(y[sa[i]]==y[sa[i-1]] && (sa[i]+k<n)==(sa[i-1]+k<n) &&
                    (sa[i]+k>=n || y[sa[i]+k]==y[sa[i-1]+k]))?m-1:(m++);
            if(m>=n) break;
        }
        for(i=0;i<n;i++) rk[sa[i]]=i;
        for(h[0][n-1]=0,l=0,i=0;i<n;i++)
        {
            if(l) l--;
            if(!rk[i]) continue;
            while(s[i+l]==s[sa[rk[i]-1]+l]) l++;
            h[0][rk[i]-1]=l;
        }
        // for(i=0;i<n;i++)
        // {
        //     printf("%s\n",s+sa[i]);
        //     if(i==n-1) break;
        //     for(k=0;k<h[0][i];k++)
        //         printf("|");
        //     printf("\n");
        // }
        for(k=1;k<=lg[n];k++)
            for(i=0;i+(1<<k)<=n;i++)
                h[k][i]=min(h[k-1][i],h[k-1][i+(1<<(k-1))]);
    }
    inline int lcp(int x,int y)
    {
        if(x==y) return n-x;
        int k;
        x=rk[x],y=rk[y];
        if(x>y) swap(x,y);
        y--,k=lg[y-x+1];
        return min(h[k][x],h[k][y-(1<<k)+1]);
    }
}sa[2];
inline void sieve()
{
    int i,j;
    for(i=1,tot=0;i<=n;i++) minp[i]=i;
    for(i=2;i<=n;i++)
    {
        if(minp[i]==i) p[tot++]=i;
        for(j=0;j<tot && i*(long long)p[j]<=n;j++)
        {
            minp[i*p[j]]=p[j];
            if(!(i%p[j])) break;
        }
    }
}
inline bool check1(int l,int r)
{
    int L=r-l+1,t=L,p;
    for(;t>1;)
    {
        p=minp[t];
        if(sa[0].lcp(l,l+L/p)>=L-L/p) return true;
        for(;!(t%p);t/=p);
    }
    return false;
}
int findR(int _,int x) { return (R[_][x]==x)?x:(R[_][x]=findR(_,R[_][x])); }
inline void updatel(int l,int r,int x)
{
    // printf("updatel %d %d %d\n",l,r,x);
    if(l>r) return;
    for(;(l=findR(0,l))<=r;R[0][l]=l+1)
        minl[l]=x;
}
inline void updater(int l,int r,int x)
{
    // printf("updater %d %d %d\n",l,r,x);
    if(l>r) return;
    for(;(l=findR(1,l))<=r;R[1][l]=l+1)
        minr[l]=x;
}
int main()
{
    int i,q,l,r,x,y;
    scanf("%d%s%d",&n,s,&q),s[n]='\0';
    sieve();
    for(lg[1]=0,i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
    reverse(s,s+n),sa[1].build(),reverse(s,s+n),sa[0].build();
    // for(i=1;i<=n;i++) printf("%d ",minp[i]); printf("\n");
    for(i=0;i<=n;i++)
        for(l=0;l<maxsz;l++)
            suf[i][l]=0;
    for(i=0;i<n;i++) suf[i][s[i]-'a']=1;
    for(i=n-1;i>=0;i--)
        for(l=0;l<maxsz;l++)
            suf[i][l]+=suf[i+1][l];
    // if every letter occurs <=1 times: no solution
    // else ...a..a... ans<=4
    // ans=1? cycle
    // if s[l] occurs >=2 times or s[r] occurs >=2 times
    //   a...a... ans<=3
    //   ans=2: A...A or A...B
    //   ABA or AAB or ABB or AB...AB -> ABA
    //   ABA or AAB or ABB
    // else a....c A(no A or C)C ans>=3
    //   ans=3 <=> ABBC

    // find AA:
    for(i=0;i<=n;i++) R[0][i]=R[1][i]=i;
    for(i=0;i<n;i++) minl[i]=minr[i]=n;
    for(l=1;(l<<1)<=n;l++)
        for(i=l-1;i+l<n;i+=l)
        {
            x=min(sa[0].lcp(i,i+l),l),y=min(sa[1].lcp(n-1-i,n-1-l-i),l);
            // L~L+l-1, L+l~L+2l-1
            // L+l-1-i+1<=x L<=i-l+x
            // i-L+1<=y L>=i+1-y
            updater(i+1-y,i-l+x,l),updatel(i-y+(l<<1),i+l+x-1,l);
        }
    // for(i=0;i<n;i++) printf("%d ",minl[i]); printf("\n");
    // for(i=0;i<n;i++) printf("%d ",minr[i]); printf("\n");
    for(minR[n]=n,i=n-1;i>=0;i--) minR[i]=min(minR[i+1],i+(minr[i]<<1));
    for(i=0,x=0;i<n-1;i++) x=max(x,sa[0].h[0][i]);
    // fprintf(stderr,"%d\n",x);
    while(q--)
    {
        scanf("%d%d",&l,&r),l--,r--;
        // if every letter occurs <=1 times: no solution
        for(i=0;i<maxsz;i++)
            if(suf[l][i]-suf[r+1][i]>=2)
                break;
        if(i>=maxsz) { printf("-1\n"); continue; }
        // else ...a..a... ans<=4
        // ans=1: cycle
        if(check1(l,r)) { printf("1\n"); continue; }
        if(suf[l][s[l]-'a']-suf[r+1][s[l]-'a']>=2
            || suf[l][s[r]-'a']-suf[r+1][s[r]-'a']>=2)
        {
            if(r-l+1>=(min(minr[l],minl[r])<<1)) { printf("2\n"); continue; }
            // for(i=1,y=1;i<=x && (i<<1)<=r-l+1 && y;i++)
            //     if(sa[0].lcp(l,r-i+1)>=i)
            //         y=0;
            // printf("%d\n",y?3:2);

            // solution's idea:
            // BAB: find the shortest B
            // then B: can't represent as CDC
            // at most occurs n/|B| times
            for(i=1,y=1;i<=x && (i<<1)<=r-l+1 && y && i*i<=n;i++)
                if(sa[0].lcp(l,r-i+1)>=i)
                    y=0;
            if(i>x || (i<<1)>r-l+1 || !y) { printf("%d\n",y?3:2); continue; }
            for(y=i,i=max(0,sa[0].rk[l]-y);i<=sa[0].rk[l]+y && i<n;i++)
                if(l<sa[0].sa[i] && sa[0].sa[i]<=r && sa[0].lcp(l,sa[0].sa[i])>=r-sa[0].sa[i]+1)
                    y=-y-1;
            printf("%d\n",(y>=0)?3:2);
        }
        else printf("%d\n",(r>=minR[l])?3:4);
    }
    return 0;
}