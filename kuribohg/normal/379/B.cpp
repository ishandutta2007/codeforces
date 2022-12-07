#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100010;
int n,a[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=300;i++)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]) putchar('P'),a[i]--;
            if(i!=n) putchar('R');
        }
        for(int i=1;i<n;i++) putchar('L');
    }
    return 0;
}