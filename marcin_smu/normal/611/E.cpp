#include <bits/stdc++.h>

using namespace std;
#define MP make_pair
#define PB push_back
#define LL long long
#define int LL
#define FI first
#define SE second
#define R(i,n) for(int i=0;i<n;i++)
#define F(i,a,b) for(int i=a;i<b;i++)
#define FD(i,n) for(int i=n-1;i>=0;i--)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define PII pair<int,int>
#define VI vector<int>
template<class C> void mini(C&a4, C b4){a4=min(a4,b4);}
template<class C> void maxi(C&a4, C b4){a4=max(a4,b4);}

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a){
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1,a...);
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(C) {for(auto&c:C)cerr<<c<<",";cerr<<endl;}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(C) {}
#define cerr if(0) cout
#endif
#define MAX 200010
int n;
multiset<int> d,dd;
int a,b,c;
void kill(int k){
  auto x = dd.lower_bound(k+1);
  if(x == dd.begin())return;
  x--;
  dd.erase(x);
}
bool spr(int il){
  debug("spr", il);
  dd = d;
  while(!dd.empty()){
    auto x = *dd.rbegin();
    if(x > a+c){
      il--;
      dd.erase(dd.find(x));
      kill(a);
    }else
      break;
  }
  while(!dd.empty()){
    auto x = *dd.rbegin();
    if(x > max(c,a+b)){
      il--;
      dd.erase(dd.find(x));
      kill(b);
    }else
      break;
  }
  int ila = il;
  int ilb = il;
  int ilc = il;
  if (c < a+b){
    while(!dd.empty()){
      auto x = *dd.rbegin();
      if(x > c){
        ilb--;
        ila--;
        dd.erase(dd.find(x));
      }else
        break;
    }
  }
  
  while(ilc > 0){
    auto x = dd.lower_bound(c+1);
    if(x == dd.begin())break;
    ilc--;
    x--;
    debug("c",*x);
    dd.erase(x);
  }
  
  while(!dd.empty()){
    auto x = *dd.rbegin();
    if(x > b){
      if(x > a+b)return false;
      ilb--;
      ila--;
      dd.erase(dd.find(x));
    }else
      break;
  }
  
  
  while(ilb > 0){
    auto x = dd.lower_bound(b+1);
    if(x == dd.begin())break;
    ilb--;
    x--;
    debug("b",*x);
    dd.erase(x);
  }
  
  while(ila > 0){
    auto x = dd.lower_bound(a+1);
    if(x == dd.begin())break;
    ila--;
    x--;
    debug("a",*x);
    dd.erase(x);
  }
  if(ila < 0 || ilb < 0 || ilc < 0)return false;
  debug(SZ(dd));
  return dd.empty();
}
#undef int
int main(){
#define int LL
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout<<fixed<<setprecision(11);
  cin >> n;
  vector<int> pom;
  R(i,3){
    int pom2;
    cin >> pom2;
    pom.PB(pom2);
  }
  sort(ALL(pom));
  a = pom[0];
  b = pom[1];
  c = pom[2];
  int res=0;
  R(i,n){
    int pom;
    cin >> pom;
    if(pom > a + b + c){
      cout << "-1\n";
      return 0;
    }
    if(pom > b + c){
      res++;
    }else{
      d.insert(pom);
    }
  }
//   for(int x:d){
//     debug(x);
//   }
  int p = -1,k=n;
  while(p+1 != k){
    int m = (p+k)/2;
    if(spr(m))
      k = m;
    else
      p = m;
  }
  cout << k + res << endl;
}