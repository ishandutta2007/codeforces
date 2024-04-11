#include <algorithm>
#include <iostream>
#include <random>
#include <cmath>

using namespace std;

constexpr int N = 1000, M = 1e4;

int w[N];
double c[M];

int main() {
  {
    double coef = 16;
    for (int i = 0; i < M; ++i) {
      c[i] = coef / (i * i + coef);
    }
  }
  int n, m;
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  mt19937 rng(12312213);
  auto d = uniform_real_distribution(0., 1.);
  for (int r = 0; r < m; ++r) {
    string s; cin >> s;
    int bst = *min_element(w, w + n);
    double a = 0, b = 0;
    for (int i = 0; i < n; ++i) {
      b += c[w[i] - bst];
      if (s[i] == '1') {
        a += c[w[i] - bst];
      }
    }
    cout << (d(rng) < a / b) << endl;
    char res; cin >> res;
    for (int i = 0; i < n; ++i) {
      w[i] += s[i] != res;
    }
  }
}