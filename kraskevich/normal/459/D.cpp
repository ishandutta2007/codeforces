#include <bits/stdc++.h>

using namespace std;

const int N = 1000 * 1000 + 10;

long long f[N];

void upd(int at, int by) {
  for (; at < N; at = (at | (at + 1)))
    f[at] += by;
}

long long get(int at) {
  long long res = 0;
  for (; at >= 0; at = (at & (at + 1)) - 1)
    res += f[at];
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  map<int, int> cnt;
  vector<int> fi(n);
  vector<int> fj(n);
  for (int i = 0; i < n; i++)
    fi[i] = cnt[a[i]]++;
  cnt.clear();
  for (int i = n - 1; i >= 0; i--)
    fj[i] = cnt[a[i]]++;
  long long ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    ans += get(fi[i] - 1);
    upd(fj[i], 1);
  }
  cout << ans;

  return 0;
}