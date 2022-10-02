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
#define FORIN(x, A) for (auto&& x : A)
#define all(x) x.begin(), x.end()

#define elif else if

#define popcnt __builtin_popcount

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define VEC vector

template <typename T>
struct Matrix {
  ll H, W;
  vector<vector<T>> data;
  pi shape;
  Matrix(ll H, ll W) : H(H), W(W), data(H, vector<T>(W)), shape({H,W}) {}
  void fill(T x) {
    FOR(i, H) { FOR(j, W) data[i][j] = x; }
  }
  vector<T>& operator[](ll i) { return data[i]; }
  bool operator==(Matrix<T>& other){
    if(H != other.H || W != other.W) return false;
    FOR(i, H) FOR(j, W){
      if(data[i][j] != other[i][j]) return false;
    }
    return true;
  }
  Matrix rot(){
    auto B = Matrix(W,H);
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

pi in2() {
  ll a, b;
  cin >> a >> b;
  return {a, b};
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

vi vin(int n) {
  vi A(n);
  for (auto&& x : A) {
    cin >> x;
  }
  return A;
}

string sin() {
  string s;
  cin >> s;
  return s;
}

vi s_to_vi(string S, char first_char='a'){
  vi A(S.size());
  FOR(i, S.size()){
    A[i] = S[i] - first_char;
  }
  return A;
}

Matrix<ll> matrixin(int H, int W){
  Matrix<ll> A(H, W);
  FOR(i, H){
    FOR(j, W){
      A[i][j] = in();
    }
  }
  return A;
}

Matrix<char> cmatrixin(int H, int W){
  Matrix<char> A(H, W);
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

template <typename T>
string join(vector<T>& v){
  ostringstream os;
  for(auto&& x : v){
    os << x;
  }
  return os.str();
}

void YES() {print("YES");}
void NO() {print("NO");}
void Yes() {print("Yes");}
void No() {print("No");}
// ]

template <typename T>
ll sum(T A) {
  return accumulate(all(A), 0LL);
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
vi argsort(vector<T>& A){
  vi ids(A.size());
  iota(all(ids), 0);
  sort(all(ids), [&](ll i, ll j){return mp(A[i],i)<=mp(A[j],j);});
  return ids;
}

template <typename T>
int argmax(vector<T>& A){
  return max_element(all(A)) - A.begin();
}


template <typename T>
ostream& operator<<(ostream& os, Matrix<T>& A) {
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

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  auto [N, Q, S, D] = in4();
  --S;
  auto A = vin(N);
  set<ll> se_A;
  FORIN(x, A) { se_A.insert(x); }

  set<ll> se_B;
  /*
   A
   B
  b in B  A 
   a  b   a  b 
  */
  const ll INF = 1LL << 60;
  se_A.insert(-INF);
  se_A.insert(INF);
  se_B.insert(-INF);
  se_B.insert(INF);

  vi ANS(1 << 20, INF);

  auto find_lr = [&](set<ll>& se, ll x) -> pi {
    auto it = se.lower_bound(x);
    ll r = *it;
    ll l = *(--it);
    return mp(l, r);
  };

  // (k, )  priority queue
  priority_queue<pi, vector<pi>, greater<pi>> que;
  que.push(mp(0, A[S]));

  ll find = 0;
  ll now_k = 0;
  while (find < N) {
    ll k, v;
    tie(k, v) = que.top();
    // print(k, v);
    que.pop();
    chmax(now_k, k);
    if (ANS[v] <= now_k) continue;
    ANS[v] = now_k;
    ++find;
    se_A.erase(v);
    // print(v, "is erased from A");

    // v 
    auto [l, r] = find_lr(se_B, v);
    if (l != -INF) {
      auto [ll, lr] = find_lr(se_A, l);
      if (lr != INF) que.push(mp(lr - l, lr));
    }
    if (r != INF) {
      auto [rl, rr] = find_lr(se_A, r);
      if (rl != -INF) que.push(mp(r - rl, rl));
    }

    // v - d  v + d 
    ll to;
    to = v - D;
    // print(to, "is inserted to B");
    if (!se_B.count(to)) {
      se_B.insert(to);
      tie(l, r) = find_lr(se_A, to);
      if (l != -INF) que.push(mp(to - l, l));
      if (r != INF) que.push(mp(r - to, r));
    }

    to = v + D;
    // print(to, "is inserted to B");
    if (!se_B.count(to)) {
      se_B.insert(to);
      tie(l, r) = find_lr(se_A, to);
      if (l != -INF) que.push(mp(to - l, l));
      if (r != INF) que.push(mp(r - to, r));
    }
  }

  // 
  FOR(_, Q) {
    auto [i, k] = in2();
    --i;
    if (ANS[A[i]] <= k)
      Yes();
    else
      No();
  }

  return 0;
}