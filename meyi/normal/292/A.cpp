#include<cstdio>
int a,c,n,s,t,x;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&t,&c);
        x+=a-t;
        if(x<0)x=0;
        x+=c;
        if(x>s)s=x;
        a=t;
    }
    return printf("%d %d",t+x,s),0;
}