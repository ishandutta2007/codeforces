#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int x, y, stx, sty;
int mp[510][510];

char res[5000000];
int res_size;

int di[4]={-1,0,1,0};
int dj[4]={0,-1,0,1};
char dir[10] = "ULDR";

int visited[510][510];

int is_light(int i, int j, int di, int dj){
  for(;;){
    if(i < 0 || j < 0 || i >= x || j >= y) break;
    if(mp[i][j]==1) return 1;
    i += di; j += dj;
  }
  return 0;
}

void dfs1(int i, int j){
  int ni, nj, k;

  visited[i][j] = 1;
  if(!mp[i][j]){
    mp[i][j] = 1;
    res[res_size++] = '1';
  }
  rep(k,4){
    ni = i+di[k]; nj = j+dj[k];
    if(ni < 0 || nj < 0 || ni >= x || nj >= y || visited[ni][nj]) continue;
    if(!is_light(ni,nj,di[k],dj[k])) continue;
    res[res_size++] = dir[k];
    dfs1(ni, nj);
    res[res_size++] = dir[(k+2)%4];
  }
}

void dfs2(int i, int j){
  int ni, nj, k;

  visited[i][j] = 1;
  rep(k,4){
    ni = i+di[k]; nj = j+dj[k];
    if(ni < 0 || nj < 0 || ni >= x || nj >= y || visited[ni][nj]) continue;
    if(!is_light(ni,nj,di[k],dj[k])) continue;
    res[res_size++] = dir[k];
    dfs2(ni, nj);
    res[res_size++] = dir[(k+2)%4];
  }

  mp[i][j] = 0;
  res[res_size++] = '2';
}

int main(){
  int i, j, k;

  scanf("%d%d%d",&x,&stx,&sty);
  y = x; stx--; sty--;
  rep(i,x) rep(j,y) scanf("%d",mp[i]+j);

  res_size = 0;

  rep(i,x) rep(j,y) visited[i][j] = 0;
  dfs1(stx,sty);

/*  puts("mp after dfs1");
  rep(i,x){ rep(j,y) printf("%d ",mp[i][j]); puts(""); }
  puts("visted after dfs1");
  rep(i,x){ rep(j,y) printf("%d ",visited[i][j]); puts(""); }*/

  k = 0;
  rep(i,x) rep(j,y){
    if(mp[i][j] && !visited[i][j]) k++;
  }
  if(k){ puts("NO"); return 0; }

  rep(i,x) rep(j,y) visited[i][j] = 0;
  dfs2(stx,sty);
  
  res[res_size] = '\0';
  puts("YES");
  printf("%s\n",res);

  return 0;
}