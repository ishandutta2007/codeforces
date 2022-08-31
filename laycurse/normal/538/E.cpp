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

char memarr[77000000]; void *mem = memarr;
#define MD 1000000007

int N;
int A[300000], B[300000];
int dp1[300000], dp2[300000], dp3[300000];

int **edge, *es;

void solve(int n, int fg){
  int i, j, k;
  int add, sa;

  if(es[n]==0){
    dp1[n] = 0;
    dp2[n] = 0;
    dp3[n] = 1;
    return;
  }

  dp3[n] = 0;
  rep(i,es[n]){
    k = edge[n][i];
    solve(k, -fg);
    dp3[n] += dp3[k];
  }

  if(fg==1){
    dp1[n] = -1;
    dp2[n] = -1;
  } else {
    dp1[n] = 0;
    dp2[n] = N+100;
  }

  rep(i,es[n]){
    k = edge[n][i];
    add = dp3[n] - dp3[k];
    if(fg==1){
      dp1[n] = max(dp1[n], dp1[k]+add);
      dp2[n] += dp2[k]+1;
    } else {
      dp1[n] += dp1[k];
      dp2[n] = min(dp2[n], dp2[k]);
    }
  }
}

int main(){
  int i, j, k;
  int res1, res2;

  reader(&N);
  rep(i,N-1) reader(A+i,B+i), A[i]--, B[i]--;

  setDirectEdge(N, N-1, A, B, &es, &edge, mem);

  solve(0, 1);
  
//  rep(i,N) printf("%d : %d %d %d\n",i,dp1[i],dp2[i],dp3[i]);

  writerLn(dp1[0]+1, dp2[0]+1);

  return 0;
}