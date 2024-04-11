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
#define MAX 101001
int n,m;
int ta[MAX],tb[MAX];
int tc[MAX],td[MAX];
int mas = 0,mis = 0;
struct pkt{
  int x,y;
  int kt;
};
bool il_wek(pkt a,pkt b){
  LL pom = a.x * 1ll * b.y - a.y * 1ll * b.x;
  if(pom != 0)return pom > 0;
  return a.kt < b.kt;
}
vector<pkt> pkty;
void maks(){
  puts("Max");
  exit(0);
}
int x,y;
bool wyp(pkt a,pkt b,pkt c){
  return (b.x - a.x) *1ll * (c.y - a.y) < (c.x - a.x) *1ll * (b.y - a.y);
}
main(){
  make2(n,m);
  scanf("%*d%*d");
  R(i,n){
    make2(ta[i],tb[i]);
    pkty.PB({ta[i],tb[i],0});
  }
  int mtc = 0,mtd =0;
  R(i,m){
    make2(tc[i],td[i]);
    pkty.PB({tc[i],td[i],1});
    MA(mtc,tc[i]);
    MA(mtd,td[i]);
  }
  pkty.PB({mtc,0,1});
  pkty.PB({0,mtd,1});
    
  mas = 0;
  mis = 0;
  R(i,n)MA(mas,ta[i]);
  R(i,m)MA(mis,tc[i]);
  if(mas >= mis)maks();
  mas = 0;
  mis = 0;
  R(i,n)MA(mas,tb[i]);
  R(i,m)MA(mis,td[i]);
  if(mas >= mis)maks();
  
  sort(ALL(pkty),il_wek);
  vector<pkt> o;
  R(i,pkty.size()){
 //   printf("%d %d\n",pkty[i].x,pkty[i].y);
    while(o.size() >= 2 && wyp(o[SZ(o)-2], o.back(), pkty[i]))
      o.pop_back();
    if(o.empty() || pkty[i].x != o.back().x || pkty[i].y != o.back().y)
      o.push_back(pkty[i]);
  }
//  puts("");
  R(i,SZ(o)){
 //   printf("%d %d\n",o[i].x,o[i].y);
    if(o[i].kt == 0)maks();
  }
  puts("Min");
}