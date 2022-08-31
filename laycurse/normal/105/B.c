#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int N, K;
int use[8];
int per[8];
int level[8];
int A;
double res;

void dfs(int depth, int st){
  int i,j,sum,all,dame;
  double p, ok, tmp;

  if(depth == K){
    tmp = 0;
    rep(i,1<<N){
      p = 1; sum = all = dame = 0;
      rep(j,N){
        all += 1;
        if(i&1<<j) sum += 1;
        else       dame += level[j];

        ok = (per[j] + use[j]*10) / 100.0;
        if(ok > 1) ok = 1;
        
        if(i&1<<j) p *= ok;
        else       p *= 1-ok;
      }

      if(all < 2*sum) tmp += p;
      else            tmp += p * A / (A+dame);
    }
    if(res < tmp) res = tmp;
    return;
  }

  REP(i,st,N){
    use[i]++;
    dfs(depth+1, i);
    use[i]--;
  }
}

int main(){
  int i,j,l,m;
  int sum;

  while(scanf("%d%d%d",&N,&K,&A)==3){
    rep(i,N) scanf("%d%d",level+i,per+i);
    res = 0;
    dfs(0,0);
    printf("%.10lf\n",res);
  }

  return 0;
}