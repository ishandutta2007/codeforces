#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100000
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m;
int a[N],ans;
int lsum1[N],lsum2[N];
int rsum1[N],rsum2[N];
inline int Mx(int a,int b)
{return a>b?a:b;}
inline int Mn(int a,int b)
{return a<b?a:b;}

void init()
{
    n=read();
    for(int i=1;i<=n;i++)
    a[i]=read();
    for(int i=1;i<=n;i++)
    lsum1[i]=lsum1[i-1]+(a[i]==1),lsum2[i]=lsum2[i-1]+(a[i]==2);
	for(int i=n;i;i--)
    rsum1[i]=rsum1[i+1]+(a[i]==1),rsum2[i]=rsum2[i+1]+(a[i]==2);
}
int main()
{

    init();
    for(int i=1;i<=n;i++)
    {
        int tmp=lsum2[i-1]+rsum1[i];
        int pos=i-1;
        for(int j=i;j<=n;j++)
        {
            if(lsum2[j]+rsum1[j+1]>tmp)
            tmp=lsum2[j]+rsum1[j+1],pos=j;
            int sav=lsum1[i-1]-lsum2[i-1]+rsum1[pos+1]+rsum2[j+1]+lsum2[pos]-rsum1[j+1];
            ans=Mx(ans,sav);
        }
    }

    printf("%d\n",ans);
}