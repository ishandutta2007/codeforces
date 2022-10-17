#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N=3*100000000;
int n;
unsigned int A,B,C,D, ans;
const int F=100000;
char s[F];
int p[F],pri,ptr[F],s2[F];
int a_,b_,i_=-1,m_;

inline void go(int _p) {
    int count = 0, _n = n;
    unsigned int p = _p;
    while (_n) {
      _n /= p;
      count += _n;
    }

    ans = ans + (((A*p + B)*p + C)*p + D) * count;
}

void sieve4(int n) {
   const int S=int(sqrt(n));
   p[pri++]=2;

   go(2);
   if (2>b_) return;
   if (2>=a_) i_++;
   if (i_==m_) i_=0;

   int i;
   for (i=3;i<S;i+=2) if (!s[i/2]) {
      p[pri++]=i;
      
      go(i);
      if (i>b_) return;
      if (i>=a_) i_++;
      if (i_==m_) i_=0;

      int j;
      for (j=3*i;j<S;j+=2*i) s[j/2]=1;
      ptr[pri-1]=j;
   }
   int LEN=2*3*5*7*11*13*2;
   int pocz=i,kon=min(pocz+LEN,n);
   int oldpri=pri;
   for(int ii=1;ii<6;++ii) {
      for(int j=ptr[ii]; j<kon; j+=2*p[ii]) s2[(j-pocz)/2]=1;
   }
   for(int ii=6;ii<oldpri;++ii) ptr[ii]/=2; i/=2;
   while (pocz<n) {
      REP(ii,LEN/2+3) s[ii]=s2[ii];
      for(int ii=6;ii<oldpri;++ii) {
         int j;
	 for (j=ptr[ii]; j<kon/2; j+=p[ii]) s[(j-pocz/2)]=1;
	 ptr[ii]=j;
      }
      for (;i<kon/2;i+=1) if (!s[(i-pocz/2)]) {
	 pri++;
	 const int p_=2*i+1;
	 if (p_>b_) return;
	 if (p_>=a_) i_++;
	 if (i_==m_) i_=0;
         go(p_);
      }
      pocz=kon,kon=min(pocz+LEN,n);
   }
}

int main() {
  scanf("%d%u%u%u%u",&n,&A,&B,&C,&D);

  a_=2; b_=n; m_=1;
  sieve4(N);

  printf("%u\n", ans);
}