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
bool isPrime(int x)
{
  if (x == 1)
    return false;
  for (int i = 2; i * i <= x; ++i)
  {
    if (x % i == 0)
      return false;
  }
  return true;
}
void solve()
{
  int n, e;
  cin >> n >> e;
  vector<int> inputs;
  REP(i, n)
  {
    int a;
    cin >> a;
    inputs.push_back(a);
  }
  int ans = 0;
  REP(i, e)
  {
    vector<int> tmp;
    for (int q = i; q < n; q += e)
    {
      tmp.push_back(inputs[q]);
    }
    for (int q = 0; q < tmp.size(); ++q)
    {
      if (!isPrime(tmp[q]))
        continue;
      int left = 1;
      int rights = 1;
      for (int j = q - 1; j >= 0; --j)
      {
        if (tmp[j] != 1)
          break;
        left++;
      }
      for (int j = q + 1; j < tmp.size(); ++j)
      {
        if (tmp[j] != 1)
          break;
        rights++;
      }
      ans += left * rights - 1;
    }
  }
  cout << ans << endl;
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