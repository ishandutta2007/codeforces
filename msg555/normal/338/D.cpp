#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long itype;
 
pair<itype, itype> gcdext(itype a, itype b) {
  pair<itype, itype> A(1, 0), B(0, 1);
  while(a) {
    itype m = b / a;
    B.first -= m * A.first;
    B.second -= m * A.second;
    b %= a;
    swap(a, b); swap(A, B);
  }
  return B;
}
 
// Calculate x such that x = x1 (mod m1) and x = x2 (mod m2)
itype crt(itype x1, itype m1, itype x2, itype m2) {
  if(m1 < m2) {
    swap(m1, m2);
    swap(x1, x2);
  }

  itype a = gcdext(m1, m2).first;
  itype x = x1 + ((a * (x2 - x1)) % m2) * m1;
  x %= m1 * m2;
  if(x < 0) x += m1 * m2;
  return x;
}

long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}

long long A[10010];

int main() {
  long long N, M; cin >> N >> M;
  int K; cin >> K;

  double flcm = 1;
  long long lcm = 1;
  for(int i = 0; i < K; i++) {
    cin >> A[i];

    long long g = gcd(lcm, A[i]);
    flcm = flcm / g * A[i];
    lcm = lcm / g * A[i];

    if(flcm > 1e13) {
      cout << "NO" << endl;
      return 0;
    }
  }

  if(lcm > N) {
    cout << "NO" << endl;
    return 0;
  }
  cerr << "ROW = " << lcm << endl;

  vector<pair<long long, int> > primes;
  for(long long p = 2; p * p <= lcm; p++) {
    int cnt = 0;
    while(lcm % p == 0) {
      lcm /= p;
      cnt++;
    }
    if(cnt) {
      primes.push_back(make_pair(p, cnt));
    }
  }
  if(lcm != 1) {
    primes.push_back(make_pair(lcm, 1));
  }

  long long r = 0;
  long long m = 1;
  for(int i = 0; i < primes.size(); i++) {
    long long p = primes[i].first;
    for(int j = 0; j < primes[i].second; j++, p *= primes[i].first) {
      int resexp;
      for(resexp = 0; A[resexp] % p; resexp++);

      for(int k = 0; k < K; k++) {
        if((k % p == resexp) != (A[k] % p == 0)) {
          cout << "NO" << endl;
          return 0;
        }
      }

      if(j + 1 == primes[i].second) {
        r = crt(r, m, (p - resexp) % p, p);
        m *= p;
      }
    }
  }

  if(r == 0) r = m;

  cerr << "COL = " << r << endl;
  if(r + K - 1 <= M) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}