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
#define SZ(x) ((int)(x).size())
#define db if(1)printf
template<typename C> void MA(C& a,C b){if(a<b)a=b;}
template<typename C> void MI(C& a,C b){if(a>b)a=b;}
int n,m;
struct tr{
  int p,k;
  int a,b;
  bool operator<(const tr &pom)const{
    return k < pom.k;
  }
  void dzielU(int s);
  void dzielL(int s);
}x;
set<tr> se;
void tr::dzielU(int s){
  printf("%d\n",b+(k-s));
//   printf("<<%d %d %d>>\n",a,p,k);
  if(s!=p)se.insert({p,s-1,a,b+(k-s)+1});
  if(s!=k)se.insert({s+1,k,1,b});
}
void tr::dzielL(int s){
  printf("%d\n",a+(s-p));
  if(s!=p)se.insert({p,s-1,a,1});
  if(s!=k)se.insert({s+1,k,a+(s-p)+1,b});
}
set<int> wyk;
main(){
  make2(n,m);
  se.insert({1,n,1,1});
  R(i,m){
    int a,b;
    make2(a,b);
    char z;
    scanf(" %c",&z);
    if(wyk.find(a)!=wyk.end()){
      puts("0");
      continue;
    }
    wyk.insert(a);
    auto xxx = se.lower_bound({0,a,0,0});
    x = *xxx;
    se.erase(xxx);
    if(z == 'U')
      x.dzielU(a);
    else
      x.dzielL(a);
//     for(auto a:se){
//       printf("%d %d %d %d\n",a.p,a.k,a.a,a.b);
//     }
//     puts("");
  }
}