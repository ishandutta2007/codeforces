#include<cstdio>
int main(void){
long long t,x,y;
scanf("%lld",&t);
for(long long i=0;i<t;i++){
scanf("%lld %lld",&x,&y);
printf("%lld\n",x+y);
}
return 0;
}