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
#define MAX 20010
int n,m,t;
int d[MAX];
int get_time(){
  int a,b,c;
  scanf("%d:%d:%d",&a,&b,&c);
  return a*3600 + b*60 + c;
}
priority_queue<PI> z;
int sum[MAX];
vector<int> wyny;
main(){
  make2(n,m);
  make(t);
  R(i,n){
    d[i] = get_time();
    z.push(MP(-d[i],-1));
  }
  int il = 0;
  int ost = 0;
  bool cz = 0;
  while(!z.empty()){
    PI ak = z.top();z.pop();
    if(ak.SE == -1){
      if(il != m){
        ost++;
        il++;
        if(il == m)cz = 1;
      }
      wyny.PB(ost);
      z.push(MP(ak.FI-t,ost));
      sum[ost]++;
    }else{
      sum[ak.SE]--;
      if(sum[ak.SE] == 0)
        il--;
    }
  }
  if(!cz){
    puts("No solution");
  }else{
    printf("%d\n",ost);
    R(i,n){
      printf("%d\n",wyny[i]);
    }
  }
  
}