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
#define MAX 301
int n,t[MAX],k[MAX];
priority_queue<PI> q;
unordered_map<int,int> m;
void add(int g,int k){
  if(m.find(g)==m.end() || m[g] > k){
    m[g] = k;
    q.push(MP(-k,g));
  }
}
main(){
  make(n);
  R(i,n)make(t[i]);
  R(i,n)make(k[i]);
  add(0,1);
  while(!q.empty()){
    PI ak = q.top();q.pop();
    if(m[ak.SE] != -ak.FI)continue;
    if(ak.SE == 1){
      printf("%d\n",-ak.FI-1);
      return 0;
    }
    R(i,n){
      add(__gcd(ak.SE,t[i]),k[i] - ak.FI);
    }
  }
  puts("-1");
}