#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m;
  int n, n1, n2;
  int in[111111];
  int cnt[6];
  int nn1[6], nn2[6], go;

  while(scanf("%d%d%d",&n,&n1,&n2)==3){
    rep(i,n) scanf("%d",in+i);
    rep(i,6) cnt[i]=0;
    rep(i,n) cnt[in[i]]++;

    if(n1==n2){
      rep(i,n){
        if(i) putchar(' ');
        if(i<n1) putchar('1'); else putchar('2');
      }
      puts(""); continue;
    }

    rep(i,6) nn1[i] = nn2[i] = 0;

    go = n1; if(n1<n2) go = n2;
    rep(i,6){
      k = cnt[i];
      if(k > go) k = go;
      go -= k;
      nn1[i] += k;
      nn2[i] += cnt[i]-k;
    }

    if(n1 < n2){
      rep(i,6) k=nn1[i], nn1[i]=nn2[i], nn2[i]=k;
    }

    rep(i,n){
      if(i) putchar(' ');
      if(nn1[in[i]]>0){ putchar('1'); nn1[in[i]]--; }
      else            { putchar('2'); nn2[in[i]]--; }
    }
    puts("");
  }

  return 0;
}