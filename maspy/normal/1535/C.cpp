#include <bits/stdc++.h>
using namespace std;

using ll = long long;
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

template <typename T>
void print(T x) {
  cout << x << "\n";
}

template <typename A, typename B>
void print(A x, B y, string sep=" ") {
  cout << x << sep << y << "\n";
}

template <typename T>
void printseq(T begin, T end, string sep=" ") {
  for(auto it=begin;it!=end;it++){cout << (*it) << sep;}
  cout << endl;
}

template <typename T>
vector<T> cumsum(vector<T> A){
  ll N = A.size();
  vector<T> B(N+1);
  B[0] = T(0);
  FOR(i, N){
    B[i+1] = B[i] + A[i];
  }
  return B;
}

ll read() {
  ll i;
  cin >> i;
  return i;
}

vi readvi(int n, int off = 0) {
  vi v(n);
  for(auto&& x : v){
    x = read() + off;
  }
  return v;
}

pi readpi(int off = 0) {
  int a, b;
  cin >> a >> b;
  return pi(a + off, b + off);
}

string readstr() {
  string s;
  cin >> s;
  return s;
}

ll solve(string S){
  ll N = S.size();
  vi A_00(N), A_01(N), A_10(N), A_11(N);
  FOR(i, N){
    A_00[i] = A_01[i] = A_10[i] = A_11[i] = 0;
    if(i%2==0 && S[i] == '0') A_00[i] = 1;
    if(i%2==0 && S[i] == '1') A_01[i] = 1;
    if(i%2==1 && S[i] == '0') A_10[i] = 1;
    if(i%2==1 && S[i] == '1') A_11[i] = 1;
  }
  A_00 = cumsum(A_00);
  A_01 = cumsum(A_01);
  A_10 = cumsum(A_10);
  A_11 = cumsum(A_11);

  auto check = [&](ll L, ll R){
    if(A_00[R] - A_00[L] > 0 && A_01[R] - A_01[L] > 0) return false;
    if(A_10[R] - A_10[L] > 0 && A_11[R] - A_11[L] > 0) return false;
    if(A_00[R] - A_00[L] > 0 && A_10[R] - A_10[L] > 0) return false;
    if(A_01[R] - A_01[L] > 0 && A_11[R] - A_11[L] > 0) return false;
    return true;
  };

  ll ans = 0;
  ll R = 0;
  FOR(L, N){
    R = max(L+1,R);
    while(R < N and check(L, R+1)) ++R;
    ans += R - L;
  }
  return ans;
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll T = read();
  FOR(_,T){
    string S = readstr();
    print(solve(S));
  }
  return 0;
}