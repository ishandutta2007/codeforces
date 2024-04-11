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

template<class T> int bitCountSlow(T n){int r=0;while(n)r+=n%2,n/=2;return r;}

int bt[66666];
int bitCount(unsigned n){ return bt[n&65535]+bt[n>>16]; }

unsigned A[32][8000], B[32][8000];
int As, Bs, Len;
int Q;

char Araw[500000], Braw[500000];

int main(){
  int i, j, k, l;
  int x, xx, y, yy, z;
  int res;

  rep(i,66666) bt[i] = bitCountSlow(i);

  k = reader(Araw);
  //k = 200000; rep(i,k) Araw[i] = '0'+rand()%2;
  rep(i,k) if(Araw[i]=='1') A[0][i/32] |= (1ULL<<(i%32));
  k = reader(Braw);
  //k = 200000; rep(i,k) Braw[i] = '0'+rand()%2;
  rep(i,k) if(Braw[i]=='1') B[0][i/32] |= (1ULL<<(i%32));

  REP(i,1,32) rep(j,7900){
    A[i][j] = (A[i-1][j] >> 1) + ((A[i-1][j+1] % 2) << 31);
    B[i][j] = (B[i-1][j] >> 1) + ((B[i-1][j+1] % 2) << 31);
  }

  reader(&Q);
  //Q = 400000;
  while(Q--){
    reader(&As,&Bs,&Len);
    //As = rand()%5000; Bs = rand()%5000; Len = rand()%5000 + 189000;
    res = 0;
    while(Len%32){
      if(Araw[As] != Braw[Bs]) res++;
      As++; Bs++; Len--;
    }
    x = As/32; xx = As%32;
    y = Bs/32; yy = Bs%32;
    z = Len / 32;
    rep(i,z) res += bitCount(A[xx][x+i]^B[yy][y+i]);
    writer(res,'\n');
  }

  myed;
  return 0;
}