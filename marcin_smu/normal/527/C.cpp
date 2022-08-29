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
LL w,h;
int n;
struct{
  multiset<int> dl;
  set<int> s;
  void init(int n){
    s.insert(0);
    s.insert(n);
    dl.insert(n);
  }
  void add(int a){
    auto xxx = s.lower_bound(a);
    int nast = *xxx;
    xxx--;
    int pop = *xxx;
    s.insert(a);
    dl.erase(dl.find(nast - pop));
    dl.insert(a - pop);
    dl.insert(nast - a);
  }
  LL war(){
    auto xxx = dl.end();xxx--;
    return *xxx;
  }
}s1,s2;
main(){
  scanf("%lld%lld",&w,&h);
  make(n);
  s1.init(w);
  s2.init(h);
  R(i,n){
    char z;int v;
    scanf(" %c%d",&z,&v);
    if(z == 'V'){
      s1.add(v);
    }else
      s2.add(v);
    printf("%lld\n",s1.war()*s2.war());
  }
}