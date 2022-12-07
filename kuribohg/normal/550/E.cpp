#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100010;
int n,a[MAXN],sub;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    if(a[n]==1) {puts("NO");return 0;}
    if(n==1) {puts("YES");puts("0");return 0;}
    if(a[n]==0&&a[n-1]==1)
    {
        puts("YES");
        for(int i=1;i<n;i++) printf("%d->",a[i]);
        printf("%d\n",a[n]);
        return 0;
    }
    for(int i=1;i<n-1;i++) if(a[i]==0) sub=i;
    if(!sub) {puts("NO");return 0;}
    puts("YES");
    for(int i=1;i<sub;i++) printf("%d->",a[i]);
    putchar('(');
    printf("%d->",a[sub]);
    putchar('(');
    for(int i=sub+1;i<n-1;i++) printf("%d->",a[i]);
    printf("%d",a[n-1]);
    putchar(')'),putchar(')'),putchar('-'),putchar('>');
    printf("%d\n",a[n]);
    return 0;
}