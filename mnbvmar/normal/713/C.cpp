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

template<class TH> void _dbg(const char *sdbg, TH h){ cerr << sdbg << '=' << h << endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(CC) {cerr<<#CC<<"=";for(auto&cc:CC)cerr<<cc<<",";cerr<<endl;}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(CC) {}
#define cerr if(0)cout
#endif

const int MaxN = 3005;

int N;
int tab[MaxN];
vector<int> nums;
LL dp[MaxN][MaxN];



int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> tab[i];
    tab[i] -= i;
    nums.push_back(tab[i]);
  }

  sort(nums.begin(), nums.end());
  nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
  int S = SZ(nums);

  for (int pos = 1; pos <= N; pos++) {
    int value = tab[pos - 1];

    for (int h = 0; h < S; h++) {
      dp[pos][h] = dp[pos - 1][h] + abs(value - nums[h]);
      if (h) { dp[pos][h] = min(dp[pos][h], dp[pos][h - 1]); }
    }
  }

  cout << dp[N][S - 1] << "\n";
}