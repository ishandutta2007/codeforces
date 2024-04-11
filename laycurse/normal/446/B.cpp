#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

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
void writer(ll x, char c){int i,sz=0,m=0;char buf[20];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}

template <class T>
struct heapEx {
  int *hp, *place, size; T *val;

  void malloc(int N){hp=(int*)std::malloc(N*sizeof(int));place=(int*)std::malloc(N*sizeof(int));val=(T*)std::malloc(N*sizeof(T));}
  void free(){free(hp);free(place);free(val);}
  void* malloc(int N, void *workMemory){hp=(int*)workMemory;workMemory=(void*)(hp+N);place=(int*)workMemory;workMemory=(void*)(place+N);val=(T*)workMemory;workMemory=(void*)(val+N);return workMemory;}
  void init(int N){int i;size=0;rep(i,N)place[i]=-1;}
  void up(int n){int m;while(n){m=(n-1)/2;if(val[hp[m]]<=val[hp[n]])break;swap(hp[m],hp[n]);swap(place[hp[m]],place[hp[n]]);n=m;}}
  void down(int n){int m;for(;;){m=2*n+1;if(m>=size)break;if(m+1<size&&val[hp[m]]>val[hp[m+1]])m++;if(val[hp[m]]>=val[hp[n]])break;swap(hp[m],hp[n]);swap(place[hp[m]],place[hp[n]]);n=m;}}
  void change(int n, T v){T f=val[n];val[n]=v;if(place[n]==-1){place[n] = size;hp[size++] = n;up(place[n]);}else{if(f < v) down(place[n]); else if(f > v) up(place[n]);}}
  int pop(void){int res=hp[0];place[res]=-1;size--;hp[0]=hp[size];place[hp[0]]=0;down(0);return res;}
};

int N, M, K, P;
int A[1010][1010];
ll row[1010], col[1010];

ll rgain[1000100], cgain[1000100];

int main(){
  int i, j, x, y;
  ll res = 0, tmp;
  heapEx<ll> rHeap, cHeap;

  reader(&N,&M);
  reader(&K,&P);
  rep(i,N) rep(j,M) reader(A[i]+j);

  rep(i,N) row[i] = 0;
  rep(i,M) col[i] = 0;
  rep(i,N) rep(j,M) row[i] += A[i][j], col[j] += A[i][j];

  rHeap.malloc(N); rHeap.init(N);
  cHeap.malloc(M); cHeap.init(M);

  rep(i,N) rHeap.change(i, -row[i]);
  rep(i,M) cHeap.change(i, -col[i]);

  res = -1000000000000000000LL;
  
  rgain[0] = 0;
  cgain[0] = 0;
  REP(i,1,K+1){
    x = rHeap.hp[0];
    rgain[i] = rgain[i-1] - rHeap.val[x];
    rHeap.change(x, rHeap.val[x] + P*M);
  }
  REP(i,1,K+1){
    x = cHeap.hp[0];
    cgain[i] = cgain[i-1] - cHeap.val[x];
    cHeap.change(x, cHeap.val[x] + P*N);
  }

  rep(i,K+1){
    tmp = rgain[i] + cgain[K-i] - (ll)P*i*(K-i);
    res = max(res, tmp);
  }

  writer(res,'\n');

  myed;
  return 0;
}