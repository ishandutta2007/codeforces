#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<utility>
#include<iostream>
#include<cmath>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

int main(){
  ll i,j,k,l,m,n,a;
  double b, c, chk;
  int fg = 0;

  cin >> n;

  for(a=0;a<63;a++){
    b = (1LL<<a) - 1;
    b = 2*b-1;
    c = 2*n;
    chk = (-b + sqrt(b*b+4*c))/2;

    REP(k,chk-100,chk+100){
      if(k <= 0 || k > 3000000000LL) continue;
      if(k%2==0) continue;
      m = (1LL<<a) - 1;
      if(m*k/k != m) continue;
      m *= k;
      m += k*(k-1)/2;
      if(m!=n) continue;
      fg++;
      cout << (1LL<<a) * k << endl;
    }
  }

  if(!fg) cout << -1 << endl;

  return 0;
}