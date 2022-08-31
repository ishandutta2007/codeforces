#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  int a[4], cmd=0;

  scanf("%d%d%d%d",a,a+1,a+2,a+3);
  for(;;){
/*    printf("%d : %d %d %d %d\n",cmd,a[0],a[1],a[2],a[3]);*/
    if(a[0]==1 && a[1]==1 && a[2]==1 && a[3]==1) break;

    cmd++;
    
    rep(i,4) if(a[i]%2==0 && a[(i+1)%4]%2==0) break;
    if(i<4){
      a[i]/=2; a[(i+1)%4]/=2;
      printf("/%d\n",i+1);
      continue;
    }

    rep(i,4) if(a[i]+a[(i+1)%4]!=2 && a[i]%2==1 && a[(i+1)%4]%2==1) break;
    if(i<4){
      a[i]++; a[(i+1)%4]++;
      printf("+%d\n",i+1);
      continue;
    }

    m=0;
    rep(i,4) if(m<a[i]+a[(i+1)%4]) m=a[i]+a[(i+1)%4], k=i;
    a[k]++; a[(k+1)%4]++;
    printf("+%d\n",k+1);
  }

  return 0;
}