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
void reader(int *x, int *y, int *z){reader(x);reader(y);reader(z);}
void writer(int x, char c){int i,sz=0,m=0;char buf[10];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}

int N, X, Y;
int T[3000], H[3000], M[3000];

int used[3000];

int main(){
  int i, j, k, mx, ind;
  int res=0, tmp;
  int st, nx;

  reader(&N,&X);
  rep(i,N) reader(T+i,H+i,M+i);

  rep(st,2){
    rep(i,N) used[i] = 0;

    nx = st;
    Y = X;
    for(;;){
      mx = -1;
      rep(i,N){
        if(T[i] != nx) continue;
        if(used[i]) continue;
        if(H[i] > Y) continue;
        if(M[i] > mx) mx = M[i], ind = i;
      }
      if(mx==-1) break;

      used[ind] = 1;
      Y += mx;
      nx ^= 1;
    }

    tmp = 0;
    rep(i,N) tmp += used[i];
    res = max(res, tmp);
  }

  writer(res, '\n');

  myed;
  return 0;
}