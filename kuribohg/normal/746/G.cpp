#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=400010;
int n,t,k,L,R,tot;
int a[MAXN],s[MAXN],f[MAXN];
int main()
{
    scanf("%d%d%d",&n,&t,&k);
    for(int i=1;i<=t;i++) scanf("%d",&a[i]);
    for(int i=1;i<t;i++)
    {
        int low=max(a[i]-a[i+1],0);
        k-=low;
        s[i]=a[i]-1-low;
        f[i]=low;
    }
    k-=a[t];
    if(k<0) {puts("-1");return 0;}
    for(int i=1;i<t;i++)
    {
        if(k>=s[i]) f[i]+=s[i],k-=s[i];
        else f[i]+=k,k=0;
    }
    if(k>0) {puts("-1");return 0;}
    printf("%d\n",n);
    for(int i=1;i<=a[1];i++) printf("1 %d\n",i+1);
    tot=a[1]+1,L=2,R=tot;
    for(int i=2;i<=t;i++)
    {
        int r=a[i-1]-f[i-1]+L-1,o=a[i];
        while(o)
        {
            for(int k=L;k<=r;k++)
            {
                printf("%d %d\n",k,++tot);
                o--;
                if(o==0) break;
            }
        }
        L=R+1,R=tot;
    }
    return 0;
}