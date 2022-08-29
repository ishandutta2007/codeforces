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

#define MD 1000000007
#define D 987361

int N, W;
ll A[300000], B[300000];

int solve(){
  int i, j, k;
  int res = 0;
  ull h1, h2, hs1, hs2, p1, p2;

  if(W==1) return N;
  if(N < W) return 0;

  N--; W--;
  rep(i,N) A[i] = A[i]-A[i+1];
  rep(i,W) B[i] = B[i]-B[i+1];

  rep(i,N) A[i] += 4000000000LL;
  rep(i,W) B[i] += 4000000000LL;

  p1 = p2 = 1;
  rep(i,W) p1 = p1 * D;
  rep(i,W) p2 = p2 * D % MD;

  h1 = h2 = 0;
  rep(i,W) h1 = h1 * D + B[i];
  rep(i,W) h2 = (h2 * D + B[i]) % MD;

  hs1 = hs2 = 0;
  rep(i,W){
    hs1 = hs1 * D + A[i];
    hs2 = (hs2 * D + A[i]) % MD;
  }
  if(hs1 == h1 && hs2 == h2) res++;

  REP(i,W,N){
    hs1 = hs1 * D + A[i] - A[i-W] * p1;
    hs2 = ((ull)MD*MD + hs2 * D + A[i] - A[i-W]%MD * p2) % MD;
    if(hs1 == h1 && hs2 == h2) res++;
  }

  return res;
}

int main(){
  int i, j, k;
  int res;

  reader(&N,&W);
  rep(i,N) reader(A+i);
  rep(i,W) reader(B+i);

  res = solve();
  writer(res,'\n');

  myed;
  return 0;
}