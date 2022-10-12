#define DEBUG 0

#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
using namespace std;

#define LL long long
#define LD long double
#define PR pair<int,int>

#define Fox(i,n) for (i=0; i<n; i++)
#define Fox1(i,n) for (i=1; i<=n; i++)
#define FoxI(i,a,b) for (i=a; i<=b; i++)
#define FoxR(i,n) for (i=(n)-1; i>=0; i--)
#define FoxR1(i,n) for (i=n; i>0; i--)
#define FoxRI(i,a,b) for (i=b; i>=a; i--)
#define Foxen(i,s) for (auto i:s)
#define Min(a,b) a=min(a,b)
#define Max(a,b) a=max(a,b)
#define Sz(s) int((s).size())
#define All(s) (s).begin(),(s).end()
#define Fill(s,v) memset(s,v,sizeof(s))
#define pb push_back
#define mp make_pair
#define x first
#define y second

template<typename T> T Abs(T x) { return(x < 0 ? -x : x); }
template<typename T> T Sqr(T x) { return(x * x); }
string plural(string s) { return(Sz(s) && s[Sz(s) - 1] == 'x' ? s + "en" : s + "s"); }

const int INF = (int)1e9;
const LD EPS = 1e-12;
const LD PI = acos(-1.0);

//#if DEBUG
#define GETCHAR getchar
/*#else
#define GETCHAR getchar_unlocked
#endif*/

bool Read(int& x) {
  char c, r = 0, n = 0;
  x = 0;
  for (;;) {
    c = GETCHAR();
    if ((c < 0) && (!r))
      return(0);
    if ((c == '-') && (!r))
      n = 1;
    else if ((c >= '0') && (c <= '9'))
      x = x * 10 + c - '0', r = 1;
    else if (r)
      break;
  }
  if (n)
    x = -x;
  return(1);
}

bool ReadLL(LL& x) {
  char c, r = 0, n = 0;
  x = 0;
  for (;;) {
    c = GETCHAR();
    if ((c < 0) && (!r))
      return(0);
    if ((c == '-') && (!r))
      n = 1;
    else if ((c >= '0') && (c <= '9'))
      x = x * 10 + c - '0', r = 1;
    else if (r)
      break;
  }
  if (n)
    x = -x;
  return(1);
}

#define MOD 1000000007
#define LIM 1000005

int N, M;
LL K;
int A[LIM], P[LIM];
vector<LL> V;

typedef vector<LL> VI;
typedef pair<LL, LL> PII;

// return a % b (positive value)
LL mod(LL a, LL b) {
  return ((a % b) + b) % b;
}

// computes gcd(a,b)
LL gcd(LL a, LL b) {
  while (b) { LL t = a % b; a = b; b = t; }
  return a;
}

// computes lcm(a,b)
LL lcm(LL a, LL b) {
  return a / gcd(a, b) * b;
}

// (a^b) mod m via successive squaring
LL powermod(LL a, LL b, LL m)
{
  LL ret = 1;
  while (b)
  {
    if (b & 1) ret = mod(ret * a, m);
    a = mod(a * a, m);
    b >>= 1;
  }
  return ret;
}

// returns g = gcd(a, b); finds x, y such that d = ax + by
LL extended_euclid(LL a, LL b, LL& x, LL& y) {
  LL xx = y = 0;
  LL yy = x = 1;
  while (b) {
    LL q = a / b;
    LL t = b; b = a % b; a = t;
    t = xx; xx = x - q * xx; x = t;
    t = yy; yy = y - q * yy; y = t;
  }
  return a;
}

// finds all solutions to ax = b (mod n)
VI modular_linear_equation_solver(LL a, LL b, LL n) {
  LL x, y;
  VI ret;
  LL g = extended_euclid(a, n, x, y);
  if (!(b % g)) {
    x = mod(x * (b / g), n);
    for (LL i = 0; i < g; i++)
      ret.push_back(mod(x + i * (n / g), n));
  }
  return ret;
}

// computes b such that ab = 1 (mod n), returns -1 on failure
LL mod_inverse(LL a, LL n) {
  LL x, y;
  LL g = extended_euclid(a, n, x, y);
  if (g > 1) return -1;
  return mod(x, n);
}

// Chinese remainder theorem (special case): find z such that
// z % m1 = r1, z % m2 = r2.  Here, z is unique modulo M = lcm(m1, m2).
// Return (z, M).  On failure, M = -1.
PII chinese_remainder_theorem(LL m1, LL r1, LL m2, LL r2) {
  LL s, t;
  LL g = extended_euclid(m1, m2, s, t);
  if (r1 % g != r2 % g) return make_pair(0, -1);
  return make_pair(mod(s * r2 * m1 + t * r1 * m2, m1 * m2) / g, m1 * m2 / g);
}

// Chinese remainder theorem: find z such that
// z % m[i] = r[i] for all i.  Note that the solution is
// unique modulo M = lcm_i (m[i]).  Return (z, M). On 
// failure, M = -1. Note that we do not require the a[i]'s
// to be relatively prime.
PII chinese_remainder_theorem(const VI& m, const VI& r) {
  PII ret = make_pair(r[0], m[0]);
  for (LL i = 1; i < m.size(); i++) {
    ret = chinese_remainder_theorem(ret.second, ret.first, m[i], r[i]);
    if (ret.second == -1) break;
  }
  return ret;
}

int GCD(int a, int b)
{
  return(b ? GCD(b, a % b) : a);
}

LL LCM(LL a, LL b)
{
  return(a / GCD(a, b) * b);
}

int main() {
  if (DEBUG)
    freopen("in.txt", "r", stdin);
  int i, j, k, a, b, c, x, y, z;
  Read(N), Read(M), ReadLL(K), K--;
  Fox(i, N)
    Read(A[i]);
  Fill(P, -1);
  Fox(i, M)
    Read(j), P[j] = i;
  LL C = LCM(N, M);
  Fox(i, N)
  {
    int p = P[A[i]];
    if (p < 0)
      continue;
    // i, i+N, i+2N, etc.
    // p, p+M, p+2M, etc.
    // z%N = i, z%M = p
    /*Fox(j, C / N)
      if ((i + (LL)N * j) % M == p)
        V.pb(i + (LL)N * j);*/
        //z% m[i] = r[i] for all i
    VI m(2), r(2);
    m[0] = N, m[1] = M;
    r[0] = i, r[1] = p;
    PII ret = chinese_remainder_theorem(m, r);
    if (ret.y >= 0)
      V.pb(ret.x);
  }
  sort(All(V));
  LL bad = C - Sz(V);
  LL ans = C * (K / bad);
  K %= bad;
  K++;
  Fox(i, Sz(V))
  {
    LL bet = V[i] - (i ? V[i - 1] + 1 : 0);
    if (K <= bet)
    {
      ans += K;
      K = 0;
      break;
    }
    ans += bet + 1;
    K -= bet;
  }
  ans += K;
  cout << ans << endl;
  return(0);
}