#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

char a[11000], b[1100000];
int as, bs;

int next[11000][26];

int main(){
  int i,j,k,l,m,n;
  int res, now;

  while(scanf("%s%s",a,b)==2){
    for(as=0;;as++) if(a[as]<' ') break;
    for(bs=0;;bs++) if(b[bs]<' ') break;

    rep(i,as) a[i] -= 'a';
    rep(i,bs) b[i] -= 'a';

    res = 1;
    rep(i,as+1){
      rep(j,26) next[i][j] = -1;
      REP(k,i,as) if(next[i][a[k]]==-1) next[i][a[k]] = k;
    }

    now = 0;
    rep(i,bs){
      if(next[now][b[i]]==-1){
        if(now==0){ res=-1; break; }
        res++; now=0; i--; continue;
      }

      now = next[now][b[i]]+1;
    }

    printf("%d\n",res);
  }

  return 0;
}