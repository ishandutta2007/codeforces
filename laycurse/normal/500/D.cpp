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

void* setUndirectEdge(int N, int M, int A[], int B[], int **es, int ***edge, void *workMemory){int i;*es=(int*)workMemory;*edge=(int**)((*es)+N);(*edge)[0]=(int*)((*edge)+N);rep(i,N)(*es)[i]=0;rep(i,M)(*es)[A[i]]++,(*es)[B[i]]++;REP(i,1,N)(*edge)[i]=(*edge)[i-1]+(*es)[i-1];workMemory=(void*)((*edge)[N-1]+(*es)[N-1]);rep(i,N)(*es)[i]=0;rep(i,M)(*edge)[A[i]][(*es)[A[i]]++]=B[i],(*edge)[B[i]][(*es)[B[i]]++]=A[i];return workMemory;}

int N, A[111111], B[111111], C[111111], Q;
int *es, **edge;

int depth[111111], num[111111];

void dfs(int now, int bef){
  int i, j, k;

  if(bef==-1) depth[now] = 0; else depth[now] = depth[bef] + 1;
  num[now] = 1;

  rep(i,es[now]){
    k = edge[now][i];
    if(k==bef) continue;
    dfs(k, now);
    num[now] += num[k];
  }
}

int main(){
  int i, j, k;
  double res, mul;
  void *mem = malloc(70000000);

  reader(&N);
  rep(i,N-1) reader(A+i,B+i,C+i), A[i]--, B[i]--;
  mem = setUndirectEdge(N, N-1, A, B, &es, &edge, mem);

  dfs(0, -1);
  rep(i,N-1) if(depth[A[i]] > depth[B[i]]) swap(A[i], B[i]);

  res = 0;
  rep(i,N-1){
    res += (double) C[i] * (N - num[B[i]]) * num[B[i]];
  }

  mul = 3;
  mul /= (double)N*(N-1)/2;

  reader(&Q);
  while(Q--){
    reader(&i,&k); i--;
    res -= (double) (C[i] - k) * (N - num[B[i]]) * num[B[i]];
    C[i] = k;
    printf("%.15f\n", res * mul);
  }

  myed;
  return 0;
}