#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define RE(i,n) FOR(i,1,n)
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

template<class C> void mini(C& a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C& a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h) {cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while (*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1, a...);
}

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
  os << "["; for (auto v : V) os << v << ","; os << ']'; return os;
}

template<class L, class R> ostream &operator<<(ostream &os, pair<L, R> P ){
  return os << "(" << P.st << ", " << P.nd << ")";
}


#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int MaxN = 105;

int N;
int rating[MaxN];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> rating[i];
  }
  
  if (N == 2) {
    if (rating[0] == rating[1]) {
      cout << rating[0] << "\n0\n";
      return 0;
    } else {
      int M = max(rating[0], rating[1]);
      cout << "0\n" << M << "\n";
      for (int i = 0; i < M; i++) { cout << "11\n"; }
      return 0;
    }
  }
  
  int maxVal = 0;
  int R = 1e9;
  int sumRatings = 0;
  for (int i = 0; i < N; i++) {
    maxi(maxVal, rating[i]);
    mini(R, rating[i]);
    sumRatings += rating[i];
  }
  
  vector<int> ratingsSorted(rating, rating + N);
  sort(ALL(ratingsSorted), greater<int>());
  
  
  while (R > 0) {
    int diff = sumRatings - N * R;
    int rMaxVal = maxVal;
    
    if (diff % 2 == 1) {
      diff -= 3;
      rMaxVal--;
      if (N >= 4) { maxi(rMaxVal, ratingsSorted[3]); }
    }
    
    debug(rMaxVal, R, diff);
    
    if ((rMaxVal - R) * 2 <= diff) { break; }
    R--;
  }
  
  if (R == 0) {
    int maxRating = ratingsSorted[0];
    cout << "0\n" << maxRating * N << "\n";
    for (int i = 0; i < maxRating; i++) {
      for (int j = 0; j < N; j++) {
        string s(N, '0');
        s[j] = '1';
        s[(j + 1) % N] = '1';
        cout << s << "\n";
      }
    }
    return 0;
  }
  
  
  vector<string> result;
  priority_queue<pair<int, int>> curRatings;
  
  for (int i = 0; i < N; i++) {
    curRatings.push({rating[i], i});
  }
  
  auto makeTeam = [&](int size) {
    vector<int> who;
    for (int j = 0; j < size; j++) {
      who.push_back(curRatings.top().second);
      curRatings.pop();
    }
    
    string s(N, '0');
    
    for (int v : who) {
      s[v] = '1';
      rating[v]--;
      curRatings.push({rating[v], v});
    }
    result.push_back(s);
  };
  
  int diff = sumRatings - N * R;
  if (diff % 2 == 1) {
    makeTeam(3);
    diff -= 3;
  }
  while (diff > 0) {
    makeTeam(2);
    diff -= 2;
  }
  
  cout << R << "\n" << SZ(result) << "\n";
  for (auto s : result) { cout << s << "\n"; }
}