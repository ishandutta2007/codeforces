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
void writer(int x, char c){int i,sz=0,m=0;char buf[10];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}

int N, P[5000], Pi[5000], M;

int num[5000], vis[5000], mnn[5000], szz[5000], sz;
int now;

int resx[5000], resy[5000], ress;

void getsz(void){
  int i, k;
  rep(i,N) vis[i] = 0;
  sz = 0;
  rep(i,N) if(!vis[i]){
    k = i;
    mnn[sz] = i;
    szz[sz] = 0;
    while(vis[k]==0){
      num[k] = sz;
      vis[k] = 1;
      szz[sz]++;
      k = P[k];
    }
    sz++;
  }
}

int main(){
  int i, j, k;
  int lis[5000], liss;

  reader(&N);
  rep(i,N) reader(P+i), P[i]--;
  reader(&M);

  getsz();
  now = N - sz;
  ress = 0;
  while(now < M){
    resx[ress] = mnn[0]; resy[ress++] = mnn[1];
    swap(P[mnn[0]], P[mnn[1]]);

    getsz();
    now = N - sz;
  }
  while(now > M){
    rep(k,sz) if(szz[k] > 1) break;
    liss = 0;
    rep(i,N) if(num[i]==k) lis[liss++] = i;
    resx[ress] = lis[0]; resy[ress++] = lis[1];
    swap(P[lis[0]], P[lis[1]]);

    getsz();
    now = N - sz;
  }

  writer(ress, '\n');
  rep(i,ress) writer(resx[i]+1,' '), writer(resy[i]+1,i==ress-1?'\n':' ');

  myed;
  return 0;
}