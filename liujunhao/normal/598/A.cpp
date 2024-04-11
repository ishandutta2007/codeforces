#include<cstdio>
typedef long long LL;
LL n,sum;
int T;
void Read(LL &x){
    char c;
    while(c=getchar(),c!=EOF)
        if(c>='0'&&c<='9'){
            x=c-'0';
            while(c=getchar(),c>='0'&&c<='9')
                x=x*10+c-'0';
            ungetc(c,stdin);
            return;
        }
}
int main()
{
    scanf("%d",&T);
    while(T--){
        LL a;
        Read(n);
        sum=n*(n+1)/2;
        a=1;
        while(a<=n){
            sum-=2*a;
            a*=2;
        }
        printf("%I64d\n",sum);
    }
}