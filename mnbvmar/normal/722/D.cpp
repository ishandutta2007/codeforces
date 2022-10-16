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

const int MaxN = 50005;

int N;
int inSet[MaxN];
set<int> nums, inNums;
map<int, int> numMap;
vector<int> numInvTab;

vector<vector<int>> adj;
vector<int> needHave;


/*bool checkMost(int bound) {
  vector<int> 
}*/


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> inSet[i];

    int v = inSet[i];
    do {
      nums.insert(v);
      v /= 2;
    } while (v);

    inNums.insert(inSet[i]);
  }

  while (true) {
    int v = *inNums.rbegin();

    int newV = v;
    do {
      newV /= 2;
    } while (inNums.count(newV));
    if (newV == 0) { break; }

    inNums.erase(v);
    inNums.insert(newV);
  }

  for (int v : inNums) {
    cout << v << " ";
  }
  cout << "\n";

  /*int ptr = 0;
  for (int v : nums) {
    numMap[v] = ptr++;
    numInvTab.push_back(v);
    needHave.push_back(0);
  }

  adj.resize(SZ(nums));

  for (int v : nums) {
    int vid = numMap[v];
    for (int t = 0; t < 2; t++) {
      if (nums.count(2 * v + t)) {
        int tid = numMap[2 * v + t];

        adj[vid].PB(tid);
      }
    }
  }

  for (int v : inNums) {
    needHave[numMap[v]] = 1;
  }


  int left = -1, right = SZ(numInvTab);
  while (left < right - 1) {
    int mid = (left + right) / 2;
    if (checkMost(numInvTab[mid])) {
      right = mid;
    } else {
      left = mid;
    }
  }

  checkMost(numInvTab[right]);*/

}