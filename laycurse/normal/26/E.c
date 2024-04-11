#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)


int get_mini(int in[],int n){
  int i,k,mx=100000;
  rep(i,n) if(in[i] && mx>in[i]) mx=in[i], k=i;
  return k;
}

int get_mx(int in[],int n){
  int i,k,mx=-1;
  rep(i,n) if(mx<in[i]) mx=in[i], k=i;
  return k;
}

int main(){
  int i,j,k,l,m,n,W;
  int in[120], sum, now;

  scanf("%d%d",&n,&W);
  rep(i,n) scanf("%d",in+i);
  if(W<=0){ puts("No"); return 0; }

  sum=0;
  rep(i,n) sum+=in[i];
  now=get_mini(in,n);
  
  if(W>sum){ puts("No"); return 0; }
  if(n==1 && W!=sum){ puts("No"); return 0; }
  if(in[now]>1 && W==1){ puts("No"); return 0; }

  puts("Yes");

  if(W >= in[now]){
    k = sum-W;
    printf("%d",now+1);
    rep(i,n) if(i!=now){
      while(in[i] > 0 && k > 0){
        printf(" %d %d",i+1,i+1);
        in[i]--; k--;
      }
    }
    printf(" %d",now+1); in[now]--;
    rep(i,n) while(in[i] > 0){ printf(" %d %d",i+1,i+1); in[i]--; }
  } else {
    rep(k,n) if(k!=now) break;
    printf("%d",k+1);
    while(in[now]>1) printf(" %d %d",now+1,now+1), in[now]--;
    printf(" %d %d",k+1,now+1); in[k]--;

    sum=0;
    rep(i,n) sum += in[i];
    k = sum - W + 1;

    rep(i,n) if(i!=now){
      while(in[i] > 0 && k > 0){
        printf(" %d %d",i+1,i+1);
        in[i]--; k--;
      }
    }
    printf(" %d",now+1); in[now]--;
    rep(i,n) while(in[i] > 0){ printf(" %d %d",i+1,i+1); in[i]--; }
  }
  
  puts("");

  return 0;
}