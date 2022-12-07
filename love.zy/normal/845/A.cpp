#include<bits/stdc++.h>
using namespace std;

const int maxn=200005;
int a[maxn],n;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++)scanf("%d",&a[i]);
    sort(a+1,a+2*n+1);
    if(a[n]<a[n+1])printf("YES\n");else printf("NO\n");
    return 0;
}