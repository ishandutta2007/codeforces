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
#define INF 1000000000000000000LL

template<class T> inline T min(T a, T b, T c){return min(min(a,b),c);}
template<class T> inline T min(T a, T b, T c, T d){return min(min(a,b),min(c,d));}
template<class T> inline T max(T a, T b, T c){return max(max(a,b),c);}
template<class T> inline T max(T a, T b, T c, T d){return max(max(a,b),max(c,d));}

template<class T> T GCD(T a,T b){T r; while(a)r=b,b=a,a=r%a; return b;}
template<class T> T LCM(T a,T b){return a/GCD(a,b)*b;}

template<class T> void unique(T arr[], int &sz, int sorted=0){int i,k=0;if(!sorted)sort(arr,arr+sz);rep(i,sz)if(!k||arr[k-1]!=arr[i])arr[k++]=arr[i];sz=k;}

template<class T> inline int getFactors(T n, T res[], int num[]){
  int i, c, s = 0;
  for(i=2;(ll)i*i<=n;i++){
    if(n%i==0){
      res[s] = i;
      c = 0;
      while(n%i==0) n/=i, c++;
      if(num!=NULL) num[s] = c;
      s++;
    }
  }
  if(n>1){
    res[s] = n;
    if(num!=NULL) num[s] = 1;
    s++;
  }
  return s;
}

int N, C1, C2;
int A[1000000];

ll dp1[1000001], dp2[1000001], dp3[1000001];

int main(){
  int i, j, k, m, x;
  int fac[1000], fs;
  ll res, tmp;

  reader(&N,&C1,&C2);
  rep(i,N) reader(A+i);

  fs = 0;
  REP(i,-1,2){
    fs += getFactors(A[0]+i, fac+fs, NULL);
    fs += getFactors(A[N-1]+i, fac+fs, NULL);
  }
  unique(fac, fs);

  res = INF;
  rep(m,fs){
    x = fac[m];
    dp1[0] = dp2[0] = dp3[0] = 0;
    rep(i,N){
      k = A[i]%x;
      if(k==0){
        dp1[i+1] = dp1[i];
        dp2[i+1] = min(dp1[i], dp2[i]+C1);
        dp3[i+1] = min(dp2[i], dp3[i]);
      } else if(k==1 || k==x-1){
        dp1[i+1] = dp1[i] + C2;
        dp2[i+1] = min(dp1[i]+C2, dp2[i]+C1);
        dp3[i+1] = min(dp2[i]+C2, dp3[i]+C2);
      } else {
        dp1[i+1] = INF;
        dp2[i+1] = min(dp1[i], dp2[i]) + C1;
        dp3[i+1] = dp2[i+1];
      }
    }
    res = min(res, dp1[N], dp2[N], dp3[N]);
  }

  writerLn(res);

  return 0;
}