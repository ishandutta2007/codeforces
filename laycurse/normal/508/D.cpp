#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define mygc(c) (c)=getchar()
#define mypc(c) putchar(c)

#define ll long long
#define ull unsigned ll

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(ll *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(double *x){scanf("%lf",x);}
int reader(char c[]){int i,s=0;for(;;){mygc(i);if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF) break;}c[s++]=i;for(;;){mygc(i);if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF) break;c[s++]=i;}c[s]='\0';return s;}
template <class T, class S> void reader(T *x, S *y){reader(x);reader(y);}
template <class T, class S, class U> void reader(T *x, S *y, U *z){reader(x);reader(y);reader(z);}
template <class T, class S, class U, class V> void reader(T *x, S *y, U *z, V *w){reader(x);reader(y);reader(z);reader(w);}

void writer(int x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(ll x, char c){int s=0,m=0;char f[20];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(double x, char c){printf("%.15f",x);mypc(c);}
void writer(const char c[]){int i;for(i=0;c[i]!='\0';i++)mypc(c[i]);}
void writer(const char x[], char c){int i;for(i=0;x[i]!='\0';i++)mypc(x[i]);mypc(c);}
template<class T> void writerLn(T x){writer(x,'\n');}
template<class T, class S> void writerLn(T x, S y){writer(x,' ');writer(y,'\n');}
template<class T, class S, class U> void writerLn(T x, S y, U z){writer(x,' ');writer(y,' ');writer(z,'\n');}
template<class T> void writerArr(T x[], int n){int i;if(!n){mypc('\n');return;}rep(i,n-1)writer(x[i],' ');writer(x[n-1],'\n');}

void* setDirectEdge(int N, int M, int A[], int B[], int **es, int ***edge, void *workMemory){int i;*es=(int*)workMemory;*edge=(int**)((*es)+N);(*edge)[0]=(int*)((*edge)+N);rep(i,N)(*es)[i]=0;rep(i,M)(*es)[A[i]]++;REP(i,1,N)(*edge)[i]=(*edge)[i-1]+(*es)[i-1];workMemory=(void*)((*edge)[N-1]+(*es)[N-1]);rep(i,N)(*es)[i]=0;rep(i,M)(*edge)[A[i]][(*es)[A[i]]++]=B[i];return workMemory;}
void directedEulerPathDFS(int now, int *es, int **edge, int *used, int res[], int *sz){int i;while(used[now]<es[now]){i=used[now]++;directedEulerPathDFS(edge[now][i],es,edge,used,res,sz);}res[(*sz)++]=now;}
int directedEulerPath(int N, int *es, int **edge, int res[], void *mem){int i,j,M=0,s=0,*d,*u;d=(int*)mem;u=d+N;rep(i,N)d[i]=0;rep(i,N){M+=es[i];rep(j,es[i])d[edge[i][j]]--;d[i]+=es[i];}j=-1;rep(i,N){if(!d[i]) continue;if(d[i]<-1||d[i]>1)return -1;if(d[i]==1){if(j!=-1)return -1;j=i;}}if(j==-1){rep(i,N)if(es[i]){j=i;break;}}rep(i,N)u[i]=0;directedEulerPathDFS(j,es,edge,u,res,&s);if(s!=M+1)return -1;reverse(res,res+s);return s;}

char memarr[77000000]; void *mem = memarr;
#define MD 1000000007

int N;
char in[210000][5];
int A[210000], B[210000];

int node;
int *es, **edge;

int res[210000], ress;


int main(){
  int i, j, k;

  reader(&N);
  rep(i,N) reader(in[i]);

  node = 128 * 128;
  rep(i,N){
    A[i] = in[i][0] * 128 + in[i][1];
    B[i] = in[i][1] * 128 + in[i][2];
  }

  mem = setDirectEdge(node, N, A, B, &es, &edge, mem);
  ress = directedEulerPath(node, es, edge, res, mem);
  if(ress < 0){ writerLn("NO"); return 0; }

  writerLn("YES");
  mypc(res[0]/128);
  rep(i,ress) mypc(res[i]%128);
  writerLn("");

  return 0;
}