#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100000
#define int long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int t;
int n;

int cal2(int l,int r,int x)
{
    if(l==r) return l;
    int len=r-l+1;
    int step=len/4;

    if(x<=len/4)
    {
        return cal2(l,l+step-1,x);
    }
    else if(x<=len/2)
    {
        return cal2(l+2*step,l+3*step-1,x-step);
    }
    else if(x<=3*step)
    {
        return cal2(l+3*step,l+4*step-1,x-2*step);
    }
    else return cal2(l+step,l+2*step-1,x-3*step);
}

int cal3(int l,int r,int x)
{
    if(l==r) return l;

    int len=r-l+1;
    int step=len/4;

    if(x<=len/4)
    {
        return cal3(l,l+step-1,x);
    }
    else if(x<=len/2)
    {
        return cal3(l+3*step,l+4*step-1,x-step);
    }
    else if(x<=3*step)
    {
        return cal3(l+1*step,l+2*step-1,x-2*step);
    }
    else return cal3(l+2*step,l+3*step-1,x-3*step);
}
int bin[N];
main()
{
//    freopen("me.out","w",stdout);
    bin[0]=1;
    for(int i=1;i<=70;i++) bin[i]=bin[i-1]<<1;
    t=read();
    while(t--)
    {
        int qq=read();

        n=qq/3+1;
        if(qq%3==0) n--;

        int m=0;
        int p=0;
        while(m<n)
        {
            m+=bin[p+1]-bin[p];
            p+=2;
        }

        p-=2;

        int len=bin[p+1]-bin[p];
        int tmp=m-n;
        int re=len-tmp;

        int fi=bin[p]+re-1;
    //    cerr<<re<<' '<<p<<endl;
        if(qq%3==1)
        {
            printf("%lld\n",fi);
        }
        else if(qq%3==2)
        {
            printf("%lld\n",cal2(bin[p],bin[p+1]-1,re)+bin[p]);
        }
        else
        {
            printf("%lld\n",cal3(bin[p],bin[p+1]-1,re)+bin[p]*2);
        }

    }
}