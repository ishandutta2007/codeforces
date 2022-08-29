#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

int getPrime(int n,int p[]){int i,j,n2=n/2;rep(i,n2)p[i]=1;for(i=3;i*i<n;i+=2)if(p[i>>1])for(j=(i*i)>>1;j<n2;j+=i)p[j]=0;j=1;p[0]=2;REP(i,1,n2)if(p[i])p[j++]=i*2+1;return j;}
int ps, p[100000];

int fac[100010][20], fac_size[100010];
int now_num[100010];
int is_on[100010];

int main(){
  int i,j,k,l,m,n,ok;
  int q;
  char buf[10];

  ps = getPrime(100000, p);

  rep(i,100010) fac_size[i] = 0;
  rep(i,ps){
    for(j=p[i];j<100010;j+=p[i]) fac[j][fac_size[j]++] = i;
  }

  rep(i,ps) now_num[i] = -1;
  rep(i,100010) is_on[i] = 0;

  scanf("%d%d",&n,&q);
  while(q--){
    scanf("%s%d",buf,&k);
    if(buf[0]=='+'){
      if(is_on[k]){ puts("Already on"); continue; }
      ok = -1;
      rep(i,fac_size[k]) if(now_num[fac[k][i]] >= 0) ok = now_num[fac[k][i]];
      if(ok >= 0){ printf("Conflict with %d\n", ok); continue; }
      puts("Success");
      rep(i,fac_size[k]) now_num[fac[k][i]] = k;
      is_on[k] = 1;
    } else {
      if(is_on[k]==0){ puts("Already off"); continue; }
      puts("Success");
      rep(i,fac_size[k]) now_num[fac[k][i]] = -1;
      is_on[k] = 0;
    }
  }
  
  return 0;
}