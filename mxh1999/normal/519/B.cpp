//Author:mxh1999
//
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

#define maxn 100010
int n;
int a[maxn],b[maxn],c[maxn];
map<int,int>    A,B,C;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        A[a[i]]++;
    }
    for (int i=1;i<n;i++)
    {
        scanf("%d",&b[i]);
        B[b[i]]++;
    }
    for (int i=1;i<n-1;i++)
    {
        scanf("%d",&c[i]);
        C[c[i]]++;
    }
    for (int i=1;i<=n;i++)
    if (A[a[i]]!=B[a[i]])
    {
        printf("%d\n",a[i]);
        break;
    }
    for (int i=1;i<n;i++)
    if (B[b[i]]!=C[b[i]])
    {
        printf("%d\n",b[i]);
        break;
    }
    return 0;
}