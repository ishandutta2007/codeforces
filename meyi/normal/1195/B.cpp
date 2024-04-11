#include<cstdio>
int k,n;
inline bool check(register int x){
    return (long long)x*(x+3)*0.5<=n+k;
}
main(){
    scanf("%d%d",&n,&k);
    register int l=0,r=n,s;
    while(l<=r){
        register int m=l+r>>1;
        if(check(m))l=m+1,s=m;
        else r=m-1;
    }
    printf("%d",n-s);
}