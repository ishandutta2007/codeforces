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

template<class T> void doublingRMQBuild(T arr[], int n, int res[]){int i,k,h;rep(i,n)res[i]=i;for(k=1;;k++){h=(1<<(k-1));if(h>=n)break;rep(i,n){res[n*k+i]=res[n*(k-1)+i];if(i+h<n&&arr[res[n*k+i]]>arr[res[n*(k-1)+i+h]])res[n*k+i]=res[n*(k-1)+i+h];}}}
template<class T> void* doublingRMQBuild(T arr[], int n, int **res, void *workMemory){int i,k,h;*res=(int*)workMemory;rep(i,n)(*res)[i]=i;for(k=1;;k++){h=(1<<(k-1));if(h>=n)break;rep(i,n){(*res)[n*k+i]=(*res)[n*(k-1)+i];if(i+h<n&&arr[(*res)[n*k+i]]>arr[(*res)[n*(k-1)+i+h]])(*res)[n*k+i]=(*res)[n*(k-1)+i+h];}}return (void*)((*res)+n*k);}
template<class T> int doublingRMQQuery(T arr[], int n, int rmq[], int a, int b){int d,w=b-a+1,A,B;for(d=0;(1<<(d+1))<=w;d++);A=rmq[n*d+a];B=rmq[n*d+b-(1<<d)+1];return arr[A]>arr[B]?B:A;}

char memarr[227000000]; void *mem = memarr;
#define MD 1000000007

int N, M, A, B;
ll D[400000], H[400000];
ll toL[400000], toR[400000], sumL[400000], sumR[400000];

int *rmqL, *rmqR;

ll solve(int A, int B){
  int i, j, k, C, D;
  ll res = 0, tmp;

  C = doublingRMQQuery(sumR, 3*N+1, rmqR, A+1, B);
  tmp = -(sumR[C] - sumR[A]) + 4*H[A];
  res = max(res, tmp);

  if(A < C){
    D = doublingRMQQuery(sumL, 3*N+1, rmqL, A, C-1);
    tmp = -(sumR[C] - sumR[D]) + 4*H[D];
    res = max(res, tmp);
  }

  if(C < B){
    D = doublingRMQQuery(sumR, 3*N+1, rmqR, C+1, B);
    tmp = -(sumR[D] - sumR[C]) + 4*H[C];
    res = max(res, tmp);
  }

  return res;
}

ll solve_brute(int A, int B){
  int i, j, k;
  ll res = 0, tmp;

  REP(i,A,B) REP(j,i+1,B+1){
    tmp = 2 * H[i] + 2 * H[j];
    REP(k,i,j) tmp += D[k];
    res = max(res, tmp);
  }
  
  return res;
}

int main(){
  int i, j, k;
  ll res, tmp;

  reader(&N,&M);
  rep(i,N) reader(D+i);
  rep(i,N) reader(H+i);
  rep(i,2*N) D[i+N] = D[i];
  rep(i,2*N) H[i+N] = H[i];

  rep(i,3*N-1) toR[i] = D[i] + 2*H[i+1] - 2*H[i];
  REP(i,1,3*N) toL[i] = D[i-1] + 2*H[i-1] - 2*H[i];

  sumR[0] = 0;
  rep(i,3*N-1) sumR[i+1] = sumR[i]+toR[i];
  sumL[3*N] = 0;
  for(i=3*N;i;i--) sumL[i-1] = sumL[i]+toL[i];

  rep(i,3*N+1) sumR[i] *= -1, sumL[i] *= -1;

  mem = doublingRMQBuild(sumR, 3*N+1, &rmqR, mem);
  mem = doublingRMQBuild(sumL, 3*N+1, &rmqL, mem);

  while(M--){
    reader(&A,&B); A--; B--;
    if(B < A) B += N;
    swap(A,B);
    A++; B=B+N-1;
    res = solve(A, B);
    writerLn(res);

//    tmp = solve_brute(A, B);
//    writerLn(res,tmp);
//    assert(res==tmp);
  }

  return 0;
}