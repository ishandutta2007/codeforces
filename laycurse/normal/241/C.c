#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define H 100
#define W 100000
#define EPS 1e-8

int upScore[10000], upLeft[10000], upRight[10000], upSize;
int downScore[10000], downLeft[10000], downRight[10000], downSize;
int hLeft, hRight;

int main(){
  int i,j,k,l,m,n,loop,r,sum;
  int a, b;
  int res = 0, tmp;
  char buf[10];

  scanf("%d%d%d",&hLeft,&hRight,&n);
  upSize = downSize = 0;

  while(n--){
    scanf("%d%s%d%d\n",&i,buf,&j,&k);
    if(buf[0]=='T'){
      upScore[upSize] = i;
      upLeft [upSize] = j;
      upRight[upSize] = k;
      upSize++;
    } else {
      downScore[downSize] = i;
      downLeft [downSize] = j;
      downRight[downSize] = k;
      downSize++;
    }
  }

  rep(k,upSize) REP(i,1,upSize) if(upLeft[i-1] > upLeft[i]){
    m = upScore[i-1]; upScore[i-1] = upScore[i]; upScore[i] = m;
    m = upLeft[i-1]; upLeft[i-1] = upLeft[i]; upLeft[i] = m;
    m = upRight[i-1]; upRight[i-1] = upRight[i]; upRight[i] = m;
  }
  rep(k,downSize) REP(i,1,downSize) if(downLeft[i-1] > downLeft[i]){
    m = downScore[i-1]; downScore[i-1] = downScore[i]; downScore[i] = m;
    m = downLeft[i-1]; downLeft[i-1] = downLeft[i]; downLeft[i] = m;
    m = downRight[i-1]; downRight[i-1] = downRight[i]; downRight[i] = m;
  }

  sum = upSize + downSize;
  rep(loop,2){
    rep(r,sum+2){
      double dist, dir, ss;
      int uu = -1, dd = -1, cur = 0;

      dist = hLeft + hRight + 2*H*(r/2);
      if(r%2) dist += (H-hRight)*2;
      
      dir = W / dist;
      ss = hLeft * dir;

      rep(i,r+1){
        if(i%2==0){
          dd++;
          while(dd < downSize && downRight[dd] < ss-EPS) dd++;
          if(dd < downSize && downLeft[dd] < ss+EPS && ss-EPS < downRight[dd]){
            cur += downScore[dd];
          } else {
            cur = 0;
            break;
          }
        } else {
          uu++;
          while(uu < upSize && upRight[uu] < ss-EPS) uu++;
          if(uu < upSize && upLeft[uu] < ss+EPS && ss-EPS < upRight[uu]){
            cur += upScore[uu];
          } else {
            cur = 0;
            break;
          }
        }
        if(i!=r) ss += H * dir;
      }

      if(res < cur) res = cur;
    }
    
    n = upSize;
    if(n < downSize) n = downSize;
    rep(i,n){
      m = upScore[i]; upScore[i] = downScore[i]; downScore[i] = m;
      m = upLeft[i]; upLeft[i] = downLeft[i]; downLeft[i] = m;
      m = upRight[i]; upRight[i] = downRight[i]; downRight[i] = m;
    }
    n = upSize; upSize = downSize; downSize = n;
    hLeft = H - hLeft;
    hRight = H - hRight;
  }
  
  printf("%d\n",res);
  return 0;
}