#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PI;
typedef long long LL;
typedef long double D;
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
#define MAX 200100
int n;
vector<int> res;
struct para{
  int first;
  int second;
  vector<int>* nrs;
  void dod(){
    R(i,nrs->size()){
      res.PB((*nrs)[i]);
    }
  }
}t[MAX];
bool q(para a,para b){
  if(a.FI != b.FI)
    return a.FI < b.FI;
  return a.SE < b.SE;
}
vector<para> wyn;
pair<LL,LL> licz(para a,para b){
  LL l = (b.FI - a.FI) * 1ll * a.SE * b.SE;
  LL m = (a.SE - b.SE) * 1ll * a.FI * b.FI;
  return MP(l,m);
}
bool spr(para a,para b, para c){
  pair<LL,LL> p1 = licz(a,b);
  pair<LL,LL> p2 = licz(b,c);
  LL l1 = p1.FI;
  LL m1 = p1.SE;
  LL l2 = p2.FI;
  LL m2 = p2.SE;
 // printf("%lld /%lld <? %lld/%lld\n",l1,m1,l2,m2);
  
  LL g = abs(__gcd(l1,l2));
  if(g!=0){
    l1 /= g;
    l2 /= g;
  }
  g = abs(__gcd(m1,m2));
  if(g!=0){
    m1 /= g;
    m2 /= g;
  }
 // printf("%lld /%lld <? %lld/%lld\n",l1,m1,l2,m2);
  return l1 * m2 < l2 * m1;
}
void add(para a){
  while(1){
    int pom = wyn.size();
    if(pom < 2)
      break;
    if(spr(wyn[pom-2],wyn[pom-1],a))
      wyn.pop_back();
    else
      break;
  }
  wyn.PB(a);
}
main(){
  make(n);
  R(i,n){
    make(t[i].FI);
    make(t[i].SE);
    t[i].nrs = new vector<int>(1,i);
  }
  sort(t,t+n,q);
  vector<para> pom;
  R(i,n){
    while(pom.size() && pom.back().SE <= t[i].SE && (pom.back().SE != t[i].SE || t[i].FI != pom.back().FI))
    {
      pom.pop_back();
    }
    if(pom.size() && pom.back().SE == t[i].SE && t[i].FI == pom.back().FI){
        pom.back().nrs->PB((*t[i].nrs)[0]);
    }else
      pom.PB(t[i]);
  }
  R(i,pom.size()){
    add(pom[i]);
  }
  R(i,wyn.size()){
    wyn[i].dod();
  }
  sort(ALL(res));
  R(i,res.size())
    printf("%d ",res[i]+1);
  puts("");
  R(i,n){
    delete t[i].nrs;
  }
}