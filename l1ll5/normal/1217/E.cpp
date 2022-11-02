#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 200005
using namespace std;
char xB[1<<15],*xS=xB,*xT=xB;
#define getchar() (xS==xT&&(xT=(xS=xB)+fread(xB,1,1<<15,stdin),xS==xT)?0:*xS++)
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m;
int flag=0;
int a[N];

#define pr pair<int,int>
#define fi first
#define se second

pr merge(pr a,pr b)
{
    int m1=min(a.fi,b.fi);
    int m2=max(a.fi,b.fi);

    int aa,bb;
    aa=m1;
    bb=min(m2,min(a.se,b.se));

    return make_pair(aa,bb);
}

struct seg
{
    int mn1[N<<2];
    int mn2[N<<2];
    int mn3[N<<2];

    void build()
    {
        for(int i=0;i<N-5;i++) mn1[i]=mn2[i]=2e9+7;
        for(int i=0;i<N-5;i++) mn3[i]=2e9+7;
    }

    #define ls (x<<1)
    #define rs (x<<1|1)

    void pushup(int x)
    {
        int m1=min(mn1[ls],mn1[rs]);
        int m2=max(mn1[ls],mn1[rs]);

        mn1[x]=m1;
        mn2[x]=min(m2,min(mn2[ls],mn2[rs]));

        mn3[x]=mn1[x]+mn2[x];
    }

    void upd(int x,int l,int r,int p,int v)
    {
        if(l==r)
        {
            if(flag)
            mn1[x]=v;
            else mn1[x]=1e9+7;
            mn2[x]=1e9+7;
            mn3[x]=2e9+7;
            return ;
        }
        int mid=(l+r)>>1;
        if(p<=mid) upd(x<<1,l,mid,p,v);
        else upd(x<<1|1,mid+1,r,p,v);
        pushup(x);
    }

    pr ask(int x,int l,int r,int L,int R)
    {
        if(l>=L&&r<=R)
        {
            return make_pair(mn1[x],mn2[x]);
        }

        int mid=(l+r)>>1;
        pr ret=make_pair(2e9,2e9);
        if(L<=mid) ret=merge(ret,ask(x<<1,l,mid,L,R));
        if(R>mid ) ret=merge(ret,ask(x<<1|1,mid+1,r,L,R));
        return ret;
    }

}T[12];
main()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=0;i<=9;i++) T[i].build();

    for(int i=1;i<=n;i++)
    {
        int tmp=a[i];
        for(int j=0;j<=9;j++)
        {
            int x=tmp%10;

            if(x!=0) flag=1;
            else flag=0;

            T[j].upd(1,1,n,i,a[i]);

            tmp/=10;
        }
    }

    while(m--)
    {
        int opt=read();
        int l=read(),r=read();
        if(opt==1)
        {
            a[l]=r;
            int tmp=a[l];
            for(int i=0;i<=9;i++)
            {
                int x=tmp%10;

                if(x!=0) flag=1;
                else flag=0;

                T[i].upd(1,1,n,l,a[l]);
                tmp/=10;
            }
        }
        else
        {
            int ans=2e9+5;
            for(int i=0;i<=9;i++)
            {
                pr tmp=T[i].ask(1,1,n,l,r);
                if(tmp.se<=1e9) ans=min(ans,tmp.se+tmp.fi);
        //        ans=min(ans,T[i].ask(1,1,n,l,r));
        //        cerr<<T[i].ask(1,1,n,l,r)<<endl;
            }
        //    cerr<<ans<<endl;
            if(ans>2e9) ans=-1;
            printf("%d\n",ans);
        }
    }
}