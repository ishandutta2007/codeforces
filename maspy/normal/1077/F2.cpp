#line 1 "main.cpp"
#include <bits/stdc++.h>
#line 3 "/home/maspy/library/my_template.hpp"

using namespace std;

using ll = long long;
using ld = long double;
#define int ll
using pi = pair<int, int>;
using vi = vector<int>;

#define FOR(i, n) for (int i = 0; (i) < (int)(n); ++(i))
#define FOR3(i, m, n) for (int i = (m); (i) < (int)(n); ++(i))
#define FOR_R(i, n) for (int i = (int)(n)-1; (i) >= 0; --(i))
#define FOR3_R(i, m, n) for (int i = (int)(n)-1; (i) >= (int)(m); --(i))
#define all(x) x.begin(), x.end()

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

template <typename T>
struct Grid {
  ll H, W;
  vector<vector<T>> data;
  pi shape;
  Grid(ll H, ll W) : H(H), W(W), data(H, vector<T>(W)), shape({H,W}) {}
  void fill(T x) {
    FOR(i, H) { FOR(j, W) data[i][j] = x; }
  }
  vector<T>& operator[](ll i) { return data[i]; }
  bool operator==(Grid<T>& other){
    if(H != other.H || W != other.W) return false;
    FOR(i, H) FOR(j, W){
      if(data[i][j] != other[i][j]) return false;
    }
    return true;
  }
  Grid rot(){
    auto B = Grid(W,H);
    FOR(i, W){
      FOR(j, H){
        B[i][j] = (*this)[j][W-1-i];
      }
    }
    return B;
  }
};


// [
ll in() {
  ll i;
  cin >> i;
  return i;
}

pi in2(int off = 0) {
  ll a, b;
  cin >> a >> b;
  return {a + off, b + off};
}

tuple<ll, ll, ll> in3() {
  ll a, b, c;
  cin >> a >> b >> c;
  return {a, b, c};
}

tuple<ll, ll, ll, ll> in4() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  return {a, b, c, d};
}

vi vin(int n, int off = 0) {
  vi A(n);
  for (auto&& x : A) {
    cin >> x;
    x += off;
  }
  return A;
}

string sin() {
  string s;
  cin >> s;
  return s;
}

Grid<ll> gridin(int H, int W){
  Grid<ll> A(H, W);
  FOR(i, H){
    FOR(j, W){
      A[i][j] = in();
    }
  }
  return A;
}

Grid<char> cgridin(int H, int W){
  Grid<char> A(H, W);
  FOR(i, H){
    string S = sin();
    FOR(j, W){
      A[i][j] = S[j];
    }
  }
  return A;
}

// ]

// [
template <typename T, typename U>
ostream& operator<<(ostream& os, pair<T, U>& A) {
  os << A.fi << " " << A.se;
  return os;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& A) {
  for (size_t i = 0; i < A.size(); i++) {
    if(i) os << " ";
    os << A[i];
  }
  return os;
}


void print() {
  cout << "\n";
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(Tail)) cout << " ";
  print(forward<Tail>(tail)...);
}

void YES() {print("YES");}
void NO() {print("NO");}
void Yes() {print("Yes");}
void No() {print("No");}
// ]

template <typename T>
ll sum(T A) {
  return accumulate(all(A), 0);
}

template <typename T>
vector<T> cumsum(vector<T> A) {
  ll N = A.size();
  vector<T> B(N + 1);
  B[0] = T(0);
  FOR(i, N) { B[i + 1] = B[i] + A[i]; }
  return B;
}

vi bin_count(vi& A, ll size) {
  vi C(size);
  for (auto&& x : A) {
    ++C[x];
  }
  return C;
}



template <typename T>
ostream& operator<<(ostream& os, Grid<T>& A) {
  FOR(i, A.H){
    if(i) os << "\n";
    os << A[i];
  }
  return os;
}

template <class T, class U>
bool chmax(T& a, const U& b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T, class U>
bool chmin(T& a, const U& b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
#line 3 "main.cpp"

template <class T, class Op>
class Swag {
 private:
  class node {
   public:
    T val, sum;
    node(const T& val, const T& sum) : val(val), sum(sum) {}
  };

  Op op;
  std::stack<node> front_stack, back_stack;

 public:
  Swag(const Op& op = Op()) : op(op), front_stack(), back_stack() {}

  bool empty() const { return front_stack.empty() && back_stack.empty(); }

  std::size_t size() const { return front_stack.size() + back_stack.size(); }

  T fold_all() const {
    assert(!empty());
    if (front_stack.empty()) {
      return back_stack.top().sum;
    } else if (back_stack.empty()) {
      return front_stack.top().sum;
    } else {
      return op(front_stack.top().sum, back_stack.top().sum);
    }
  }

  void push(const T& x) {
    if (back_stack.empty()) {
      back_stack.emplace(x, x);
    } else {
      T s{op(back_stack.top().sum, x)};
      back_stack.emplace(x, s);
    }
  }

  void pop() {
    assert(!empty());
    if (front_stack.empty()) {
      front_stack.emplace(back_stack.top().val, back_stack.top().val);
      back_stack.pop();
      while (!back_stack.empty()) {
        T s{op(back_stack.top().val, front_stack.top().sum)};
        front_stack.emplace(back_stack.top().val, s);
        back_stack.pop();
      }
    }
    front_stack.pop();
  }
};

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  const ll INF = 1LL << 60;

  auto [N, K, X] = in3();
  auto A = vin(N);

  // x  -> 
  vi dp(N + 1, -INF);
  dp[0] = 0;
  FOR(_, X) {
    auto f = [](ll x, ll y) -> ll { return max(x, y); };
    Swag<ll, decltype(f)> swag(f);

    vi newdp(N + 1, -INF);
    FOR3(i, 1, N + 1) {
      swag.push(dp[i - 1]);
      if (swag.size() > K) {
        swag.pop();
      }
      newdp[i] = swag.fold_all() + A[i - 1];
    }
    swap(dp, newdp);
  }
  reverse(all(dp));
  dp.resize(K);
  auto ans = *max_element(all(dp));
  if (ans < 0) ans = -1;
  print(ans);

  return 0;
}