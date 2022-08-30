#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int memory[1000000], mem;
int *up[5100], *down[5100];
int *left[5100], *right[5100];

int x,y;
char mp[5100][5100], used[5100][5100];

int get_up(int a,int b){
  if(up[a][b]==-1) return -1;
  if(!used[up[a][b]][b]) return up[a][b];
  return up[a][b] = get_up(up[a][b],b);
}

int get_down(int a,int b){
  if(down[a][b]==-1) return -1;
  if(!used[down[a][b]][b]) return down[a][b];
  return down[a][b] = get_down(down[a][b],b);
}

int get_left(int a,int b){
  if(left[a][b]==-1) return -1;
  if(!used[a][left[a][b]]) return left[a][b];
  return left[a][b] = get_left(a,left[a][b]);
}

int get_right(int a,int b){
  if(right[a][b]==-1) return -1;
  if(!used[a][right[a][b]]) return right[a][b];
  return right[a][b] = get_right(a,right[a][b]);
}

int solve(int a,int b){
  int i,j,k;
  int res = 0;

  rep(i,x) rep(j,y) used[i][j] = 0;

  rep(i,x){
    left[i][0] = -1;
    REP(j,1,y){
      left[i][j] = left[i][j-1];
      if(mp[i][j-1]!='.') left[i][j] = j-1;
    }

    right[i][y-1] = -1;
    for(j=y-2;j>=0;j--){
      right[i][j] = right[i][j+1];
      if(mp[i][j+1]!='.') right[i][j] = j+1;
    }
  }

  rep(j,y){
    up[0][j] = -1;
    REP(i,1,x){
      up[i][j] = up[i-1][j];
      if(mp[i-1][j]!='.') up[i][j] = i-1;
    }

    down[x-1][j] = -1;
    for(i=x-2;i>=0;i--){
      down[i][j] = down[i+1][j];
      if(mp[i+1][j]!='.') down[i][j] = i+1;
    }
  }

  for(;;){
    res++;
    used[a][b] = 1;

         if(mp[a][b]=='U') a = get_up(a,b);
    else if(mp[a][b]=='D') a = get_down(a,b);
    else if(mp[a][b]=='L') b = get_left(a,b);
    else if(mp[a][b]=='R') b = get_right(a,b);

    if(a<0 || b<0) break;
  }

  return res;
}

int main(){
  int i,j,k,l,m,n;
  int mx, res;

  mem = 0;
  rep(i,5100){
    up[i]    = memory+mem; mem += 5100/(i+1);
    down[i]  = memory+mem; mem += 5100/(i+1);
    left[i]  = memory+mem; mem += 5100/(i+1);
    right[i] = memory+mem; mem += 5100/(i+1);
  }

  while(scanf("%d%d",&x,&y)==2){
    rep(i,x) scanf("%s",mp[i]);

    mx = res = 0;
    rep(i,x) rep(j,y) if(mp[i][j]!='.'){
      k = solve(i,j);
      if(mx < k) mx = k, res = 0;
      if(mx==k) res++;
    }

    printf("%d %d\n",mx,res);
  }

  return 0;
}