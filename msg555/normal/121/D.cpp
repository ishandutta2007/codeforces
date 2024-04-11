#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

pair<long long, long long> A[100000];
pair<long long, long long> B[100000];

#define BIBITS 80
#define BISZ ((BIBITS+15)/16)

/* Simple non-negative fixed sized int. */
struct bigint {
  bigint() {
    memset(A, 0, sizeof(A));
  }

  bigint(unsigned long long x) {
    for(int i = 0; i < BISZ; i++) {
      A[i] = x & 0xFFFF;
      x = x >> 16;
    }
  }

  bigint& fix() {
    for(int i = 0; i < BISZ; i++) {
      if(i + 1 < BISZ) A[i + 1] += A[i] >> 16;
      A[i] &= 0xFFFF;
    }
    return *this;
  }

  void fixup(int i) {
    for(; i < BISZ && A[i] < (1 << 16); i++) {
      if(i + 1 < BISZ) A[i + 1] += A[i] >> 16;
      A[i] &= 0xFFFF;
    }
  }

  bigint& operator+=(const bigint& x) {
    for(int i = 0; i < BISZ; i++) A[i] += x.A[i];
    return fix();
  }

  bigint& operator-=(const bigint& x) {
    int c = 0;
    for(int i = 0; i < BISZ; i++) {
      A[i] -= x.A[i] + c;
      c = A[i] < 0 ? 1 : 0;
      if(c) A[i] += 1 << 16;
    }
    return *this;
  }

  bigint& operator*=(const bigint& x) {
    for(int i = BISZ - 1; i >= 0; i--) {
      A[i] = A[i] * x.A[0];
      fixup(i);
      for(int j = i - 1; j >= 0; j--) {
        int k = i - j;
        A[i] += A[j] * x.A[k];
        fixup(i);
      }
    }
    return fix();
  }

  bigint& operator*=(int x) {
    if(x > 1 << 16) return *this *= bigint(x);
    for(int i = 0; i < BISZ; i++) {
      A[i] *= x;
    }
    return fix();
  }

  /* Performs division, returns remainder */
  int operator/=(int x) {
    int c = 0;
    for(int i = BISZ - 1; i >= 0; i--) {
      int v = (c << 16) + A[i];
      c = v % x;
      A[i] = v / x;
    }
    return c;
  }

  bool operator<(const bigint& x) const {
    for(int i = BISZ - 1; i >= 0; i--) {
      if(A[i] != x.A[i]) {
        return A[i] < x.A[i];
      }
    }
    return false;
  }

  bool operator==(const bigint& x) const {
    return !memcmp(A, x.A, sizeof(A));
  }

  string tostr() {
    string ret;
    bigint cpy = *this;
    bigint zero = 0;
    while(!(cpy == zero)) {
      ret += '0' + (cpy /= 10);
    }
    reverse(ret.begin(), ret.end());
    return ret.empty() ? "0" : ret;
  }

  int A[BISZ];
};

int main() {
  vector<long long> v;
  for(int i = 1; i <= 18; i++) {
    for(int j = 0; j < 1 << i; j++) {
      long long x = 0;
      for(int k = 0; k < i; k++) {
        x *= 10;
        x += (j & 1 << k) ? 7 : 4;
      }
      v.push_back(x);
    }
  }
  sort(v.begin(), v.end());

  int N; long long K;
  cin >> N >> K;

  long long mnsp = 0x7FFFFFFFFFFFFFFFLL;
  for(int i = 0; i < N; i++) {
    cin >> A[i].second >> A[i].first; A[i].first++;
    mnsp = min(mnsp, A[i].first - A[i].second);
  }
  sort(A, A + N);
  for(int i = 0; i < N; i++) swap(A[i].first, A[i].second);
  memcpy(B, A, sizeof(B));
  sort(A, A + N);

  bigint hsuminit = 0;
  for(int i = 0; i < N; i++) hsuminit += A[i].first;

  int lo = 0;
  int hi = v.size();
  while(lo < hi) {
    int md = (lo + hi + 1) / 2;

    bool ok = false;

    int posh = 0;
    int posl = 0;
    bigint hsum = hsuminit;
    bigint lsum = 0;
    for(int i = 0; !ok && i + md <= v.size(); i++) {
      long long lk = v[i];
      long long hk = v[i + md - 1];
      if(hk - lk + 1 > mnsp) continue;

      while(posh < N && A[posh].first <= lk) {
        hsum -= A[posh++].first;
      }
      while(posl < N && B[posl].second <= hk) {
        lsum += B[posl++].second - 1;
      }

      bigint t0 = hk;
      t0 *= posl;
      t0 -= lsum;
      
      bigint t1 = lk;
      t1 *= N - posh;
      bigint tmp = hsum; tmp -= t1; t1 = tmp;

      t0 += t1;
      ok = t0 < K + 1;
    }

    if(ok) lo = md;
    else hi = md - 1;
  }

  cout << lo << endl;
}