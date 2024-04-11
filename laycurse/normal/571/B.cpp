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

template<class S, class T> inline void chmin(S &a, T b){if(a>b)a=b;}
template<class S, class T> inline void chmax(S &a, T b){if(a<b)a=b;}

char memarr[17000000]; void *mem = memarr;
#define MD 1000000007
#define INF 1000000000000000000LL

int N, K;
int A[400000];
ll dp[5100][5100];

int sn, ln, ss, ls;

int main(){
  int i, j, k;
  int now;

  reader(&N,&K);
  rep(i,N) reader(A+i);
  sort(A, A+N);

  ln = N % K;
  sn = K - ln;
  
  ss = N / K;
  ls = ss+1;

//  printf("small len %d num %d\n",ss,sn);
//  printf("large len %d num %d\n",ls,ln);
//  printf("N %d %d\n",N,ss*sn+ls*ln);

  rep(i,sn+1) rep(j,ln+1) dp[i][j] = INF;
  dp[0][0] = 0;
  rep(i,sn+1) rep(j,ln+1) if(dp[i][j] < INF){
    now = i*ss + j*ls;
    if(i<sn){
      chmin(dp[i+1][j], dp[i][j] + A[now+ss-1]-A[now]);
    }
    if(j<ln){
      chmin(dp[i][j+1], dp[i][j] + A[now+ls-1]-A[now]);
    }
  }

  writerLn(dp[sn][ln]);

  return 0;
}