#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 101;
const int kMatrixSize = 16;
const int kMod = 1000000007;

class Matrix {
 public:
  Matrix() = delete;

  Matrix(int rows, int cols) {
    data_.resize(rows);
    for (int i = 0; i < rows; ++i) {
      data_[i].assign(cols, 0);
    }
  }

  int get_value(int i, int j) { return data_[i][j]; }
  void set_value(int i, int j, int value) { data_[i][j] = value; }
  int rows() const { return data_.size(); }
  int cols() const { return data_[0].size(); }

  Matrix operator*(const Matrix& other) {
    assert(cols() == other.rows());

    Matrix result(rows(), other.cols());
    for (int i = 0; i < rows(); ++i) {
      for (int j = 0; j < other.cols(); ++j) {
        int& running_value = result.data_[i][j];
        running_value = 0;
        for (int k = 0; k < cols(); ++k) {
          running_value = (static_cast<long long>(data_[i][k]) * other.data_[k][j] + running_value) % kMod;
        }
      }
    }

    return result;
  }

 private:
  vector<vector<int>> data_;
};

Matrix ConstructMatrixForLine(int y_limit) {
  assert(y_limit < kMatrixSize);

  Matrix result(kMatrixSize, kMatrixSize);
  for (int i = 0; i <= y_limit; ++i) {
    if (i) {
      result.set_value(i, i - 1, 1);
    }
    result.set_value(i, i, 1);
    if (i + 1 < kMatrixSize) {
      result.set_value(i, i + 1, 1);
    }
  }

  return result;
}

Matrix BinaryPower(Matrix a, long long power) {
  assert(power > 0);
  assert(a.cols() == a.rows());

  Matrix result = a;
  --power;
  while (power) {
    if (power & 1ll) {
      result = result * a;
    }

    a = a * a;
    power >>= 1;
  }

  return result;
}

int n;
long long k;
long long a[kMaxN];
long long b[kMaxN];
long long c[kMaxN];

void Solve() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i] >> c[i];
  }

  Matrix result(kMatrixSize, 1);
  result.set_value(0, 0, 1);

  for (int i = 0; i + 1 < n; ++i) {
    if (a[i] + 1 < b[i]) {
      result = BinaryPower(ConstructMatrixForLine(c[i]), b[i] - a[i] - 1) * result;
    }

    result = ConstructMatrixForLine(min(c[i], c[i + 1])) * result;
  }

  if (a[n - 1] + 1 <= k) {
    result = BinaryPower(ConstructMatrixForLine(c[n - 1]), k - a[n - 1]) * result;
  }

  cout << result.get_value(0, 0) << "\n";
}

int main() {
  Solve();

  return 0;
}