#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

template<class C> void mini(C& _a4, C _b4) { _a4 = min(_a4, _b4); }
template<class C> void maxi(C& _a4, C _b4) { _a4 = max(_a4, _b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream& operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto& vv : V) os << vv << ","; os << "]";
  return os;
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

#define MAX 3002

int n,m;
int t[MAX];
int sum[MAX];
char res[MAX][MAX];
void ustal(int k){
  int sum = 0;
  vector<int> zle(k);
  R(i,k){
    sum += t[i];
    zle[i] = max(0ll, sum - (i + 1) * (k - i - 1));
    debug(i,zle[i]);
  }
  
  for(int i = k-2;i>=0;i--){
    maxi(zle[i], zle[i+1] - 1);
  }
  
  int ak = 0;
  for(int i = 0; i < k;i++){
    if(zle[i] > ak){
      ak++;
      t[i]--;
      res[i][k] = 'W';
      res[k][i] = 'L';
    }
  }
  
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m;
  int sum = 0;
  R(i,n){
    if(i < m){
      cin >> t[i];
      t[i] -= n - 1;
    }else{
      t[i] = min(t[i-1], (i+1) * (n-i-1) - sum);
    }
    sum += t[i];
    if(sum > (i+1) * (n-i-1)){
      cout << "no\n";
      return 0;
    }
  }
  if(sum != 0){
    cout << "no\n";
    return 0;
  }
  R(i,n)cerr << t[i] << " ";
  cerr << "\n";
  cout << "yes\n";
  R(i,n)R(j,n)res[i][j] = i == j ? 'X' : 'D';
  for(int i = n-1;i >= 0;i--)ustal(i);
  R(i,n)cout << res[i] << "\n";
}