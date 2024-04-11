#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n,q;
  int a,b;

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  scanf("%d%d",&q,&k);
  while(q--){
    scanf("%d%d",&a,&b); a--; b--;
    if(k==1){
      if(a%2==1||b%2==1) puts("+"); else puts("-");
      continue;
    }
    if(a>b) m=a, a=b, b=m;
    b-=a;
    a %= 2*(k+1);
    if(a==k || a==2*k+1){puts("+"); continue;}
    if(a<=k) b++;
    if(b%2) puts("-"); else puts("+");
  }

  return 0;
}