#include<stdio.h>
int main(void)
{
    long long int n,m,k,t,ans=0;
    scanf("%I64d%I64d%I64d",&n,&m,&k);
    if(n>m) {t=m;m=n;n=t;} //n<m
    if(k>n+m-2) printf("-1");
    else if(k<n)
    {
        if((n/(k+1))*m>(m/(k+1))*n) printf("%I64d",(n/(k+1))*m);
        else printf("%I64d",(m/(k+1))*n);
    }
    else if(n<=k&&k<m) printf("%I64d",(m/(k+1))*n);
    else
    {
        if(m/(k-n+2)>n/(k-m+2)) printf("%I64d",m/(k-n+2));
        else printf("%I64d",n/(k-m+2));
    }
}