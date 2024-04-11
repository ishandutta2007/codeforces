#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int ab(int x){ if(x<0)return -x; return x; }

int main(){
  int i,j,k,l,m,n,st;
  int x[666], y[666];
  int in[666], used[666];
  int res[666];

  scanf("%d%d",&n,&m);
  rep(i,n) scanf("%d%d",x+i,y+i);
  rep(i,m) scanf("%d",in+i);

  rep(st,2){
    rep(i,n) res[i]=-1;
    rep(i,m) used[i]=0;

    for(i=st;i<n;i+=2){
      k  = 0;
      k += ab(x[i]-x[(i+n-1)%n]) + ab(y[i]-y[(i+n-1)%n]);
      k += ab(x[i]-x[(i+n+1)%n]) + ab(y[i]-y[(i+n+1)%n]);
      rep(j,m) if(in[j]==k && used[j]==0) break;
      if(j==m) break;
      res[i] = j+1; used[j]=1;
    }
    if(i>=n){
      puts("YES");
      rep(i,n){
        if(i) putchar(' ');
        printf("%d",res[i]);
      }
      puts("");
      return 0;
    }
  }
  puts("NO");
  
  return 0;
}