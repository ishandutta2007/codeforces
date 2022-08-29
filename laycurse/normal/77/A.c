#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
#define ull unsigned ll

#define ULL_HASH_SIZE 2000
ull ull_hash_n[ULL_HASH_SIZE]; int ull_hash_d[ULL_HASH_SIZE];

void ullHashClear(void){ memset(ull_hash_d,0,ULL_HASH_SIZE*sizeof(int)); }
int ullHashFunction(ull a){ return (a*1007)%ULL_HASH_SIZE; }

int ullHashGet(ull a){
  int i=ullHashFunction(a);
  for(;;){
    if(ull_hash_n[i]==a && ull_hash_d[i]) break;
    if(!ull_hash_d[i]) break;
    i++; if(i==ULL_HASH_SIZE) i=0;
  }
  if(ull_hash_n[i]!=a) return 0; return ull_hash_d[i];
}

void ullHashSet(ull a,int n){
  int i=ullHashFunction(a);
  for(;;){
    if(ull_hash_n[i]==a && ull_hash_d[i]) break;
    if(!ull_hash_d[i]) break;
    i++; if(i==ULL_HASH_SIZE) i=0;
  }
  ull_hash_n[i]=a; ull_hash_d[i]=n;
}

int ullHashIncrease(ull a){
  int i=ullHashFunction(a);
  for(;;){
    if(ull_hash_n[i]==a && ull_hash_d[i]) break;
    if(!ull_hash_d[i]) break;
    i++; if(i==ULL_HASH_SIZE) i=0;
  }
  ull_hash_n[i]=a; return ++ull_hash_d[i];
}

int number;
char tmp_string[1000];

int get_next(void){
  int i; ull hs=0;
  scanf("%s",tmp_string);
  for(i=0;;i++){
    if(tmp_string[i]<' ') break;
    hs = hs*1007+tmp_string[i];
  }
  i=ullHashGet(hs); if(i>0) return i-1;
  ullHashSet(hs,number+1); return number++;
}

void get_clear(void){
  number=0; ullHashClear();
}


int n;
int edge[10][10];
int now[7];
int res1, res2;
int gain[3];

void solve(int depth){
  int i,j,k;
  int tmp1, tmp2, mx, mi;

  if(depth==n){
    mx = 0; mi = 2000000000;
    rep(i,3){
      k = 0;
      rep(j,n) if(now[j]==i) k++;
      if(!k) return;

      k = gain[i] / k;
      if(mx < k) mx = k;
      if(mi > k) mi = k;
    }
    tmp1 = mx-mi;

    tmp2 = 0;
    rep(i,n) rep(j,n) if(now[i]==now[j]) tmp2 += edge[i][j];

    if(res1 > tmp1 || (res1==tmp1 && res2<tmp2)){
      res1 = tmp1; res2 = tmp2;
    }

    return;
  }

  rep(i,3){
    now[depth]=i;
    solve(depth+1);
  }
}

int main(){
  int i,j,k,l,m;

  n=7;

  while(scanf("%d",&m)==1){
    get_clear();
    res1 = 2000000000; res2 = 0;

    rep(i,n) rep(j,n) edge[i][j] = 0;
    while(m--){
      i=get_next();
      scanf("%*s");
      j=get_next();
      edge[i][j]=1;
    }
    rep(i,3) scanf("%d",gain+i);
    solve(0);

    printf("%d %d\n",res1,res2);
  }

  return 0;
}