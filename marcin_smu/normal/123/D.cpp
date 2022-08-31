#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
typedef double D;
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define R(I,N) for(int I=0;I<N;I++)
#define F(I,A,B) for(int I=A;I<B;I++)
#define FD(I,N) for(int I=N-1;I>=0;I--)
#define make(A) scanf("%d",&A)
#define make2(A,B) scanf("%d%d",&A,&B)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define db if(1)printf
template<typename C> void maxi(C& a,C b){if(a<b)a=b;}
template<typename C> void mini(C& a,C b){if(a>b)a=b;}

struct SA{
  vector<pair<PII, int>> x;
  vector<int> suf; // <- numery kolejnych sufiksow w porzadku leksykograficznym
  vector<int> rankk; // <- odwrotnosc tablicy sufiksowej (suf)
  vector<int> lcp; //lcp[i] == lcp(suf[i-1],suf[i])
  int *z;
  int n;
  SA(int *z, int n):z(z), n(n){
    suf.resize(n);
    rankk.resize(n);
    x.resize(n);
    
    R(i,n)x[i] = {{z[i], 0}, i};
    mapuj();
    int krok = 1;
    while(krok < n){
      R(i,n)x[i] = {{rankk[i], i+krok < n ? rankk[i+krok] : -1}, i};
      mapuj();
      krok*=2;
    }
    R(i,n)suf[rankk[i]] = i;
    
    //LCP - opcjnolanie
    lcp.resize(n);
    int k = 0;
    R(i,n){
      int ak = rankk[i];
      if(ak)
        while(z[ suf[ak] + k ] == z[ suf[ak-1] + k ])
          k++;
      lcp[rankk[i]] = k;
      if(k)k--;
    }
    //koniec LCP
    
  };
  void mapuj(){
    sort(ALL(x));
    int id = 0;
    R(i,n){
      if(i && x[i-1].FI != x[i].FI) id++;
      rankk[x[i].SE] = id;
    }
  }
};
#define MAX 100001
char z[MAX];
int zint[MAX];
int n;
main(){
  scanf("%s",z);
  while(z[n]){
    zint[n] = z[n];
    n++;
  }
  SA sa(zint,n);
  vector<PII> stos;
  stos.PB({-1,0});
  LL wyn = 0;
  R(i,n){
    stos.PB({i,n-sa.suf[i]});
    int lcp = i != n-1 ? sa.lcp[i+1] : 0;
        while(!stos.empty() && stos.back().SE > lcp){
      if(SZ(stos) >=2 && stos.back().SE == stos[SZ(stos)-2].SE){
        stos.pop_back();
        continue;
      }
      int tnij = lcp;
      if(SZ(stos) >=2 && stos[SZ(stos)-2].SE > lcp)
        tnij = stos[SZ(stos)-2].SE;
      int sze = i - stos.back().FI + 1;
      wyn += sze*1ll*(sze+1)/2 * (stos.back().SE - tnij);
      stos.back().SE = tnij;
    }
  }
  printf("%lld\n",wyn);
}