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

char memarr[77000000]; void *mem = memarr;
#define MD 1000000007
#define INF 1000000000

int getPrime(int N, int res[]){int i,a,b,s=1,f[4780],S=1;const int r=23000;bool B[r],*p=B;N/=2;res[0]=2;b=min(r,N);REP(i,1,b)p[i]=1;REP(i,1,b)if(p[i]){res[s++]=2*i+1;f[S]=2*i*(i+1);if(f[S]<N){for(;f[S]<r;f[S]+=res[S])p[f[S]]=0;S++;}}for(a=r;a<N;a+=r){b=min(a+r,N);p-=r;REP(i,a,b)p[i]=1;REP(i,1,S)for(;f[i]<b;f[i]+=res[i])p[f[i]]=0;REP(i,a,b)if(p[i])res[s++]=2*i+1;}return s;}
int ps, p[100000];

int N, L[333], C[333];

int lis[20], liss;
int dp[5000];

int main(){
  int i, j, k, x, mask;
  int res = INF, tmp;

  ps = getPrime(100000, p);

  reader(&N);
  rep(i,N) reader(L+i);
  rep(i,N) reader(C+i);

  rep(k,N){
    j = L[k];
    liss = 0;
    rep(i,ps){
      if(p[i]*p[i] > j) break;
      if(j%p[i]==0){
        while(j%p[i]==0) j/=p[i];
        lis[liss++] = p[i];
      }
    }
    if(j>1) lis[liss++] = j;

    rep(i,1<<liss) dp[i] = INF;
    dp[0] = 0;
    rep(x,N) if(k!=x){
      mask = 0;
      rep(i,liss) if(L[x]%lis[i]) mask |= (1<<i);
      rep(i,1<<liss) dp[i|mask] = min(dp[i|mask], dp[i]+C[x]);
    }
    res = min(res, dp[(1<<liss)-1]+C[k]);
  }

  if(res>=INF) res = -1;
  writerLn(res);

  return 0;
}