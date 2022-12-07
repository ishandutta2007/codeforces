#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[10010],tmp[10010];
int n,m,l,r,k;
int main()
{
    scanf("%s%d",s,&m);
    n=strlen(s);
    while(m--)
    {
        scanf("%d%d%d",&l,&r,&k);
        l--,r--;
        k%=r-l+1;
        for(int i=0;i<l;i++) tmp[i]=s[i];
        for(int i=r+1;i<n;i++) tmp[i]=s[i];
        int sub=l;
        if(k!=0) sub=r+1-k;
        for(int i=l;i<=r;i++)
        {
            tmp[i]=s[sub];
            sub++;
            if(sub==r+1) sub=l;
        }
        for(int i=0;i<n;i++) s[i]=tmp[i];
    }
    puts(s);
    return 0;
}