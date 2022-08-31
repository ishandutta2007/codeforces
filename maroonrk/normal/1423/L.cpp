#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

using Int = long long;

template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << endl; }
template <class T> bool chmin(T &t, const T &f) { if (t > f) { t = f; return true; } return false; }
template <class T> bool chmax(T &t, const T &f) { if (t < f) { t = f; return true; } return false; }


//fast IO by yosupo
struct Scanner {
    FILE* fp = nullptr;
    char line[(1 << 15) + 1];
    size_t st = 0, ed = 0;
    void reread() {
        memmove(line, line + st, ed - st);
        ed -= st;
        st = 0;
        ed += fread(line + ed, 1, (1 << 15) - ed, fp);
        line[ed] = '\0';
    }
    bool succ() {
        while (true) {
            if (st == ed) {
                reread();
                if (st == ed) return false;
            }
            while (st != ed && isspace(line[st])) st++;
            if (st != ed) break;
        }
        if (ed - st <= 50) reread();
        return true;
    }
    template <class T, enable_if_t<is_same<T, string>::value, int> = 0>
    bool read_single(T& ref) {
        if (!succ()) return false;
        while (true) {
            size_t sz = 0;
            while (st + sz < ed && !isspace(line[st + sz])) sz++;
            ref.append(line + st, sz);
            st += sz;
            if (!sz || st != ed) break;
            reread();            
        }
        return true;
    }
    template <class T, enable_if_t<is_integral<T>::value, int> = 0>
    bool read_single(T& ref) {
        if (!succ()) return false;
        bool neg = false;
        if (line[st] == '-') {
            neg = true;
            st++;
        }
        ref = T(0);
        while (isdigit(line[st])) {
            ref = 10 * ref + (line[st++] - '0');
        }
        if (neg) ref = -ref;
        return true;
    }
    template <class T> bool read_single(vector<T>& ref) {
        for (auto& d : ref) {
            if (!read_single(d)) return false;
        }
        return true;
    }
    void read() {}
    template <class H, class... T> void read(H& h, T&... t) {
        bool f = read_single(h);
        assert(f);
        read(t...);
    }
    Scanner(FILE* _fp) : fp(_fp) {}
};
 
struct Printer {
  public:
    template <bool F = false> void write() {}
    template <bool F = false, class H, class... T>
    void write(const H& h, const T&... t) {
        if (F) write_single(' ');
        write_single(h);
        write<true>(t...);
    }
    template <class... T> void writeln(const T&... t) {
        write(t...);
        write_single('\n');
    }
 
    Printer(FILE* _fp) : fp(_fp) {}
    ~Printer() { flush(); }
 
  private:
    static constexpr size_t SIZE = 1 << 15;
    FILE* fp;
    char line[SIZE], small[50];
    size_t pos = 0;
    void flush() {
        fwrite(line, 1, pos, fp);
        pos = 0;
    }
    void write_single(const char& val) {
        if (pos == SIZE) flush();
        line[pos++] = val;
    }
    template <class T, enable_if_t<is_integral<T>::value, int> = 0>
    void write_single(T val) {
        if (pos > (1 << 15) - 50) flush();
        if (val == 0) {
            write_single('0');
            return;
        }
        if (val < 0) {
            write_single('-');
            val = -val;  // todo min
        }
        size_t len = 0;
        while (val) {
            small[len++] = char('0' + (val % 10));
            val /= 10;
        }
        for (size_t i = 0; i < len; i++) {
            line[pos + i] = small[len - 1 - i];
        }
        pos += len;
    }
    void write_single(const string& s) {
        for (char c : s) write_single(c);
    }
    void write_single(const char* s) {
        size_t len = strlen(s);
        for (size_t i = 0; i < len; i++) write_single(s[i]);
    }
    template <class T> void write_single(const vector<T>& val) {
        auto n = val.size();
        for (size_t i = 0; i < n; i++) {
            if (i) write_single(' ');
            write_single(val[i]);
        }
    }
};
 
Scanner sc(stdin);
Printer pr(stdout);


constexpr int MAX_N = 1010;
constexpr int MAX_S = 30;

int N, S, D;
int C[MAX_S];
int A[MAX_S][MAX_N];

bitset<MAX_N> as[MAX_S];
int H;
unordered_map<bitset<MAX_N>, int> mns;

void dfs0(int s, const bitset<MAX_N> &key, int val) {
  if (s == H) {
    auto it = mns.find(key);
    if (it == mns.end()) {
      mns[key] = val;
    } else {
      chmin(it->second, val);
    }
  } else {
    dfs0(s + 1, key, val);
    dfs0(s + 1, key ^ as[s], val + 1);
  }
}

int T;
int B[MAX_N];
int ans;

void dfs1(int s, const bitset<MAX_N> &key, int val) {
  if (s == S) {
    auto it = mns.find(key);
    if (it != mns.end()) {
      chmin(ans, it->second + val);
    }
  } else {
    dfs1(s + 1, key, val);
    dfs1(s + 1, key ^ as[s], val + 1);
  }
}

int main() {
  {
    sc.read(N);
    sc.read(S);
    sc.read(D);
    for (int s = 0; s < S; ++s) {
      sc.read(C[s]);
      for (int c = 0; c < C[s]; ++c) {
        sc.read(A[s][c]);
      }
    }
    
    for (int s = 0; s < S; ++s) {
      as[s].reset();
      for (int c = 0; c < C[s]; ++c) {
        as[s][A[s][c]] = true;
      }
    }
    H = S - S / 3;
    dfs0(0, bitset<MAX_N>{}, 0);
    
    bitset<MAX_N> start;
    for (int d = 0; d < D; ++d) {
      sc.read(T);
      for (int t = 0; t < T; ++t) {
        sc.read(B[t]);
      }
      
      start.reset();
      for (int t = 0; t < T; ++t) {
        start[B[t]] = true;
      }
      ans = S + 1;
      dfs1(H, start, 0);
      printf("%d\n", (ans >= S + 1) ? -1 : ans);
    }
  }
  return 0;
}