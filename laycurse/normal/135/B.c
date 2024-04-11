#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

void intReverse(int d[],int size){int a=0,b=size-1,t;while(a<b)t=d[a],d[a]=d[b],d[b]=t,a++,b--;}
int intNextPermutation(int d[],int size){int i,j,k;for(k=size-2;k>=0;k--)if(d[k]<d[k+1])break;if(k<0){intReverse(d,size);return 0;}for(i=size-1;;i--)if(d[i]>d[k])break;j=d[i],d[i]=d[k],d[k]=j;intReverse(d+k+1,size-k-1);return 1;}


int x[10], y[10];

int is_right(int a, int b, int c){
  int dx1 = x[b] - x[a];
  int dx2 = x[c] - x[a];
  int dy1 = y[b] - y[a];
  int dy2 = y[c] - y[a];

  if(dx1*dx2 + dy1*dy2 == 0) return 1;
  return 0;
}

int len(int a, int b){
  int dx = x[a] - x[b];
  int dy = y[a] - y[b];
  return dx * dx + dy * dy;
}

int is_rect(int a, int b, int c, int d){
  if( !is_right(a, b, d) ) return 0;
  if( !is_right(b, c, a) ) return 0;
  if( !is_right(c, d, b) ) return 0;
  if( !is_right(d, a, c) ) return 0;
  return 1;
}

int is_square(int a, int b, int c, int d){
  int dist = len(a, b);
  if(dist != len(b, c)) return 0;
  if(dist != len(c, d)) return 0;
  if(dist != len(d, a)) return 0;
  if(!is_rect(a, b, c, d)) return 0;
  return 1;
}

int main(){
  int i,j,k,l,m,n;
  int d[8];
  int ok = 0;

  rep(i,8) scanf("%d%d",x+i,y+i);
  rep(i,8) d[i] = i;

  do{
    if( !is_square(d[0], d[1], d[2], d[3]) ) continue;
    if( !is_rect  (d[4], d[5], d[6], d[7]) ) continue;
    rep(i,8) d[i]++;

    ok = 1;
    puts("YES");
    printf("%d %d %d %d\n",d[0],d[1],d[2],d[3]);
    printf("%d %d %d %d\n",d[4],d[5],d[6],d[7]);
    break;
  }while(intNextPermutation(d,8));

  if(!ok) puts("NO");

  return 0;
}