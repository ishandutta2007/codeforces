#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PI;
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
#define db if(1)printf
template<typename C> void MA(C& a,C b){if(a<b)a=b;}
template<typename C> void MI(C& a,C b){if(a>b)a=b;}
#define MAX 201001
int n,m;
int dp[MAX];
vector<int> p;
vector<PI> k; 
multiset<int> pocz;
struct TV{
  int pocz;
  int kon;
  int c;
  int nr;
};
vector<TV> t;
bool qTV(TV a,TV b){
  return a.kon < b.kon;
}
vector<PI> cal;
void add(int dl,int gd){
  while(cal.size() && cal.back().FI < dl)
    cal.pop_back();
  cal.PB(MP(dl,gd));
}
LL licz(int a){
  int po = -1,ko = cal.size();
  while(po+1 != ko){
    int m = po + ko >> 1;
    if(cal[m].SE < a)
      po = m;
    else
      ko = m;
  }
  int wyn = -1;
  if(po != -1){
    MA(wyn,cal[po].SE + cal[po].FI - a);
  }
  if(ko != cal.size()){
    MA(wyn,cal[ko].FI);
  }
  return wyn;
}
int ll[MAX],rr[MAX];
main(){
  make2(n,m);
  R(i,n){
    int l,r;
    make2(l,r);
    p.PB(l);
    k.PB(MP(r,l));
    ll[i] = l;
    rr[i] = r;
  }
  sort(ALL(p));
  sort(ALL(k));
  LL wyn = 0;TV naj;
  
  R(i,m){
    int a,b,c;
    make2(a,b);
    make(c);
    t.PB({a,b,c,i});
  }
  sort(ALL(t),qTV);
  int ip=0,ik=0,it=0;
  while(1){
    int ak = 2e9;
    if(ip < p.size())MI(ak,p[ip]);
    if(ik < k.size())MI(ak,k[ik].FI);
    if(it < t.size())MI(ak,t[it].kon);
    if(ak == 2e9)break;
    while(ip != p.size() && p[ip] == ak){
      pocz.insert(p[ip]);
      ip++;
    }
    while(ik != k.size() && k[ik].FI == ak){
      pocz.erase(pocz.find(k[ik].SE));
      add(k[ik].FI - k[ik].SE,k[ik].SE);
      ik++;
    }
    while(it != t.size() && t[it].kon == ak){
      LL res = -1;
      if(pocz.size()){
        MA(res,(LL)ak - *(pocz.begin()));
      }
      MA(res,licz(t[it].pocz));
      res = min(res,(LL)t[it].kon - t[it].pocz);
      res *= t[it].c;
      if(wyn < res){
        wyn = res;
        naj = t[it];
      }
      it++;
    }
  }
  printf("%lld\n",wyn);
  if(wyn != 0){
    R(i,n){
      if((min(rr[i],naj.kon) - max(ll[i],naj.pocz)) *1ll * naj.c == wyn){
        printf("%d %d\n",i+1,naj.nr+1);
        return 0;
      }
    }
  }
}