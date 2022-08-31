#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int seed;

int rnd() {
  int ret = seed;
  seed = (1ll * seed * 7 + 13) % 1000000007;
  return ret;
}

#define MAXN 100010

long long A[MAXN];
int S[MAXN];
int T[MAXN];

int mexp(int x, int e, int m) {
  if (e == 0) return 1;
  int r = 1;
  for (int i = 31 - __builtin_clz(e); i >= 0; i--) {
    r = (1ll * r * r) % m;
    if (e & 1 << i) {
      r = (1ll * r * x) % m;
    }
  }
  return r;
}

int main() {
  int N, M, vmax;
  cin >> N >> M >> seed >> vmax;

  int asz = N;
  for (int i = 0; i < N; i++) {
    S[i] = i;
    T[i] = i + 1;
    A[i] = (rnd() % vmax) + 1;
  }

  for (int i = 0; i < M; i++) {
    int op = (rnd() % 4) + 1;
    int l = (rnd() % N) + 1;
    int r = (rnd() % N) + 1;
    if (l > r) {
      swap(l, r);
    }
    l--;

    int x;
    if (op == 3) {
      x = (rnd() % (r - l));
    } else {
      x = (rnd() % vmax) + 1;
    }

    int y = 0;
    if (op == 4) {
      y = (rnd() % vmax) + 1;
    }
    

    if (op == 1) {
      for (int i = 0; i < asz; i++) {
        int ql = max(S[i], l);
        int qr = min(T[i], r);
        if (qr <= ql) {
          continue;
        }
        if (ql != S[i]) {
          S[asz] = ql;
          T[asz] = T[i];
          A[asz] = A[i];
          T[i] = ql;
          asz++;
          i--;
          continue;
        }
        if (qr != T[i]) {
          S[asz] = qr;
          T[asz] = T[i];
          A[asz] = A[i];
          T[i] = qr;
          asz++;
          i--;
          continue;
        }
        A[i] += x;
      }
    } else if (op == 2) {
      for (int i = 0; i < asz; i++) {
        int ql = max(S[i], l);
        int qr = min(T[i], r);
        if (qr <= ql) {
          continue;
        }
        if (ql != S[i]) {
          S[asz] = ql;
          T[asz] = T[i];
          A[asz] = A[i];
          T[i] = ql;
          asz++;
          i--;
          continue;
        }
        if (qr != T[i]) {
          S[asz] = qr;
          T[asz] = T[i];
          A[asz] = A[i];
          T[i] = qr;
          asz++;
          i--;
          continue;
        }
        if (l != S[i]) {
          S[i] = S[asz - 1];
          T[i] = T[asz - 1];
          A[i] = A[asz - 1];
          asz--;
          i--;
          continue;
        }
        A[i] = x;
        T[i] = r;
      }
    } else if (op == 3) {
      vector<pair<long long, int> > res;
      for (int i = 0; i < asz; i++) {
        int ql = max(S[i], l);
        int qr = min(T[i], r);
        if (qr <= ql) {
          continue;
        }
        res.push_back(make_pair(A[i], qr - ql));
      }
      sort(res.begin(), res.end());

      for (auto p : res) {
        if (x < p.second) {
          cout << p.first << '\n';
          break;
        } 
        x -= p.second;
      }
    } else if (op == 4) {
      int res = 0;
      for (int i = 0; i < asz; i++) {
        int ql = max(S[i], l);
        int qr = min(T[i], r);
        if (qr <= ql) {
          continue;
        }
        res = (res + 1ll * (qr - ql) * mexp(A[i] % y, x, y)) % y;
      }
      cout << res << '\n';
    }

//cout << ":: " << asz << endl;
    //cout << op << " " << l << " " << r << endl;
  }

  return 0;
}