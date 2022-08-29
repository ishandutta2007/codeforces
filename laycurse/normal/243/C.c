#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

void intSort(int d[],int s){int i=-1,j=s,k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;}intSort(d,i);intSort(d+j+1,s-j-1);}

/* d[] 1resres */
/*  d sorted */
int intUnique(int d[],int size,int res[]){
  int i,n=1;
  if(size==0) return 0;
  res[0]=d[0];
  REP(i,1,size) if(d[i]!=d[i-1]) res[n++] = d[i];
  return n;
}

/* d[i]=sa<=i<b-1d[]sorted */
int intArrayBinarySearch(int d[],int s,int a,int b){
  int c = (a+b)/2;
  if(a>=b) return -1;
  if(d[c]==s) return c;
  if(d[c]>s) return intArrayBinarySearch(d,s,a,c);
  return intArrayBinarySearch(d,s,c+1,b);
}

/* dres */
/* d={2,5,3,3,6,5} -> res={0,2,1,1,3,2} */
/* return res+1 (res) */
int intReduction(int d[],int size,int res[],void *WorkMemory){
  int i,j,k,unique_size;
  int *sorted_d,*unique_d;

  sorted_d = (int*) WorkMemory; WorkMemory = (void*) (sorted_d + size);
  unique_d = (int*) WorkMemory;

  rep(i,size) sorted_d[i]=d[i]; intSort(sorted_d,size);
  unique_size = intUnique(sorted_d,size,unique_d);

  rep(i,size) res[i] = intArrayBinarySearch(unique_d,d[i],0,unique_size);
  return unique_size;
}

int mp[3100][3100];
int st[9100000], st_size;

int x[4000], y[4000];
int X[4000], Y[4000], RX[4000], RY[4000];
int XS, YS;

int rx[4000], ry[4000];
int cnvX[4000], cnvY[4000];

int main(){
  int i,j,k,l,m,n;
  int cx, cy, nx, ny, dx[4]={1,-1,0,0}, dy[4]={0,0,-1,1}, d;
  ll res;
  void *mem = malloc(1000000);
  char mode[10];

  scanf("%d",&n); n++;
  cx = cy = x[0] = y[0] = 0;

  REP(i,1,n){
    scanf("%s%d",mode,&l);
    if(mode[0]=='R') cx += l;
    if(mode[0]=='L') cx -= l;
    if(mode[0]=='U') cy += l;
    if(mode[0]=='D') cy -= l;
    x[i] = cx; y[i] = cy;
  }

  rep(i,n){
    X[3*i+0] = x[i];
    X[3*i+1] = x[i]-1;
    X[3*i+2] = x[i]+1;
    Y[3*i+0] = y[i];
    Y[3*i+1] = y[i]-1;
    Y[3*i+2] = y[i]+1;
  }

  XS = intReduction(X, 3*n, RX, mem);
  YS = intReduction(Y, 3*n, RY, mem);

  rep(i,3*n) cnvX[RX[i]] = X[i], cnvY[RY[i]] = Y[i];

  rep(i,n) rx[i] = RX[3*i], ry[i] = RY[3*i];
  rep(i,XS) rep(j,YS) mp[i][j] = 0;

  REP(i,1,n){
    if(rx[i] != rx[i-1]){
      REP(j,rx[i-1],rx[i]+1) mp[j][ry[i]] = 1;
      REP(j,rx[i],rx[i-1]+1) mp[j][ry[i]] = 1;
    }
    if(ry[i] != ry[i-1]){
      REP(j,ry[i-1],ry[i]+1) mp[rx[i]][j] = 1;
      REP(j,ry[i],ry[i-1]+1) mp[rx[i]][j] = 1;
    }
  }

  mp[0][0] = 2;
  st_size = 0;
  st[st_size++] = 0;
  while(st_size){
    k = st[--st_size];
    cx = k/YS; cy = k%YS;
    rep(d,4){
      nx = cx + dx[d];
      ny = cy + dy[d];
      if(nx < 0 || ny < 0 || nx >= XS || ny >= YS || mp[nx][ny]) continue;
      mp[nx][ny] = 2;
      st[st_size++] = nx * YS + ny;
    }
  }

  res = 0;
  rep(i,XS-1) rep(j,YS-1) if(mp[i][j] != 2){
    k = cnvX[i+1] - cnvX[i];
    l = cnvY[j+1] - cnvY[j];
    res += (ll)k * (ll)l;
  }

  printf("%I64d\n",res);

  return 0;
}