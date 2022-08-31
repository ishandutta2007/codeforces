#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
#define ull unsigned ll
#define MD 1000000007

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
void reader(ll *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
int reader(char c[]){int i,s=0;for(;;){mygc(i);if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF) break;}c[s++]=i;for(;;){mygc(i);if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF) break;c[s++]=i;}return s;}

void writer(int x, char c){int i,sz=0,m=0;char buf[10];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}
void writer(ll x, char c){int i,sz=0,m=0;char buf[20];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}
void writer(const char c[]){int i;for(i=0;c[i]!='\0';i++)mypc(c[i]);}

ull pw(ull a, ull b, ull m){ull r=1;while(b){if(b&1)r=r*a%m;b>>=1;a=a*a%m;}return r;}

#define L 1048576

int N, A[1000001];

int cnt[L], bc[L];

int main(){
  int i, j, k;
  ll res = 0;

  reader(&N);
  rep(i,N) reader(A+i);

  rep(i,L) cnt[i] = 0;
  rep(i,N) cnt[A[i]]++;

  rep(i,L){
    bc[i] = 0;
    rep(j,20) if(i&1<<j) bc[i]++;
  }

  rep(j,20){
    rep(i,L) if(i&1<<j) cnt[i-(1<<j)] = (cnt[i-(1<<j)] + cnt[i]) % MD;
  }

  rep(i,L){
    if(bc[i]%2==0) res += pw(2, cnt[i], MD);
    else           res -= pw(2, cnt[i], MD);
  }

  res %= MD;
  if(res < 0) res += MD;
  writer((int)res,'\n');

  myed;
  return 0;
}