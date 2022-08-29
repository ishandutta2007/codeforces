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

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(int *x, int *y){reader(x);reader(y);}
void writer(int x, char c){int i,sz=0,m=0;char buf[10];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}

double getd(double dx, double dy){ return sqrt(dx*dx+dy*dy); }

int N, M;

int px[20], py[20], ps;
double dist[20][20];
double res; int resp[4];
int now[4];

void solve(int depth, double len){
  int i, j, k;
  double add = 0;

  if(depth==4){
    if(res < len){
      res = len;
      rep(i,4) resp[i] = now[i];
    }
    return;
  }

  rep(i,ps){
    rep(j,depth) if(now[j]==i) break;
    if(j<depth) continue;

    if(depth) add = dist[now[depth-1]][i];
    now[depth] = i;
    solve(depth+1, len+add);
  }
}

int main(){
  int i, j, k;
  int x, y;
  set<pair<int,int> > s;

  reader(&N,&M);

  ps = 0;
  rep(i,2) rep(j,2){
    x = i; y = j;
    if(0<=x && x<=N && 0<=y && y<=M && s.count( make_pair(x,y) )==0){
      s.insert( make_pair(x,y) );
      px[ps] = x;
      py[ps] = y;
      ps++;
    }
    
    x = N-i; y = j;
    if(0<=x && x<=N && 0<=y && y<=M && s.count( make_pair(x,y) )==0){
      s.insert( make_pair(x,y) );
      px[ps] = x;
      py[ps] = y;
      ps++;
    }
    
    x = i; y = M-j;
    if(0<=x && x<=N && 0<=y && y<=M && s.count( make_pair(x,y) )==0){
      s.insert( make_pair(x,y) );
      px[ps] = x;
      py[ps] = y;
      ps++;
    }
    
    x = N-i; y = M-j;
    if(0<=x && x<=N && 0<=y && y<=M && s.count( make_pair(x,y) )==0){
      s.insert( make_pair(x,y) );
      px[ps] = x;
      py[ps] = y;
      ps++;
    }
  }

  rep(i,ps) rep(j,ps) dist[i][j] = getd(px[i]-px[j], py[i]-py[j]);

  res = -1;
  solve(0, 0);

  rep(i,4) writer(px[resp[i]],' '), writer(py[resp[i]], '\n');

  myed;
  return 0;
}