#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<utility>
#include<iostream>
#include<cmath>
#include<ctime>
#include<cassert>
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
void reader(int *x, int *y, int *z){reader(x);reader(y);reader(z);}
void writer(int x, char c){int i,sz=0,m=0;char buf[10];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}

int pt[120], mp[120][120];

int solve(int x, int y){
  int i, j, add, tmp;
  tmp = 0;
  rep(j,y){
    add = 0;
    rep(i,x) if(pt[i] != mp[i][j]) add++;
    tmp += min(add, x-add);
  }
  return tmp;
}

int main(){
  int i, j;
  int x, y, k;
  int mp2[120][120], mask;
  int res, tmp, add;

  res = 1000000;

  reader(&x,&y,&k);
  rep(i,x) rep(j,y) reader(mp[i]+j);

  if(x <= k){
    rep(mask, 1<<x){
      rep(i,x) if(mask & 1<<i) pt[i] = 1; else pt[i] = 0;
      res = min(res, solve(x,y));
    }
  } else {
    rep(i,x) rep(j,y) mp2[i][j] = mp[i][j];
    swap(x,y);
    rep(i,x) rep(j,y) mp[i][j] = mp2[j][i];

    rep(mask, k+1){
      rep(i,x) pt[i] = mp[i][mask];
      res = min(res, solve(x,y));
    }
  }

  if(res > k) res = -1;

  writer(res, '\n');
  myed;

  return 0;
}