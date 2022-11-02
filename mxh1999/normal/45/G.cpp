//Author:mxh1999
//
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n,sum;
int a[6010];
int bo[40000010];
int prime[2000010];
int tot;

void getprime(int n)
{
    for (int i=2;i<n;i++)
    {
        if (!bo[i]) prime[tot++]=i;
        for (int j=0;j<tot && i*prime[j]<n;j++)
        {
            bo[i*prime[j]]=1;
            if (!(i%prime[j]))  break;
        }
    }
    return;
}
int main()
{
    scanf("%d",&n);
    sum=n*(n+1)/2;
    bo[1]=true;
    getprime(sum+1);
    for (int i=prime[tot-1]+1;i<=sum;i++)   bo[i]=true;
    //printf("%d\n",tot);
    if (!bo[sum])
    {
        for (int i=1;i<=n;i++)
        {
            printf("1 ");
        }
        printf("\n");
        return 0;
    }
    if (sum%2==1)
    {
        if (!bo[sum-2])
        {
            for (int i=1;i<=n;i++)
            if (i==2)   printf("2 ");else printf("1 ");
            printf("\n");
            return 0;
        }   else
        {
            int t=n;
            while (bo[t])   t--;
            a[t]=3;
            sum-=t;
        }
    }
    if (sum%2==0)
    {
        for (int j=sum-2;j>1;j--)
        if (!bo[j] && !bo[sum-j])
        {
            int pos=n,tmp=j;
            while (tmp)
            {
                while (pos>tmp || a[pos])
                {
                    if (pos>tmp)    pos=tmp;else pos--;
                }
                a[pos]=1;
                tmp-=pos;
            }
            for (int i=1;i<=n;i++)
            if (a[i]==0)    printf("2 ");else printf("%d ",a[i]);
            return 0;
        }
    }
    return 0;
}