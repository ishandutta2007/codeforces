#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int a, b, c, pw, add;

  scanf("%d%d",&a,&c);
  b = 0; pw = 1;

  while(a || c){
    add = ((c%3) - (a%3) + 3)%3;
    b += add * pw;
    pw *= 3;
    a /= 3; c /= 3;
  }

  printf("%d\n",b);

  return 0;
}