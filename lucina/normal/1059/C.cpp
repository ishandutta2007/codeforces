#include<stdio.h>
int n;
int main(){
scanf("%d",&n);
int gcd=1;
while(n!=0){
if(n==3){
   printf("%d %d %d ",gcd,gcd,3*gcd);
  break;
}
for(int i=1;i<=n;i+=2){
printf("%d ",gcd);
}
n=n/2,gcd=gcd*2;
}
}