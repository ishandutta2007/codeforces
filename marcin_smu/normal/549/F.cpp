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
template<typename C> void maxi(C& a,C b){if(a<b)a=b;}
template<typename C> void mini(C& a,C b){if(a>b)a=b;}
#define MAX 1000010
int n,k;
int t[MAX],p[MAX],sp[MAX];
bool q(int a,int b){
  return t[a] > t[b];
}
vector<int> zap[MAX],zap2[MAX];
void dodaj(int po,int ko,int il){
  il = (il%k+k)%k;
// printf("dodaj %d %d %d\n",po,ko,il);
  if(po>=0)zap[po].PB(il);
  zap2[ko].PB(il);
}
set<int> s;
void add(int a){
 // printf("add %d\n",a);
  auto x = s.insert(a).FI;
  auto y = x;
  y--;
  int pop = *y;
  y = x;
  y++;
  int nast = *y;
  //printf("%d %d\n",pop,nast);
  if(a - pop < nast - a){
    int il = 0;
    int pom = sp[a+1];
    dodaj(a,nast,pom);
    for(int i = a-1;i>pop;i--){
      il += t[i];
      il %= k;
      dodaj(a,nast,pom - il);
    }
  }else{
    int il = 0;
    int pom = sp[a];
    dodaj(pop,a,pom);
    for(int i = a+1;i < nast;i++){
      il += t[i];
      il %= k;
      dodaj(pop,a,pom+il);
    }
  }
}
int il[MAX];
main(){
  make2(n,k);
  R(i,n){
    make(t[i]);
    sp[i+1] = sp[i] + t[i];
    sp[i+1] %= k;
    p[i] = i;
  }
  sort(p,p+n,q);
  s.insert(n);
  s.insert(-1);
  R(i,n)add(p[i]);
  LL wyn = 0;
  R(i,n+1){
    il[sp[i]]++;
    R(j,zap[i].size())
      wyn -= il[zap[i][j]];
    R(j,zap2[i].size())
      wyn += il[zap2[i][j]];
  }
  printf("%lld\n",wyn - n);
}