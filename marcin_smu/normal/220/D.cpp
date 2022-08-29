#include<cstdio>
#define m 1000000007
typedef long long LL;
LL w,h;
LL wyn;
int gcd(int a,int b){
 while(b){
  int pom=b;
  b=a%b;
  a=pom;
 }
 return a;
}
main(){
 scanf("%d%d",&w,&h);
 w++;h++;
 wyn=w*h;
 wyn=wyn*(wyn-1)%m*(wyn-2)%m;
 LL a=((w+1)/2)*((h+1)/2);
 LL b=(w/2)*((h+1)/2);
 LL c=((w+1)/2)*(h/2);
 LL d=(w/2)*(h/2);
 wyn-=6*a*b%m*c%m;
 wyn-=6*a*b%m*d%m;
 wyn-=6*a*d%m*c%m;
 wyn-=6*d*b%m*c%m;
 wyn-=w*h*(h-1)%m*(h-2)%m;
 wyn-=w*h*(w-1)%m*(w-2)%m;
 wyn%=m;
 for(int i=1;i<w;i++){
  for(int j=1;j<h;j++){
   wyn-=(gcd(i,j)-1)*(w-i)*(h-j)*12;
   wyn%=m;
  }
 }
 printf("%d\n",int((wyn+m)%m));
}