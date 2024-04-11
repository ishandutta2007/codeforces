#include<stdio.h>
long long int n,i,g,l,k,m,s,p,o;
long long int a[2001],b[2001];
long long int f[2001];
long long int F[2001][2001];
int main(){
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        b[i]=0;
    }
    for(i=1;i<=n;i++)
    {
        if(a[i]>=0)
        {
            b[a[i]]=1;
        }
    }
    g=0;
    l=0;
    for(i=1;i<=n;i++)
    {
        if(a[i]<=0)
        {
            g++;
            if(b[i]==0)
            {
                l++;
            }
        }
    }
    F[1][0]=1;
    F[0][0]=1;
    F[1][1]=1;
    for(k=2;k<=n;k++)
    {

        for(m=0;m<=k;m++)
        {
            if(m!=k && m!=0)
                F[k][m]=F[k-1][m]+F[k-1][m-1];
            else
                F[k][m]=1;
            F[k][m]=F[k][m]%1000000007;
        }
    }
    o=0;
    f[0]=1;
    for(p=1;p<=2001;p++)
    {
        f[p]=p*f[p-1];
        f[p]=f[p]%1000000007;
    }
    for(k=0;k<=l;k++)
    {
        if(k%2==0)
        {
            o+=f[g-k]*F[l][k];
            o=o%1000000007;
        }
        else
        {
            o-=f[g-k]*F[l][k];
            o=(o%1000000007+1000000007)%1000000007;
        }
    }
    printf("%lld",o);
    return 0;
}