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

char memarr[17000000]; void *mem = memarr;
#define INF 1000000007

void* setUndirectEdge(int N, int M, int A[], int B[], int **es, int ***edge, void *workMemory){int i;*es=(int*)workMemory;*edge=(int**)((*es)+N);(*edge)[0]=(int*)((*edge)+N);rep(i,N)(*es)[i]=0;rep(i,M)(*es)[A[i]]++,(*es)[B[i]]++;REP(i,1,N)(*edge)[i]=(*edge)[i-1]+(*es)[i-1];workMemory=(void*)((*edge)[N-1]+(*es)[N-1]);rep(i,N)(*es)[i]=0;rep(i,M)(*edge)[A[i]][(*es)[A[i]]++]=B[i],(*edge)[B[i]][(*es)[B[i]]++]=A[i];return workMemory;}

int N, A[210000], B[210000], X, Y;
int deg[210000];

int *es, **edge;
int dp0[210000], dp1[210000];

void solve(int now, int bef){
  int i, j, k, tot = 0, g = -INF, g1 = -INF, g2 = -INF;

  rep(i,es[now]){
    k = edge[now][i];
    if(k==bef) continue;
    solve(k, now);
    tot += dp0[k];

    j = dp1[k] - dp0[k];
    if(g < j) g = j;
    
    if(g2 < j) g2 = j;
    if(g2 > g1) swap(g2, g1);
  }

  dp0[now] = dp1[now] = tot;
  if(g  > -INF + N + N) dp0[now] = dp1[now] = max(dp0[now], tot+g+1);
  if(g2 > -INF + N + N) dp0[now] = max(dp0[now], tot+g1+g2+2);

//  printf("%d: %d %d %d: %d %d %d\n",now,dp0[now],dp1[now],dp2[now],g,g1,g2);
}

int main(){
  int i, j, k;
  ll res;

  reader(&N,&X,&Y);
  rep(i,N-1) reader(A+i,B+i), A[i]--, B[i]--;
  rep(i,N-1) deg[A[i]]++, deg[B[i]]++;

  if(X < Y){
    mem = setUndirectEdge(N, N-1, A, B, &es, &edge, mem);
    solve(0, -1);
    k = dp0[0];
    res = (ll)X*k + (ll)Y*(N-1-k);
  } else {
    res = (ll)Y*(N-1);
    rep(i,N) if(deg[i]==N-1){
      res += (X-Y);
      break;
    }
  }

  writerLn(res);

  return 0;
}