#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int n,x;
int a[N],b[N],c[N],d[N];
int main()
{
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]),b[a[i]]++,c[i]=a[i]&x,d[c[i]]++;
        if(b[a[i]]>=2) {printf("0");return 0;}
    }
    for(int i=1;i<=n;i++)
    {
        b[a[i]]--;
        if(b[c[i]]>=1) {printf("1");return 0;}
        b[a[i]]++;
    }
    for(int i=1;i<=n;i++) if(d[c[i]]>=2) {printf("2");return 0;}
    printf("-1");
    return 0;
}