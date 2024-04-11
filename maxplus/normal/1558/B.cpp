#include <iostream>
#include <vector>

using namespace std;

constexpr int N = 4e6 + 1;

int a[N]{0, 1};
int d[N];
int p[N];
bool c[N];

int main()
{
    int n, m;
    int64_t s = 0;
    cin >> n >> m;
    for (int i = 2; i <= n; ++i) if (!p[i]) {
      d[i] = i;
      p[i] = 1;
      for (int j = i * 2, cf = 2; j <= n; j += i, cf += 1) {
        if (d[j] || d[cf] != i) {
          c[j] = 1;
        }
        d[j] = i;
        p[j] = d[cf] == i? p[cf] + 1: 1;
      }
    }
    vector<int> divi;
    for (int i = 2; i <= n; ++i) {
      {
        divi.clear();
        divi.push_back(1);
        int j = i;
        while (c[j]) {
          int sz = divi.size(), pos = 0, cd = d[j]? d[j]: j;
          for (int k = max(p[j], 1); k; --k) {
            int csz = divi.size();
            while (pos < csz) {
              divi.push_back(divi[pos++] * cd);
            }
            j /= cd;
          }
        }
        for (unsigned m = 1, k = 0; k <= max(p[j], 1); ++k, m *= d[j]? d[j]: j) {
          for (auto cd: divi) if ((cd *= m) != i) {
            s += a[cd] - a[cd - 1];
          }
        }
      }
      a[i] = (s += a[i - 1]) %= m;
    }
    cout << (a[n] + m) % m;
    return 0;
}