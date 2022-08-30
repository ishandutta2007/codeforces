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

int get_next(char tmp_string[], int len){
  int i; ull hs=0;
  rep(i,len){
    if(tmp_string[i]<' ') break;
    hs = hs*1007+tmp_string[i];
  }
  i=ullHashGet(hs); if(i>0) return i-1;
  ullHashSet(hs,number+1); return number++;
}

void get_clear(void){
  number=0; ullHashClear();
}


int get_len(char a[]){
  int i;
  for(i=0;;i++) if(a[i]<' ') break;
  return i;
}

#define INF 1000000000

int main(){
  int i,j,k,l,m,n;
  char a[1000], b[1000], c[1000];
  int as, bs, an, bn;
  int fst, sec;
  int d[1000];

  char *init_a = "void";
  char *init_b = "errtype";

  while(scanf("%d",&n)==1){
    get_clear();
    rep(i,1000) d[i] = INF;

    an = get_next(init_a, get_len(init_a));
    d[an] = 0;
    bn = get_next(init_b, get_len(init_b));
    d[bn] = INF;

    while(n--){
      scanf("%s%s",c,a);
      
      as = get_len(a);
      fst = sec = 0;
      while(a[fst]=='&') fst++;
      while(a[as-1-sec]=='*') sec++;
      an = get_next(a+fst, as-fst-sec);
      
      if(c[4]=='d'){
        scanf("%s",b);
        bs = get_len(b);
        bn = get_next(b,bs);

        k = d[an];
        if(k<INF) k += sec - fst;
        if(k<0) k = INF;
        d[bn] = k;
      } else {
        k = d[an];
        if(k==INF){ puts(init_b); continue; }
        k += sec - fst;
        if(k<0){ puts(init_b); continue; }
        printf("%s",init_a);
        while(k--) putchar('*');
        puts("");
      }
    }
  }


  return 0;
}