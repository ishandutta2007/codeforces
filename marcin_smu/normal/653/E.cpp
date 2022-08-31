#include <bits/stdc++.h>

using namespace std;
#define MP make_pair
#define PB push_back
#define LD long double
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

template<class T> ostream& operator<<(ostream& os, vector<T> V) {
  os << "[";
  for (auto& tt : V) { os << tt << ","; }
  os << "]";
  return os;
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0) cout
#endif

#define MAX 300100

int n,m,k;

bool cz[MAX];
set<PII> s;

void nie(){
  cout << "impossible\n";
  exit(0);
}
#undef int
int main(){
#define int LL
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(11);
  cin >> n >> m >> k;
  int il0 = 0;
  R(i,m){
    int a,b;
    cin >> a >> b;
    a--;b--;
    if(s.insert({a,b}).SE){
      if(a == 0){
        il0++;
      }
      if(b == 0){
        il0++;
      }
    }
    s.insert({b,a});
  }
  if(n-1 - il0 < k)nie();
  
  int il = 0;
  F(i,1,n){
    if(!cz[i]){
      il++;
      vector<int> poza;
      R(j,n)if(i!=j)poza.PB(j);
      vector<int> w;
      w.PB(i);
      bool cz0 = 0;
      R(j,SZ(w)){
        int ak = w[j];
        cz[ak] = 1;
        if(ak == 0){
          cz0 = 1;
          continue;
        }
        R(k,SZ(poza)){
          if(s.find({ak,poza[k]}) == s.end()){
            w.PB(poza[k]);
            swap(poza[k],poza.back());
            poza.pop_back();
            k--;
          }
        }
      }
      debug(cz0,w);
      if(cz0 == 0)nie();
    }
  }
  if(il > k)nie();
  cout << "possible\n";
}