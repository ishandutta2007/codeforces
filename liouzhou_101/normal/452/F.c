#include <stdio.h>
#include <string.h>
int a[1<<21][2],n,M;
char str[10000000],*p=str;
int getint(){
    int re=0;
    while(*p<'0'||*p>'9')p++;
    while(*p>='0'&&*p<='9')re=re*10+*p++-48;
    return re;
}
void Update(int i){
    int P=101;i+=M-1;
    for(a[i][0]=a[i][1]=1;i>>=1;P=P*P)a[i][0]=a[i<<1][0]*P+a[i<<1^1][0],a[i][1]=a[i<<1^1][1]*P+a[i<<1][1];
}
int Query(int i,int j,_Bool c){
    int ans[2]={0,0},P=101,lP=1,rP=1;
#define link(a,b,c,lP,rP) c?b*lP+a:a*rP+b
    for(i+=M-2,j+=M;i^j^1;i>>=1,j>>=1,P*=P){
        if(~i&1)ans[0]=link(ans[0],a[i^1][c],c,lP,P),lP*=P;
        if(j&1)ans[1]=link(a[j^1][c],ans[1],c,P,rP),rP*=P;
    }return link(ans[0],ans[1],c,lP,rP);
}
int main(){
    int t,i,s,k;fread(p,1,10000000,stdin);
    for(t=1;t--;puts(i==-1?"NO":"YES"))for(memset(a,0,(M=1<<32-__builtin_clz((i=n=getint())-1))<<4);i--;Update(s))if((s=getint())!=1&&s!=n){
        k=s-1>n-s?n-s:s-1;
        if(Query(s-k,s-1,1)!=Query(s+1,s+k,0)){while(*p++!='\n');break;}
    }return 0;
}