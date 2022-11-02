#include<bits/stdc++.h>
int n,k,sum=0;
int l;
int main()
{
    scanf("%d",&n);
    for(k=1;k<=n;k++)
    {
        scanf("%d",&l);
        sum+=(4*(k-1))*l;
    }
    printf("%d",sum);
    return 0;
}