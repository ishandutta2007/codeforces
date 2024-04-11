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

int x[MAX],p[MAX],per[MAX];
bool q(int a,int b){
  return p[a] < p[b];
}
set<PII> todo;
void dodaj(int po,int ko){
  if(ko <= po)return;
  todo.insert({ko,po});
  debug("dodaje", po ,ko);
}
const int inf = 1e12;
#undef int
int main(){
#define int LL
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout<<fixed<<setprecision(11);
  int n,d,m;
  cin >> d >> n >> m;
  R(i,m){
    cin >> x[i] >> p[i];
    per[i] = i;
  }
  sort(per,per+m,q);
  int res = 0;
  dodaj(n,d);
  R(_,m){
    int i = per[_];
    debug(x[i], x[i]+n, p[i]);
    while(1){
      debug(SZ(todo));
      auto xxx = todo.upper_bound({x[i],inf});
      if(xxx == todo.end())break;
      int po,ko;
      tie(ko,po) = *xxx;
      debug(po,ko);
      int pom = min(ko,x[i]+n) - max(po,x[i]);
      if(pom <= 0)break;
      todo.erase(xxx);
      debug(pom);
      res += p[i] * pom;
      dodaj(po,x[i]);
      dodaj(x[i]+n,ko);
    }
  }
  if(todo.empty())
    cout << res << "\n";
  else
    cout << "-1\n";
}