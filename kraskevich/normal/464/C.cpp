#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000 * 1000 * 1000 + 7;

typedef pair<long long, long long> pll;

long long bin_pow(long long n) {
  long long res = 1;
  long long x = 10;
  for (; n > 0; n /= 2) {
    if (n & 1)
      res = res * x % MOD;
    x = x * x % MOD;
  }
  return res;
}

pll func[10];

string parse(string s) {
  string res = "";
  for (int i = 3; i < s.length(); i++)
    res += s[i];
  return res;
}

void upd(int d, string s) {
  long long cur_len = 0;
  long long res = 0;
  int n = s.length();
  for (int i = n - 1; i >= 0; i--) {
    int cur = s[i] - '0';
    long long dl = func[cur].first;
    long long dr = func[cur].second;
    res = (res + dr * bin_pow(cur_len)) % MOD;
    cur_len = (cur_len + dl) % (MOD - 1);
  }
  func[d] = pll(cur_len, res);
}

int main() {
  ios_base::sync_with_stdio(0);
  string s;
  cin >> s;
  int n;
  cin >> n;
  vector<string> q(n);
  for (int i = 0; i < n; i++)
    cin >> q[i];
  for (int i = 0; i < 10; i++)
    func[i] = pll(1, i);
  for (int i = n - 1; i >= 0; i--) {
    int d = q[i][0] - '0';
    string p = parse(q[i]);
    upd(d, p);
  }
  upd(0, s);
  cout << func[0].second << "\n";

  return 0;
}