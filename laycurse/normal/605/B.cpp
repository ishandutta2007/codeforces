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

template<class T> void sort(int N, T a[], void *mem = NULL){sort(a,a+N);}
template<class T1, class T2> void sort(int N, T1 a[], T2 b[], void *mem){int i;pair<T1,T2> *r=(pair<T1, T2>*)mem;rep(i,N)r[i].first=a[i],r[i].second=b[i];sort(r,r+N);rep(i,N)a[i]=r[i].first,b[i]=r[i].second;}
template<class T1, class T2, class T3> void sort(int N, T1 a[], T2 b[], T3 c[], void *mem){int i;pair<T1,pair<T2,T3> > *r=(pair<T1,pair<T2,T3> >*)mem;rep(i,N)r[i].first=a[i],r[i].second.first=b[i],r[i].second.second=c[i];sort(r,r+N);rep(i,N)a[i]=r[i].first,b[i]=r[i].second.first,c[i]=r[i].second.second;}
template<class T1, class T2, class T3, class T4> void sort(int N, T1 a[], T2 b[], T3 c[], T4 d[], void *mem){int i;pair<pair<T1,T2>,pair<T3,T4> > *r=(pair<pair<T1,T2>,pair<T3,T4> >*)mem;rep(i,N)r[i].first.first=a[i],r[i].first.second=b[i],r[i].second.first=c[i],r[i].second.second=d[i];sort(r,r+N);rep(i,N)a[i]=r[i].first.first,b[i]=r[i].first.second,c[i]=r[i].second.first,d[i]=r[i].second.second;}

int N, M;
int A[100000], B[100000], ind[100000];

int res1[100000], res2[100000];

int main(){
  int i, j, k;
  int con = 0;
  int ua = 0, ub = 2;

  reader(&N,&M);
  rep(i,M) reader(A+i,B+i), B[i] *= -1;
  rep(i,M) ind[i] = i;
  sort(M, A, B, ind, mem);

  rep(i,M){
    if(B[i]==0){
      if(ub > con){ writerLn(-1); return 0; }
      res1[ind[i]] = ua;
      res2[ind[i]] = ub;
      ua++;
      if(ua+1==ub) ua=0, ub++;
    } else {
      res1[ind[i]] = con;
      res2[ind[i]] = con+1;
      con++;
    }
  }

  rep(i,M) res1[i]++, res2[i]++;
  rep(i,M) writerLn(res1[i],res2[i]);

  return 0;
}