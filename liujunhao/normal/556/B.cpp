#include<cstdio>
#define MAXN 1000
int a[MAXN+10],n;
int main()
{
    int delta,i;
    scanf("%d",&n);
    scanf("%d",&a[0]);
    delta=a[0];
    for(i=1;i<n;i++){
        scanf("%d",&a[i]);
        if(i&1)
            a[i]=(a[i]+delta)%n;
        else
            a[i]=(a[i]+n-delta)%n;
        if(a[i]!=i)
            break;
    }
    if(i==n)
        puts("Yes");
    else
        puts("No");
}