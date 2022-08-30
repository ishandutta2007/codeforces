#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int ab(int x){if(x<0) return -x; return x;}

int main(){
  int i,j,k,l,m,n,g;
  char *r[5]={"S","M","L","XL","XXL"};
  char in[6];
  int rest[5];

  rep(i,5) scanf("%d",rest+i);
  scanf("%d",&n);
  while(n--){
    scanf("%s",in);
    if(in[0]=='S') k=0;
    if(in[0]=='M') k=1;
    if(in[0]=='L') k=2;
    if(in[0]=='X' && in[1]=='L') k=3;
    if(in[0]=='X' && in[1]=='X') k=4;

    m=10;
    rep(i,5) if(rest[i]){
      j = ab(i-k);
      if(m >= j) m=j, g=i;
    }
    rest[g]--; puts(r[g]);
  }

  return 0;
}