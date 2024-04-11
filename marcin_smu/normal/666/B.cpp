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

#define MAX 3001
int odl[MAX][MAX];
int n,m;
vector<int> d[MAX];
vector<PII> najdo[MAX],najod[MAX];
const int inf = 1e9;
void bfs(int a,int* odl){
  R(i,n)odl[i] = inf;
  vector<int> s1,s2;
  s1.PB(a);
  odl[a] = 0;
  int od = 0;
  while(SZ(s1)){
    od++;
    for(auto x:s1){
      for(int el:d[x]){
        if(odl[el] == inf){
          odl[el] = od;
          s2.PB(el);
        }
      }
    }
    s1.clear();
    swap(s1,s2);
  }
}
#undef int
int main(){
#define int LL
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(11);
  cin >> n >> m;
  R(i,m){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    d[a].PB(b);
  }
  R(i,n){
    bfs(i,odl[i]);
  }
  R(i,n){
    vector<PII> pdo,pod;
    R(j,n)if(i!=j){
      if(odl[i][j] < inf/2)
        pod.PB({odl[i][j],j});
      if(odl[j][i] < inf/2)
        pdo.PB({odl[j][i],j});
    }
    sort(ALL(pdo),greater<PII>());
    sort(ALL(pod),greater<PII>());
    R(j,min(SZ(pdo),3ll)){
      najdo[i].PB(pdo[j]);
    }
    R(j,min(SZ(pod),3ll)){
      najod[i].PB(pod[j]);
    }
  }
  int wyn = 0;
  int a,b,c,d;
  R(i,n)R(j,n)if(i!=j && odl[i][j] < inf/2){
    for(auto xx:najdo[i])if(xx.SE != j){
      for(auto yy:najod[j])if(yy.SE != xx.SE && yy.SE != i){
        int pom = xx.FI + yy.FI + odl[i][j];
        if(pom > wyn){
          wyn = pom;
          a = xx.SE;
          b = i;
          c = j;
          d = yy.SE;
        }
      }
    }
  }
  debug(wyn);
  cout << a+1 << " " << b+1 << " " << c+1 << " " << d+1 << "\n";
}