#include<bits/stdc++.h>
using namespace std;
int n,mod=1e9+7,i,j,l=1;
long long s=1;
char a[100009];
int b[100009];
int main()
{
    scanf("%s",&a);
    for(i=1;i<=mod;i++)
    {
        if(a[i]==' ')
        {
            break;
        }
    }
    for(j=0;j<=i;j++)
    {
        if(a[j]=='a')
        {
            b[l]++;
        }
        if(a[j]=='b')
        {
            l++;
            //printf("%d\n",b[l-1]);
        }
    }
    //printf("%d\n",b[l]);
    for(i=1;i<=l;i++)
    {
        s*=(b[i]+1);
        s=s%mod;
    }
    s=s-1;
    if(s==-1)
    {
        s=s+mod;
    }
    printf("%lld",s);
    return 0;
}