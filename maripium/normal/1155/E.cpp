#include <bits/stdc++.h>

using namespace std;

const int mod = 1e6 + 3;

int mul(int x,int y) {
  return (long long) x * y % mod;
}

int power(int x,int y) {
  int ans = 1;
  for (; y > 0; y >>= 1) {
    if (y & 1) {
      ans = mul(ans, x);
    }
    x = mul(x, x);
  }
  return ans;
}

int inv(int x) {
  return power(x, mod - 2);
}

void add(int &x,int y) {
  x += y;
  if (x >= mod) x -= mod;
}

void sub(int &x,int y) {
  x -= y;
  if (x < 0) x += mod;
}


int get(int x) {
  cout << "? " << x << endl;
  int ans;
  cin >> ans;
  return ans;
}

void answer(int x) {
  cout << "! " << x << endl;
  exit(0);
}

vector<int> gauss(vector<vector<int>> coef) {
  int n = coef.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      if (coef[j][i]) {
        swap(coef[i], coef[j]);
        break;
      }
    }
    for (int j = i + 1; j < n; ++j) {
      int cf = mul(coef[j][i], inv(coef[i][i]));
      for (int k = i; k < n + 1; ++k) {
        sub(coef[j][k], mul(coef[i][k], cf));
      }
    }
  }
  vector<int> a(n);
  for (int i = n - 1; i >= 0; --i) {
    a[i] = mul(coef[i][n], inv(coef[i][i]));
    for (int j = 0; j < i; ++j) {
      sub(coef[j][n], mul(coef[j][i], a[i]));
    }
  }
  return a;
}

int main() {
  vector<vector<int>> coef(11, vector<int>(12));
  for (int i = 0; i < 11; ++i) {
    int nw = 1;
    for (int j = 0; j < 11; ++j) {
      coef[i][j] = nw;
      nw = mul(nw, i);
    }
    coef[i][11] = get(i);
  }
  vector<int> a = gauss(coef);
  auto eval = [&](int x) {
    int ans = 0;
    int nw = 1;
    for (int i = 0; i < 11; ++i) {
      add(ans, mul(nw, a[i]));
      nw = mul(nw, x);
    }
    return ans;
  };
  for (int i = 0; i < mod; ++i) {
    if (!eval(i)) answer(i);
  }
  answer(-1);
}