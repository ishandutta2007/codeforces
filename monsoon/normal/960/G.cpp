#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef long long ll;

int realmod(int a, int b) {
  assert(b > 0);
  if (a >= 0) return a % b;
  else return (b - (-a) % b) % b;
}

template<int Mod>
struct modint {
  int val;

  modint(int val = 0) : val(realmod(val, Mod)) { }

  modint& operator+=(const modint& other) {
    val += other.val;
    if (val >= Mod) val -= Mod;
    return *this;
  }
  modint& operator-=(const modint& other) {
    val -= other.val;
    if (val < 0) val += Mod;
    return *this;
  }
  modint& operator*=(const modint& other) {
    val = ll(val) * other.val % Mod;
    return *this;
  }
};

template<int Mod>
inline modint<Mod> operator*(modint<Mod> lhs, const modint<Mod>& rhs) {
  lhs *= rhs;
  return lhs;
}

typedef complex<double> cpl;
vector<cpl> W, powers;

void fft(cpl* A, cpl* B, int step, int size) {
  if (size == 1) {
    B[0] = A[0];
  } else {
    fft(A, B, 2*step, size/2);
    fft(A+step, B+step, 2*step, size/2);

    const int S = size*step/2;
    for (int i = 0; i < S; i += step) {
      W[i] = B[2*i] + powers[i] * B[2*i + step];
      W[i + S] = B[2*i] + powers[i + S] * B[2*i + step];
    }

    for (int i = 0; i < 2*S; i += step) {
      B[i] = W[i];
    }
  }
}

template<typename T>
struct polynomial {
  vector<T> coeff;
};

template<int Mod>
polynomial<modint<Mod>> operator*(
    const polynomial<modint<Mod>>& lhs,
    const polynomial<modint<Mod>>& rhs) {
  polynomial<modint<Mod>> ans;
  if (lhs.coeff.empty() || rhs.coeff.empty()) return ans;
  int len = lhs.coeff.size() + rhs.coeff.size() - 1;

  ans.coeff.resize(len);

  if (len < 100) {
    REP(i,(int)lhs.coeff.size()) REP(j,(int)rhs.coeff.size()) {
      ans.coeff[i+j] += lhs.coeff[i] * rhs.coeff[j];
    }
    return ans;
  }

  int n=1; while (n < len) n *= 2;
  int Squ = int(sqrt(Mod)) + 1;

  W = powers = vector<cpl>(n);
  const double mpi = 2*acos(0);
  REP(i,n) { powers[i] = exp((double)2.*mpi*i/n*cpl(0,1)); }
  vector<cpl> cA(n), X(n), cX(n);

  REP(pi,2) REP(pj,2) {

    vector<cpl> A(n), B(n);
    REP(i,(int)lhs.coeff.size()) {
      int v = lhs.coeff[i].val;
      A[i] = pi ? v/Squ : v % Squ;
    }
    REP(i,(int)rhs.coeff.size()) {
      int v = rhs.coeff[i].val;
      B[i] = pj ? v/Squ : v % Squ;
    }

    REP(i,n) { X[i] = cpl(A[i].real(), B[i].real()); }
    fft(&X[0], &cX[0], 1, n);
    REP(i,n) {
      const int j = (n-i) & (n-1);
      cA[i] = (cX[i]*cX[i] - conj(cX[j]*cX[j])) * cpl(0, -.25/n);
    }
    REP(i,n) { powers[i] = conj(powers[i]); }
    fft(&cA[0], &A[0], 1, n);
    REP(i,n) { powers[i] = conj(powers[i]); }

    REP(i,len) {
      int v = ll(A[i].real() + .5) % Mod;
      int mu = pi && pj ? Squ*Squ : pi || pj ? Squ : 1;
      ans.coeff[i].val = (ans.coeff[i].val + ll(v) * mu) % Mod;
    }

  }
  return ans;
}

template<typename T>
vector<T> stirling_cycle(int n) {
  int base = 1;
  while (base < n) base *= 2;
  vector<polynomial<T>> poly(2*base);
  REP(i,base) {
    if (i < n) {
      poly[base+i].coeff = { i, 1 };
    } else {
      poly[base+i].coeff = { 1 };
    }
  }
  for (int i=base-1; i>=1; --i) {
    poly[i] = poly[2*i] * poly[2*i+1];
  }
  return poly[1].coeff;
}

template<typename T>
vector<T> binomial(int n) {
  polynomial<T> a, ans;
  a.coeff = { 1, 1 };
  ans.coeff = { 1 };

  while (n) {
    if (n&1) ans = ans * a;
    a = a * a;
    n /= 2;
  }

  return ans.coeff;
}

int n,a,b;
const int MOD = 998244353;

int main() {
  scanf("%d%d%d",&n,&a,&b);
  modint<MOD> ans = 0;
  if (a >= 1 && b >= 1 && a+b <= n+1) {
    auto s = stirling_cycle<modint<MOD>>(n-1);
    auto t = binomial<modint<MOD>>(a+b-2);
    ans = s[a+b-2] * t[a-1];
  }
  printf("%d\n",ans.val);
}