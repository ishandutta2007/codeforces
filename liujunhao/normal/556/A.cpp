#include<cstdio>
int n,c0,c1;
int main()
{
    int i;
    scanf("%d\n",&n);
    for(i=1;i<=n;i++){
        if(getchar()=='0')
            c0++;
        else
            c1++;
    }
    printf("%d\n",n-2*(c0<c1?c0:c1));
}