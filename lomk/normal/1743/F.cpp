/*input
4
3 5
4 8
2 2
1 9


*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x, y) ((x >> y) & 1)
#define loop(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define rloop(i, l, r) for (int i = (int)l; i >= (int)r; --i)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() { cout << endl; }
template <typename T, typename... Ts>
void print(const T &value, const Ts &...values) {
  cout << value << ' ', print(values...);
}
#endif
const int N = 3e5+5;

const int INF = numeric_limits<int>::max() / 2;
const int mod = 998244353;

typedef array<array<int,2>,2> Matrix;

Matrix operator*(const Matrix &a, const Matrix &b) {
  Matrix c = {{{0,0},{0,0}}};
  loop(i, 0, 1) {
    loop(k, 0, 1) {
      loop(j, 0, 1) {
        c[i][j] = (c[i][j] + 1LL * a[i][k] * b[k][j]) % mod;
      }
    }
  }
  return c;
}

ostream &operator<<(ostream &os, const Matrix &x) {
  for (auto &it : x) {
    for (auto &it2 : it)
      os << it2 << sp;
    os << endl;
  }
  return os;
}

const Matrix mat0 = {{{3, 0}, {1, 2}}};
const Matrix mat1 = {{{1, 2}, {1, 2}}};
const Matrix matI = {{{1,0},{0,1}}};

class ITrangeSum {
private:
#define mid ((l+r)/2)
  int n;
  Matrix f[4 * N];
  void update(int k, int l, int r, int pos, const Matrix &val) {
    if (r < pos || pos < l) return;
    if (l==pos&&pos==r) {
      f[k] = val;
      return;
    }
    update(k * 2, l, mid, pos, val); update(k * 2 + 1, mid + 1, r, pos, val);
    f[k] = f[k*2] * f[k*2+1];
  }
  Matrix get(int k, int l, int r, int L, int R) {
    if (r < L || R < l) return matI;
    if (L <= l && r <= R) return f[k];
    return (get(k * 2, l, mid, L, R) * get(k * 2 + 1, mid + 1, r, L, R));
  }
  void init(int k, int l, int r) {
   if (l == r){
      f[k] = mat0; 
      return;
   }
    init(k * 2, l, mid); init(k * 2 + 1, mid + 1, r);
    f[k] = f[k*2] * f[k*2+1];
  }
public:
  void init(int _n) {n = _n; init(1, 0, n - 1);}
  Matrix get(int l, int r) {return get(1, 0, n - 1, l, r);};
  void update(int pos, const Matrix &val) {update(1, 0, n - 1, pos, val);};
#undef mid
} IT;

struct Event {
  int type;
  int pos;
  int val;
};

int n, minL = INF, maxR = -INF;
vector<Event> e;

void processEvent(Event p) {
  if (p.type == 1) {
    IT.update(p.pos, mat1);
  } else {
    IT.update(p.pos, mat0);
  }
}

int calResult() {
  Matrix root;
  if (IT.get(0, 0) == mat0) {
    root = Matrix({{{1, 0},{0,0}}});
  } else {
    root = Matrix({{{0, 1},{0,0}}});
  }
  auto mat = root * IT.get(1, n - 1);
  return mat[0][1];
}

int solve() {
  int ret = 0;
  int iter = 0;

  auto addEventsWithI = [&](int p) {
    while (iter < e.size() && e[iter].val == p) {
      processEvent(e[iter]);
      iter++;
    }
    ret = (ret+calResult())%mod;
  };
  loop(i, minL, maxR) { addEventsWithI(i); }
  return ret;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  loop(i, 0, n - 1) {
    int l, r;
    cin >> l >> r;
    e.push_back({1, i, l});
    e.push_back({-1, i, r+1});
    minL = min(minL, l);
    maxR = max(maxR, r);
  }
  sort(e.begin(), e.end(), [&](Event &X, Event &Y) { return X.val < Y.val; });
  IT.init(n);
  cout << solve() << endl;
}