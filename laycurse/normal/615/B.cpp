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

char memarr[57000000]; void *mem = memarr;
#define MD 1000000007

template<class S, class T> inline void chmax(S &a, T b){if(a<b)a=b;}
void* readUndirectedGraph(int N, int M, int **es, int ***edge, void *mem, int origin=0){int i,*A;A=((int*)(((int**)mem)+N)+N+2*M);rep(i,2*M)reader(A+i),A[i]-=origin;*es=(int*)mem;*edge=(int**)((*es)+N);memset(*es,0,sizeof(int)*N);rep(i,2*M)(*es)[A[i]]++;(*edge)[0]=(int*)((*edge)+N);REP(i,1,N)(*edge)[i]=(*edge)[i-1]+(*es)[i-1];memset(*es,0,sizeof(int)*N);for(i=0;i<2*M;i+=2)(*edge)[A[i]][(*es)[A[i]]++]=A[i+1],(*edge)[A[i+1]][(*es)[A[i+1]]++]=A[i];return A;}

int dp[100010];

int N, M;
int *es, **edge;

int main(){
  int i, j, k;
  ll res = 0;

  reader(&N,&M);
  mem = readUndirectedGraph(N,M,&es,&edge,mem,1);

  rep(i,N) dp[i] = 1;
  rep(i,N) rep(j,es[i]) if(i<edge[i][j]) chmax(dp[edge[i][j]], dp[i]+1);

  rep(i,N) chmax(res, (ll)dp[i]*es[i]);
  writerLn(res);

  return 0;
}