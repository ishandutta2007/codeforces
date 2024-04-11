#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)


void unionInit(int d[],int s){int i;rep(i,s)d[i]=i;}
int unionGet(int d[],int n){int t=n,k;while(d[t]!=t)t=d[t];while(d[n]!=n)k=d[n],d[n]=t,n=k;return n;}
int unionConnect(int d[],int a,int b){a=unionGet(d,a);b=unionGet(d,b);if(a==b)return 0;d[a]=b;return 1;}


int mp[1000][1000];
int ind[1000000];
int deg[1000][1000];

int is_ok(int sx, int sy, int dx, int dy, int go){
  int i;
  REP(i,1,go) if(mp[sx+dx*i][sy+dy*i]==0) return 0;
  return 1;
}

int main(){
  int x, y;

  int i, j, k, val, odd, t;
  int res[1001];
  int cnt, used, sx, sy, bx, by, nx, ny;

  scanf("%d%d",&x,&y);
  rep(i,x) rep(j,y) scanf("%d",mp[i]+j);

  rep(i,1001) res[i] = 0;
  cnt = 0;
  rep(i,x) rep(j,y) cnt += mp[i][j];

  if(cnt==1){
    puts("-1");
    return 0;
  }

  sx = -1;
  rep(i,x) rep(j,y) if(sx==-1 && mp[i][j]==1){
    sx = i;
    sy = j;
  }

  for(k = 1000; k >= 2; k--){
    for(i=2*k;i<=1000;i+=k) if(res[i]) res[k] = 1;
    if(res[k]) continue;
    if(k >= x && k >= y) continue;

    bx = sx % k;
    by = sy % k;
    nx = (x - bx + k-1) / k;
    ny = (y - by + k-1) / k;
    used = 0;
    odd = 0;

    unionInit(ind, nx * ny);
    rep(i,nx) rep(j,ny) deg[i][j] = 0;
    
    rep(i,nx) rep(j,ny){
      if(!mp[i*k+bx][j*k+by]) continue;
      used++;
      if(i+1 < nx && mp[(i+1)*k+bx][j*k+by]){
        if(is_ok(i*k+bx, j*k+by, 1, 0, k)==1){
          deg[i][j]++, deg[i+1][j]++, used += k-1;
          unionConnect(ind, i*ny+j, (i+1)*ny+j);
        }
      }
      if(j+1 < ny && mp[i*k+bx][(j+1)*k+by]){
        if(is_ok(i*k+bx, j*k+by, 0, 1, k)==1){
          deg[i][j]++, deg[i][j+1]++, used += k-1;
          unionConnect(ind, i*ny+j, i*ny+(j+1));
        }
      }
      if(deg[i][j]%2) odd++;
    }
    if(odd > 2) continue;
    if(used != cnt) continue;

    val = -1;
    rep(i,nx) rep(j,ny){
      if(!mp[i*k+bx][j*k+by]) continue;
      if(val==-2) continue;
      t = unionGet(ind, i*ny+j);
      if(val==-1) val = t;
      if(val != t) val = -2;
    }
    if(val==-2) continue;

    res[k] = 1;
  }

  j = 0;
  rep(i,1001) if(res[i]){
    if(j) putchar(' '); else j = 1;
    printf("%d",i);
  }
  if(!j) printf("-1");
  puts("");

  return 0;
}