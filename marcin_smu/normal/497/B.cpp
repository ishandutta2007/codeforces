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
#define maka2(A,B) scanf("%d%d",&A,&B)
#define db(A) printf("%s: %d\n",#A,A);
template<typename C> void ma(C& a,C b){if(a<b)a=b;}
template<typename C> void mi(C& a,C b){if(a>b)a=b;}
#define MAX 100010
int n,ost,il1[MAX],il2[MAX];
vector<int> a,b;
vector<PI> wyn;
void spr(int w){
  //printf("spr %d\n",w);
  int it = 0;
  int w1=0,w2=0;
  while(it < n){
    //printf("%d %d %d\n",it,w1,w2);
    int g1 = il1[it]+w - 1;
    int k1 = 1e9;
    if(g1 < a.size())
      k1 = a[g1];
    
    int g2 = il2[it]+w - 1;
    int k2 = 1e9;
    if(g2 < b.size())
      k2 = b[g2];
    
    //printf("%d %d\n",k1,k2);
    if(k1 < k2){
      w1++;
      it = k1+1;
    }else{
      w2++;
      it = k2+1;
    }
  }
  if(it == n && ((ost == 2) ^ (w1>w2)) && w1!=w2){
    wyn.PB(MP(max(w1,w2),w));
  }
}
main(){
  make(n);
  R(i,n){
    il1[i+1] = il1[i];
    il2[i+1] = il2[i];
    int pom;make(pom);
    if(pom == 1){
      a.PB(i);
      il1[i+1]++;
    }else{
      b.PB(i);
      il2[i+1]++;
    }
    ost = pom;
  }
  R(i,n)spr(i+1);
  sort(wyn.begin(),wyn.end());
  printf("%d\n",wyn.size());
  R(i,wyn.size())
    printf("%d %d\n",wyn[i].FI,wyn[i].SE);
}