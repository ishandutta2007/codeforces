#include<cstdio>
int a,b;
int main()
{
    scanf("%d%d",&a,&b);
    if(a<b){
        int t=a;
        a=b;
        b=t;
    }
    printf("%d %d\n",b,(a-b)/2);
}