#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=5010;
int n,a[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int x=n-a[1];
    for(int i=1;i<=n;i+=2) a[i]=(a[i]+x)%n;
    for(int i=2;i<=n;i+=2) a[i]=(a[i]-x+n)%n;
    for(int i=1;i<=n;i++) if(a[i]!=i-1) {puts("No");return 0;}
    puts("Yes");
    return 0;
}