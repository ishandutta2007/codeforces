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

  auto T = in();
  FOR(_, T) {
    auto S = sin();
    ll N = S.size();
    auto A = s_to_vi(S, 'a');
    auto CNT = bin_count(A, 26);
    const ll INF = 1LL << 60;
    FORIN(x, CNT) if (x == 0) x = INF;
    ll best_ch = min_element(all(CNT)) - CNT.begin();

    if (CNT[best_ch] == N) {
      print(S);
      continue;
    }
    if (CNT[best_ch] == 1) {
      string ANS;
      ANS += 'a' + best_ch;
      --CNT[best_ch];
      FOR(c, 26) {
        if (CNT[c] == INF) continue;
        FOR(_, CNT[c]) ANS += 'a' + c;
      }
      print(ANS);
      continue;
    }
    /*
     2 
    12
    */
    ll a = -1;
    FOR(x, 26) {
      if (CNT[x] != INF) {
        a = x;
        break;
      }
    }
    if (N - CNT[a] >= CNT[a] - 2) {
      vi me;
      vi other;
      FORIN(x, A) {
        if (x == a)
          me.eb(x);
        else
          other.eb(x);
      }
      sort(all(other));
      reverse(all(other));
      vi ANS;
      ANS.eb(a);
      ANS.eb(a);
      me.pop_back();
      me.pop_back();
      FOR(_, N - 2) {
        if (me.empty()) {
          ANS.eb(other.back());
          other.pop_back();
          continue;
        }
        if (ANS.back() != a) {
          ANS.eb(me.back());
          me.pop_back();
        } else {
          ANS.eb(other.back());
          other.pop_back();
        }
      }
      string SS;
      FORIN(x, ANS) SS += 'a' + x;
      print(SS);
      continue;
    }
    /* aa */
    vi words;
    FOR(c, 26) {
      if (CNT[c] != INF) words.eb(c);
    }
    if (words.size() == 2) {
      // abbbbbbaaaa
      char b = words[1];
      string ANS;
      ANS += a + 'a';
      FOR(_, CNT[b]) ANS += b + 'a';
      FOR(_, CNT[a] - 1) ANS += a + 'a';
      print(ANS);
      continue;
    }
    string ANS;
    ll b = words[1], c = words[2];
    ANS += a + 'a';
    --CNT[a];
    ANS += b + 'a';
    --CNT[b];
    FOR(_, CNT[a]) ANS += a + 'a';
    CNT[a] = 0;
    ANS += c + 'a';
    --CNT[c];
    FOR(s, 26) {
      if (CNT[s] != INF) {
        FOR(_, CNT[s]) { ANS += s + 'a'; }
      }
    }
    print(ANS);
  }

  return 0;
}