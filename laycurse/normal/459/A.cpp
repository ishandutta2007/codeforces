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

int ab(int x){ if(x<0) return -x; return x; }

int main(){
  int i, j, k;
  int x[4], y[4];
  int dx, dy;

  reader(x+0, y+0);
  reader(x+1, y+1);

  dx = x[1] - x[0];
  dy = y[1] - y[0];
  if(ab(dx)==ab(dy)){
    x[2] = x[0]; x[3] = x[1];
    y[2] = y[1]; y[3] = y[0];
  } else if(dx==0){
    x[2] = x[3] = x[0] + dy;
    y[2] = y[0]; y[3] = y[1];
  } else if(dy==0){
    y[2] = y[3] = y[0] + dx;
    x[2] = x[0]; x[3] = x[1];
  } else {
    writer(-1,'\n');
    myed;
    return 0;
  }

  writer(x[2], ' ');
  writer(y[2], ' ');
  writer(x[3], ' ');
  writer(y[3], '\n');

  myed;
  return 0;
}