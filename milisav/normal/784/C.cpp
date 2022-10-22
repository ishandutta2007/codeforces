#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int n;
int a[15];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    int na=a[0];
    for(int i=1;i<n;i++) if(a[i]>na) na=a[i];
    na=na^a[n-1];

    printf("%d",na);
    return 0;
}