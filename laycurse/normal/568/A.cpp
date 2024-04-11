#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define mygc(c) (c)=getchar()
#define mypc(c) putchar(c)

#define ll long long
#define ull unsigned ll

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
template <class T, class S> void reader(T *x, S *y){reader(x);reader(y);}

void writer(int x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
template<class T> void writerLn(T x){writer(x,'\n');}

int getPrime(int N, int res[]){int i,a,b,s=1,f[4780],S=1;const int r=23000;bool B[r],*p=B;N/=2;res[0]=2;b=min(r,N);REP(i,1,b)p[i]=1;REP(i,1,b)if(p[i]){res[s++]=2*i+1;f[S]=2*i*(i+1);if(f[S]<N){for(;f[S]<r;f[S]+=res[S])p[f[S]]=0;S++;}}for(a=r;a<N;a+=r){b=min(a+r,N);p-=r;REP(i,a,b)p[i]=1;REP(i,1,S)for(;f[i]<b;f[i]+=res[i])p[f[i]]=0;REP(i,a,b)if(p[i])res[s++]=2*i+1;}return s;}

#define MX 1200000
int ps, p[MX];
int A[MX], B[MX];

int main(){
  int i, j, k, len;
  int P, Q;
  char buf1[100], buf2[100], buf[100];

  reader(&P,&Q);

  ps = getPrime(MX, p);
  rep(i,ps) A[p[i]]++;

  REP(i,1,10000){
    sprintf(buf1, "%d", i);
    len = strlen(buf1);
    rep(j,len+1) buf2[j] = buf1[j];

    reverse(buf2, buf2+len);
    sprintf(buf, "%s%s", buf1, buf2);
    sscanf(buf, "%d", &k);
    if(k < MX) B[k]++;

    sprintf(buf, "%s%s", buf1, buf2+1);
    sscanf(buf, "%d", &k);
    if(k < MX) B[k]++;
  }

  REP(i,1,MX) A[i] += A[i-1];
  REP(i,1,MX) B[i] += B[i-1];

  k = -1;
  rep(i,MX){
    if((ll)Q*A[i] <= (ll)P*B[i]) k = i;
  }

  writerLn(k);

  return 0;
}