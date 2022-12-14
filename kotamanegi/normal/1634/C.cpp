#include "bits/stdc++.h"
using namespace std;

typedef string::const_iterator State;
#define eps 1e-8L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
#define REP(a, b) for (long long(a) = 0; (a) < (b); ++(a))
#define ALL(x) (x).begin(), (x).end()

#define int long long

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<vector<int>> inputs(n);
  REP(i, k)
  {
    REP(q, n)
    {
      inputs[q].push_back(i * n + q + 1);
    }
  }

  REP(i, n)
  {
    REP(q, k)
    {
      int now = 0;
      for (int j = q; j < k; ++j)
      {
        now += inputs[i][j];
        if (now % (j - q + 1))
        {
          cout << "NO" << endl;
          return;
        }
      }
    }
  }
  cout << "YES" << endl;
  REP(i, n)
  {
    REP(q, k)
    {
      if (q)
        cout << " ";
      cout << inputs[i][q];
    }
    cout << endl;
  }
}
#undef int

// generated by oj-template v4.7.2
// (https://github.com/online-judge-tools/template-generator)
int main()
{
  // Fasterize input/output script
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(100);
  // scanf/printf user should delete this fasterize input/output script

  int t = 1;
  cin >> t; // comment out if solving multi testcase
  for (int testCase = 1; testCase <= t; ++testCase)
  {
    solve();
  }
  return 0;
}