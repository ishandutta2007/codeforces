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
#define db(A) printf("%s: %d\n",#A,A);
template<typename C> void ma(C& a,C b){if(a<b)a=b;}
template<typename C> void mi(C& a,C b){if(a>b)a=b;}
#define MAX 100010
int n,m;
set<PI> s;
struct pp{
  int FI,SE,nr;
}t[MAX],a[MAX];
bool q(pp a,pp b){
  return a.FI < b.FI;
}
int lim[MAX],wyn[MAX];
main(){
  make(n);
  R(i,n){
    make2(t[i].FI,t[i].SE);
    t[i].nr = i;
  }
  sort(t,t+n,q);
  make(m);
  R(i,m){
    make2(a[i].FI,a[i].SE);
    make(lim[i]);
    a[i].nr = i;
  }
  sort(a,a+m,q);
  int i = 0,j = 0;
  while(i < n || j < m){
    //printf("%d %d\n",t[i].FI,a[j].FI);
    if(j == m || (i!=n && t[i].FI < a[j].FI)){
    //  puts("i");
      auto x = s.lower_bound(MP(t[i].SE,-1));
      if(x == s.end()){
        puts("NO");
        return 0;
      }
      wyn[t[i].nr] = x->SE;
      lim[x->SE]--;
      if(lim[x->SE] == 0)s.erase(x);
      i++;
    }else{
    //  puts("j");
      s.insert(MP(a[j].SE,a[j].nr));
      j++;
    }
  }
  puts("YES");
  R(i,n)
    printf("%d ",wyn[i]+1);
  puts("");
}