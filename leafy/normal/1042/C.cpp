#include<bits/stdc++.h>
using namespace std;
const int N=200005,inf=0x7f7f7f7f;
int n;
int a[N],z[N],ntz[N];
int main()
{
    scanf("%d",&n);
    int num=0,s=0,mx=-inf,p;
    int num1=0;
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        if(a[i]==0) z[++num]=i;
        else ntz[++num1]=i;
        if(a[i]<0)
        {
            s++;
            if(a[i]>mx) mx=a[i],p=i;
        }
    }
    if(num==0&&s%2==0)
    {
        for(int i=1;i<=n-1;i++)
            printf("1 %d %d\n",i,i+1);
        return 0;
    }
    if(num>0&&s%2==1)
    {
        for(int i=1;i<num;i++) printf("1 %d %d\n",z[i],z[i+1]);
        printf("1 %d %d\n",z[num],p);
        if(num!=n-1) printf("2 %d\n",p);
        for(int i=1;i<num1;i++) 
        {
            if(ntz[i]==p||(i==num1-1&&ntz[num1]==p)) continue;
            printf("1 %d %d\n",ntz[i],ntz[i+1]==p?ntz[i+2]:ntz[i+1]);
        }
        return 0;
    }
    if(num>0&&s%2==0)
    {
        for(int i=1;i<num;i++) printf("1 %d %d\n",z[i],z[i+1]);
        if(num!=n) printf("2 %d\n",z[num]);
        for(int i=1;i<num1;i++) printf("1 %d %d\n",ntz[i],ntz[i+1]);
        return 0;
    }
    printf("2 %d\n",p);
    for(int i=1;i<n;i++)
    {
        if(i==p||(i==n-1&&n==p)) continue;
        printf("1 %d %d\n",i,i+1==p?i+2:i+1);
    }
    return 0;
}