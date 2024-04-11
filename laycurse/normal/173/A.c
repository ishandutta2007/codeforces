#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int win(char a, char b){
  if(a==b) return 0;
  if(a=='R' && b=='P') return -1;
  if(a=='P' && b=='S') return -1;
  if(a=='S' && b=='R') return -1;
  return 1;
}

int main(){
  int i,j,k,l,m,n,p;
  char a[1200], b[1200]; int as, bs;
  int res1, res2, c1, c2;

  scanf("%d%s%s",&n,a,b);
  as = strlen(a);
  bs = strlen(b);
  p = as*bs;

  res1 = res2 = c1 = c2 = 0;

  rep(i,p){
    k = win(a[i%as], b[i%bs]);
    if(k==0) continue;
    if(k<0) c1++; else c2++;
  }

  res1 += (n/p) * c1;
  res2 += (n/p) * c2;

  n %= p;
  rep(i,n){
    k = win(a[i%as], b[i%bs]);
    if(k==0) continue;
    if(k<0) res1++; else res2++;
  }

  printf("%d %d\n", res1, res2);

  return 0;
}