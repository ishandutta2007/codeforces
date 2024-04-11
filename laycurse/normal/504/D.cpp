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
void reader(ll *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
int reader(char c[]){int i,s=0;for(;;){mygc(i);if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF) break;}c[s++]=i;for(;;){mygc(i);if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF) break;c[s++]=i;}c[s]='\0';return s;}
template <class T, class S> void reader(T *x, S *y){reader(x);reader(y);}
template <class T, class S, class U> void reader(T *x, S *y, U *z){reader(x);reader(y);reader(z);}
template <class T, class S, class U, class V> void reader(T *x, S *y, U *z, V *w){reader(x);reader(y);reader(z);reader(w);}

void writer(int x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(ll x, char c){int s=0,m=0;char f[20];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(const char c[]){int i;for(i=0;c[i]!='\0';i++)mypc(c[i]);}
void writer(const char x[], char c){int i;for(i=0;x[i]!='\0';i++)mypc(x[i]);mypc(c);}
template<class T> void writerLn(T x){writer(x,'\n');}
template<class T, class S> void writerLn(T x, S y){writer(x,' ');writer(y,'\n');}
template<class T, class S, class U> void writerLn(T x, S y, U z){writer(x,' ');writer(y,' ');writer(z,'\n');}
template<class T> void writerArr(T x[], int n){int i;if(!n){mypc('\n');return;}rep(i,n-1)writer(x[i],' ');writer(x[n-1],'\n');}

ull mat[2100][40];
int binaryGaussJordan(int r, int c, int right){
  int i, j, k, b = (c+right+63)/64, rank = 0;

  rep(j,c){
    REP(i,rank,r) if(mat[i][j>>6]&(1ULL<<(j&63))) break;
    if(i==r) continue;
    if(i!=rank) REP(k,j>>6,b) swap(mat[i][k], mat[rank][k]);
    REP(i,0,r) if(i!=rank) if(mat[i][j>>6]&(1ULL<<(j&63))) REP(k,j>>6,b) mat[i][k] ^= mat[rank][k];
    rank++;
  }

  return rank;
}
int N;
char in[2010][2010];

char buf[2000];
int arr[5000], sz;

int ind[2222];
int ress, res[2222];

int main(){
  int i, j, k, x;

  reader(&N);
  rep(x,N){
    sz = reader(buf);
    rep(i,5*sz+11) arr[i] = 0;
    rep(i,sz) arr[i] = buf[sz-1-i] - '0';
    rep(i,sz) arr[i] = arr[5*i+4] * 10000 + arr[5*i+3] * 1000 + arr[5*i+2] * 100 + arr[5*i+1] * 10 + arr[5*i];
    sz = sz / 5 + 2;
    
    rep(i,2000) in[x][i] = 0;
    rep(i,2000){
      in[x][i] = arr[0] % 2;
      arr[0] /= 2;
      REP(j,1,sz){
        arr[j-1] += 50000 * (arr[j]%2);
        arr[j] /= 2;
      }
      if(arr[sz-1]==0) sz--;
      if(sz==0) break;
    }
  }

  rep(i,N) rep(j,2000){
    if(in[i][j]) mat[j][i/64] |= (1ULL << (i%64));
  }
  binaryGaussJordan(2000, N, 0);

  k = 0;
  rep(i,N){
    if(mat[k][i/64] & (1ULL << (i%64))){
      ind[k++] = i;
      writerLn(0);
    } else {
      ress = 1;
      rep(j,k) if(mat[j][i/64] & (1ULL << (i%64))) res[ress++] = ind[j];
      res[0] = ress-1;
      writerArr(res,ress);
    }
  }

  myed;
  return 0;
}