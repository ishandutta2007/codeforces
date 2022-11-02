#include<bits/stdc++.h>
using namespace std;

#define maxn 110
int a[maxn],n,m;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        char ch=getchar();
        while (ch<'0' || ch>'9')    ch=getchar();
        int x=ch-'0';
        if (x==1)   continue;
        if (x==2)   a[++m]=2;
        if (x==3)   a[++m]=3;
        if (x==4)   a[++m]=3,a[++m]=2,a[++m]=2;
        if (x==5)   a[++m]=5;
        if (x==6)   a[++m]=5,a[++m]=3;
        if (x==7)   a[++m]=7;
        if (x==8)   a[++m]=7,a[++m]=2,a[++m]=2,a[++m]=2;
        if (x==9)   a[++m]=7,a[++m]=3,a[++m]=3,a[++m]=2;
    }
    sort(a+1,a+m+1);
    for (int i=m;i>=1;i--)  printf("%d",a[i]);
    printf("\n");
    return 0;
}