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
#define MD 1000000007

template<class T> inline T min(T a, T b, T c){return min(min(a,b),c);}
template<class T> inline T min(T a, T b, T c, T d){return min(min(a,b),min(c,d));}
template<class T> inline T max(T a, T b, T c){return max(max(a,b),c);}
template<class T> inline T max(T a, T b, T c, T d){return max(max(a,b),max(c,d));}

template<class S, class T> inline void chmin(S &a, T b){if(a>b)a=b;}
template<class S, class T> inline void chmax(S &a, T b){if(a<b)a=b;}

template<class T>
T max(T *arr, int N){
  int i;
  T res = arr[0];
  REP(i,1,N) chmax(res, arr[i]);
  return res;
}

template<class T>
T maxInd1(T *arr, int N){
  int i, res = 0;
  T m = arr[0];
  REP(i,1,N) if(m < arr[i]) m = arr[i], res = i;
  return res;
}

template<class T>
T maxInd2(T *arr, int N){
  int i, res = 0;
  T m = arr[0];
  REP(i,1,N) if(m <= arr[i]) m = arr[i], res = i;
  return res;
}

int N, M;
int in[100][100];

int cnt[102];

int main(){
  int i, j, k;

  reader(&N,&M);
  rep(i,M) rep(j,N) reader(in[i]+j);
  
  rep(i,M){
    k = maxInd1(in[i], N);
    cnt[k]++;
  }

  k = maxInd1(cnt, N);
  writerLn(k+1);
  
  return 0;
}