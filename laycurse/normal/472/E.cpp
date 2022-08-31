#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define READER_BUF_SIZE 1048576
#define WRITER_BUF_SIZE 1048576
int reader_pt=READER_BUF_SIZE,reader_last;char reader_buf[READER_BUF_SIZE];
int writer_pt=0;char writer_buf[WRITER_BUF_SIZE];
#define mygc(c) {if(reader_pt==READER_BUF_SIZE)reader_pt=0,reader_last=fread(reader_buf,sizeof(char),READER_BUF_SIZE,stdin);(c)=reader_buf[reader_pt++];}
#define mypc(c) {if(writer_pt==WRITER_BUF_SIZE)writer_pt=0,fwrite(writer_buf,sizeof(char),WRITER_BUF_SIZE,stdout);writer_buf[writer_pt++]=(c);}
#define myed {fwrite(writer_buf,sizeof(char),writer_pt,stdout);writer_pt=0;}

#define ll long long
#define ull unsigned ll

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(int *x, int *y){reader(x);reader(y);}
void reader(int *x, int *y, int *z){reader(x);reader(y);reader(z);}
void reader(ll *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
int reader(char c[]){int i,s=0;for(;;){mygc(i);if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF) break;}c[s++]=i;for(;;){mygc(i);if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF) break;c[s++]=i;}return s;}

void writer(int x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(ll x, char c){int s=0,m=0;char f[20];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(const char c[]){int i;for(i=0;c[i]!='\0';i++)mypc(c[i]);}

int sign(int x){
  if(x>0) return 1;
  if(x<0) return -1;
  return 0;
}

int ress;
int res1[1000100], res2[1000100];

int N, M;
int mp[33][33], goal[33][33];
int cnt[1000];

int dameX, dameY;
int dame[33][33];

void resadd(int a, int b){
  res1[ress] = a; res2[ress++] = b;
}

void domove(int sx, int sy, int nx, int ny){
  int dx, dy;

/*  int i, j;
  printf("call %d %d -> %d %d (%d %d)\n",sx,sy,nx,ny,N,M);
  printf("DAME %d %d\n",dameX,dameY);
  rep(i,N){ rep(j,M) printf("%d",dame[i][j]); puts(""); }
  puts("");

  rep(i,N){ rep(j,M) printf("%3d",mp[i][j]); puts(""); }
  puts("");
  rep(i,N){ rep(j,M) printf("%3d",goal[i][j]); puts(""); }
  puts("");
  puts("");
  fflush(stdout);*/

  while(sx != nx || sy != ny){
    dx = sign(nx - sx);
    dy = sign(ny - sy);

    if(dame[sx+dx][sy+dy] || (dameX==sx+dx && dameY==sy+dy)){
      if(dx && dy) {
        dx = 0;
      } else {
        if(dx==0){
          if(sx) dx = -1; else dx = 1;
        } else {
          if(sy) dy = -1; else dy = 1;
        }
      }
    }
    
    if(dame[sx+dx][sy+dy] || (dameX==sx+dx && dameY==sy+dy)){
      dx = sign(nx - sx);
      dy = sign(ny - sy);
      dx *= -1;
      if((sx+dx<0||sx+dx>=N) || dame[sx+dx][sy+dy] || (dameX==sx+dx && dameY==sy+dy)) dx *= -1, dy *= -1;
    }

//    printf("%d %d : %d %d -> %d %d\n",N,M,sx,sy,sx+dx,sy+dy); fflush(stdout);
    assert(!(sx+dx<0||sx+dx>=N));
    assert(!(sy+dy<0||sy+dy>=M));
    assert(!(dame[sx+dx][sy+dy] || (dameX==sx+dx && dameY==sy+dy)));

    resadd(sx+dx, sy+dy);
    swap(mp[sx][sy], mp[sx+dx][sy+dy]);
    sx += dx; sy += dy;
  }
}

void domove2(int *sx, int *sy, int nx, int ny){
  domove(*sx, *sy, nx, ny);
  *sx = nx;
  *sy = ny;
}

int isOK(void){
  int i, j;
  rep(i,N) rep(j,M) if(mp[i][j]!=goal[i][j]) return 0;
  return 1;
}

void findnear(int sx, int sy, int val, int *tx, int *ty, int curx, int cury){
  int i, j, k, d;
  int opt = 100000;

  rep(i,N) rep(j,M){
    if(dame[i][j]) continue;
    if(val != mp[i][j]) continue;
    if(i==curx && j==cury) continue;

    d = (sx-i) * sign(sx-i) + (sy-j) * sign(sy-j);
    if(d < opt){
      opt = d;
      *tx = i;
      *ty = j;
    }
  }
}

void gogo(int ti, int tj, int *sx, int *sy){
  int mx, my;

//  printf("%d %d\n",N,M);
    dameX = dameY = -1;
    domove2(sx, sy, 0, 0);
//  printf("%d %d\n",N,M);
  
  for(;;){
    findnear(ti,tj,goal[ti][tj],&mx,&my,*sx,*sy);
    if(mx==ti && my==tj){
      dame[ti][tj] = 1;
      break;
    }

    dameX = mx;
    dameY = my;
    domove2(sx, sy, ti, tj);

    dameX = dameY = -1;
    domove2(sx, sy, mx, my);
  }
}

int main(){
  int i, j, k, oN, oM;
  int ti, tj;
  int sx, sy, mx, my;
  int ok;

  reader(&N,&M); oN=N; oM=M;
  rep(i,N) rep(j,M) reader(mp[i]+j);
  rep(i,N) rep(j,M) reader(goal[i]+j);

  rep(i,N) rep(j,M) cnt[mp[i][j]]++;
  rep(i,N) rep(j,M) cnt[goal[i][j]]--;

  rep(i,1000) if(cnt[i]) break;
  if(i < 1000){
    writer("-1\n");
    myed;
    return 0;
  }

  if(N==1){
    ok = 0;
    dameX = dameY = -1;
    rep(i,M) rep(j,M) if(!ok){
      ress = 0;
      resadd(0,i);
      domove(0,i,0,j);
      if(isOK()){
        ok = 1;
      } else {
        domove(0,j,0,i);
        ress = 0;
      }
    }
  } else if(M==1){
    ok = 0;
    dameX = dameY = -1;
    rep(i,N) rep(j,N) if(!ok){
      ress = 0;
      resadd(i,0);
      domove(i,0,j,0);
      if(isOK()){
        ok = 1;
      } else {
        domove(j,0,i,0);
        ress = 0;
      }
    }
  } else {
    rep(i,N) rep(j,M) if(goal[0][0]==mp[i][j]) sx = i, sy = j;
    resadd(sx,sy);
    
    while(N > 2 || M > 2){
      if(N >= M){
        ti = N-1;
        for(tj = M-1; tj >= 0; tj--){
          gogo(ti,tj,&sx,&sy);
        }
        N--;
      } else {
        tj = M-1;
        for(ti = N-1; ti >= 0; ti--){
          gogo(ti,tj,&sx,&sy);
        }
        M--;
      }
    }

    // N = M = 2
    dameX = dameY = -1;
    domove2(&sx, &sy, 0, 0);

    for(;;){
      int fg1 = 0, fg2 = 0, fg3 = 0;
      if(mp[0][1]!=goal[0][1]) fg1++;
      if(mp[1][0]!=goal[1][0]) fg2++;
      if(mp[1][1]!=goal[1][1]) fg3++;

      if(fg1+fg2+fg3==0) break;
      
      if(fg1+fg2+fg3==3){
        domove2(&sx, &sy, 0, 1);
        domove2(&sx, &sy, 1, 0);
        domove2(&sx, &sy, 1, 1);
        domove2(&sx, &sy, 0, 0);
        continue;
      }

      if(fg1+fg2==2){
        domove2(&sx, &sy, 0, 1);
        domove2(&sx, &sy, 1, 0);
        domove2(&sx, &sy, 0, 0);
        continue;
      }

      if(fg1+fg3==2){
        domove2(&sx, &sy, 0, 1);
        domove2(&sx, &sy, 1, 1);
        domove2(&sx, &sy, 0, 0);
        continue;
      }

      if(fg2+fg3==2){
        domove2(&sx, &sy, 1, 0);
        domove2(&sx, &sy, 1, 1);
        domove2(&sx, &sy, 0, 0);
        continue;
      }
    }
  }

  writer(ress-1,'\n');
  rep(i,ress) writer(res1[i]+1,' '), writer(res2[i]+1,'\n');

/*  if(ress > 0){
    rep(i,oN) rep(j,oM) assert(mp[i][j] == goal[i][j]);
  }*/

  myed;
  return 0;
}