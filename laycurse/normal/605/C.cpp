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

char memarr[37000000]; void *mem = memarr;
#define MD 1000000007

template<class S, class T> inline void chmin(S &a, T b){if(a>b)a=b;}
template<class S, class T> inline void chmax(S &a, T b){if(a<b)a=b;}

template<class T> void sort(int N, T a[], void *mem = NULL){sort(a,a+N);}
template<class T1, class T2> void sort(int N, T1 a[], T2 b[], void *mem){int i;pair<T1,T2> *r=(pair<T1, T2>*)mem;rep(i,N)r[i].first=a[i],r[i].second=b[i];sort(r,r+N);rep(i,N)a[i]=r[i].first,b[i]=r[i].second;}
template<class T1, class T2, class T3> void sort(int N, T1 a[], T2 b[], T3 c[], void *mem){int i;pair<T1,pair<T2,T3> > *r=(pair<T1,pair<T2,T3> >*)mem;rep(i,N)r[i].first=a[i],r[i].second.first=b[i],r[i].second.second=c[i];sort(r,r+N);rep(i,N)a[i]=r[i].first,b[i]=r[i].second.first,c[i]=r[i].second.second;}
template<class T1, class T2, class T3, class T4> void sort(int N, T1 a[], T2 b[], T3 c[], T4 d[], void *mem){int i;pair<pair<T1,T2>,pair<T3,T4> > *r=(pair<pair<T1,T2>,pair<T3,T4> >*)mem;rep(i,N)r[i].first.first=a[i],r[i].first.second=b[i],r[i].second.first=c[i],r[i].second.second=d[i];sort(r,r+N);rep(i,N)a[i]=r[i].first.first,b[i]=r[i].first.second,c[i]=r[i].second.first,d[i]=r[i].second.second;}

int N, P, Q, A[100000], B[100000];

double pa[100000], pb[100000]; int ps;
double qa[100000], qb[100000]; int qs;

int pind[100000]; double pval[100000];
int qind[100000]; double qval[100000];

inline double evl(double a1, double b1, double a2, double b2){
  return (a1-b1-a2+b2) / (a1*b2-b1*a2);
}

int main(){
  int i, j, k, st, ii, jj;
  double x, y;
  double res = 1e100, tmp, opt;

  srand(time(NULL));
  
  reader(&N,&P,&Q);
  rep(i,N) reader(A+i,B+i);

  rep(i,N){
    x = A[i] / (double)P;
    y = B[i] / (double)Q;
    if(x > y) pa[ps]=x, pb[ps++]=y;
    if(x < y) qa[qs]=x, qb[qs++]=y;
    chmin(res, max(1/x, 1/y));
  }
  
  sort(N, A, B, mem);
  rep(i,N) if(A[i]>A[N-1] || B[i]>B[N-1]) break;
  if(i==N){ writerLn(res); return 0; }
  if(ps==0 || qs==0){ writerLn(res); return 0; }

  sort(ps, pa, pb, mem);
  reverse(pa, pa+ps);
  reverse(pb, pb+ps);
  sort(qs, qb, qa, mem);
  reverse(qa, qa+qs);
  reverse(qb, qb+qs);

  k = 0;
  rep(i,ps){
    if(k && pa[i] <= pa[k-1] && pb[i] <= pb[k-1]) continue;
    pa[k] = pa[i];
    pb[k] = pb[i];
    k++;
  }
  ps = k;

  k = 0;
  rep(i,qs){
    if(k && qa[i] <= qa[k-1] && qb[i] <= qb[k-1]) continue;
    qa[k] = qa[i];
    qb[k] = qb[i];
    k++;
  }
  qs = k;

  rep(st,5){
    i = rand()%ps;
    rep(j,qs) qind[j]=j, qval[j]=evl(pa[i],pb[i],qa[j],qb[j]);
    j = rand()%qs;
    rep(i,ps) pind[i]=i, pval[i]=evl(pa[i],pb[i],qa[j],qb[j]);
    sort(ps, pval, pind, mem);
    sort(qs, qval, qind, mem);

    rep(ii,min(1000,ps)) rep(jj,min(1000,qs)){
      i = pind[ii];
      j = qind[jj];
      tmp = evl(pa[i],pb[i],qa[j],qb[j]);
      chmin(res, tmp);
    }
  }
  writerLn(res);

/*  res = 1e100;
  rep(i,ps){
    rep(j,qs){
      tmp = evl(pa[i],pb[i],qa[j],qb[j]);
//      if(res > tmp) printf("%d %d\n",i,j);
      chmin(res, tmp);
    }
  }
  writerLn(res);
  writerLn(ps,qs);
*/
  return 0;
}