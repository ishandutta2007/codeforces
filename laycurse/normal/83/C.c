#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

char mp[66][66];
int x,y,z;

int sz, arr[15000][4];
int now_gen[4];

int res[5000], res_size;
int tmp[5000], tmp_size;

void gen(int depth, int st){
  int i;

  if(depth==z){
    rep(i,z) arr[sz][i] = now_gen[i];
    sz++;
    return;
  }

  REP(i,st,26){
    now_gen[depth] = i;
    gen(depth+1, i+1);
  }
}

int smaller(void){
  int i;
  rep(i,res_size){
    if(res[i] < tmp[i]) return 0;
    if(res[i] > tmp[i]) return 1;
  }
  return 0;
}

void renew(void){
  int i;

  if(res_size == tmp_size && smaller()) res_size++;
  if(res_size > tmp_size){
    res_size = tmp_size;
    rep(i,res_size) res[i] = tmp[i];
  }
}

int main(){
  int i,j,k,l,m,n,loop,mi;
  int sx,sy,ex,ey,tx,ty,nx,ny;
  int dx[4]={-1,1,0,0}, dy[4]={0,0,1,-1};
  int usa[30];
  int dist[55][55], chked[55][55];
  int q[3333], q_st, q_size;
  int ok1[3333], ok2[3333], ok1_size, ok2_size;

  while(scanf("%d%d%d",&x,&y,&z)==3){
    rep(i,x) scanf("%s",mp[i]);

    sz = 0;
    gen(0, 0);

    rep(i,x) rep(j,y){
      if(mp[i][j]=='S'){ mp[i][j] = 27; sx = i; sy = j; continue; }
      if(mp[i][j]=='T'){ mp[i][j] = 28; ex = i; ey = j; continue; }
      mp[i][j] -= 'a';
    }

    res_size = 5000;

    rep(loop,sz){
      rep(i,30) usa[i] = 0;
      rep(i,z) usa[arr[loop][i]]=1; usa[27]=usa[28]=1;

      rep(i,x) rep(j,y) dist[i][j] = -1;
      dist[ex][ey] = 0;

      q_st = 0; q_size = 1;
      q[0] = ex*y + ey;
      
      while(q_size){
        tx = q[q_st]/y; ty = q[q_st]%y;
        q_st++; q_size--;

        rep(k,4){
          nx = tx + dx[k]; ny = ty + dy[k];
          if(nx<0||ny<0 || nx>=x||ny>=y) continue;
          if(!usa[mp[nx][ny]]) continue;
          if(dist[nx][ny]>=0) continue;

          dist[nx][ny] = dist[tx][ty] + 1;
          q[q_st+q_size++] = nx*y + ny;
        }
      }

      if(dist[sx][sy]==-1) continue;
      if(dist[sx][sy]-1 > res_size) continue;

      rep(i,x) rep(j,y) chked[i][j] = 0;
      chked[sx][sy] = 1;

      tmp_size = 0;
      ok1_size = 1; ok1[0] = sx*y + sy;
      while(tmp_size < dist[sx][sy]-1){
        mi = 100;
        rep(i,ok1_size){
          tx = ok1[i]/y; ty = ok1[i]%y;
          rep(k,4){
            nx = tx + dx[k]; ny = ty + dy[k];
            if(nx<0||ny<0 || nx>=x||ny>=y) continue;
            if(dist[nx][ny] != dist[tx][ty]-1) continue;
            if(mi > mp[nx][ny]) mi = mp[nx][ny];
          }
        }

        ok2_size = 0;
        rep(i,ok1_size){
          tx = ok1[i]/y; ty = ok1[i]%y;
          rep(k,4){
            nx = tx + dx[k]; ny = ty + dy[k];
            if(nx<0||ny<0 || nx>=x||ny>=y) continue;
            if(dist[nx][ny] != dist[tx][ty]-1) continue;
            if(chked[nx][ny]) continue;
            if(mi == mp[nx][ny]){
              ok2[ok2_size++] = nx*y + ny;
              chked[nx][ny]=1;
            }
          }
        }

        ok1_size = ok2_size;
        rep(i,ok1_size) ok1[i] = ok2[i];

        tmp[tmp_size++] = mi;
      }

      renew();
    }

    if(res_size==5000){puts("-1"); continue;}
    rep(i,res_size) putchar('a' + res[i]); puts("");
  }

  return 0;
}