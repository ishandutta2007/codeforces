#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define INF 1000000000
int mp[111][111];

int ab(int a){if(a<0) return -a; return a;}

int main(){
  int i,j,k,l,m,n,q;
  int r1,r2,r3;
  int x,y1,y2,opt,tmp;

  scanf("%d%d",&q,&n);
  rep(i,n) rep(j,n) mp[i][j]=0;

  while(q--){
    scanf("%d",&m); opt=INF;
    rep(x,n) rep(y1,n-m+1){
      y2 = y1+m;
      REP(i,y1,y2) if(mp[x][i]) break;
      if(i<y2) continue;

      tmp=0;
      REP(i,y1,y2) tmp += ab((n+1)/2 - x-1) + ab((n+1)/2 - i-1);
      if(tmp < opt) opt=tmp, r1=x, r2=y1, r3=y2;
    }
    if(opt==INF){puts("-1"); continue;}
    printf("%d %d %d\n",r1+1,r2+1,r3);
    REP(i,r2,r3) mp[r1][i]=1;
  }

  return 0;
}