#include<cstdio>
const int MOD=1e9+7;
int p,k;
int quick_pow(int a,int b){
    int ret=1;
    while(b){
        if(b&1)
            ret=1ll*ret*a%MOD;
        a=1ll*a*a%MOD;
        b>>=1;
    }
    return ret;
}
int main()
{
    scanf("%d%d",&p,&k);
    if(k==0)
        printf("%d\n",quick_pow(p,p-1));
    else if(k==1)
        printf("%d\n",quick_pow(p,p));
    else{
        int m=1,t=k;
        for(;t!=1;m++)
            t=1ll*t*k%p;
        printf("%d\n",quick_pow(p,(p-1)/m));
    }
}