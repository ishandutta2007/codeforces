#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>
using namespace std;

#define repeat(n) for (int repc = (n); repc > 0; --repc)
#define ALL(x) (x).begin(), (x).end()

const int MAXN = 1005;

struct UnionFind {
  int n;
  vector<int> dad, rank, size;

  UnionFind(int n) : n(n) {
    dad.resize(n);
    rank.resize(n);
    size.resize(n);
    reset();
  }

  void reset() {
    for (int i=0; i<n; ++i) {
      dad[i] = i;
    }
    fill(rank.begin(), rank.end(), 0);
    fill(size.begin(), size.end(), 1);
  }

  int find(int a) {
    int top;
    for (top=a; top != dad[top]; top=dad[top]) ;
    while (dad[a] != top) { int x = dad[a]; dad[a] = top; a = x; }
    return top;
  }

  int union_find(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
      if (rank[a] > rank[b]) {
        dad[b] = a;
        size[a] += size[b];
      } else {
        dad[a] = b;
        size[b] += size[a];
        if (rank[a] == rank[b]) {
          ++rank[b];
        }
      }
      return 1;
    }
    return 0;
  }
};

vector<int> adj[MAXN];
char boja[MAXN];

void floodflip(int a, int parent) {
  boja[a] ^= 1;
  for (int b : adj[a]) {
    if (b != parent) {
      floodflip(b, a);
    }
  }
}

namespace FastInput {
  class FastInput {
  public:
    FastInput() : ptr_(buf_), end_(buf_) { }

    template<typename... Args>
    void read(Args&... args) { read_multi(args...); }
    template<typename T> T read() {
      T result; read_one(result); return result;
    }

  private:
    static const int MAXBUF = 8192;
    char buf_[MAXBUF];
    char *ptr_, *end_;

    template<typename T, typename... Args>
    void read_multi(T& out, Args&... args) {
      read_one(out);
      read_multi(args...);
    }
    void read_multi() { }

    template<typename T>
    void read_one(T& out) {
      static_assert(std::is_integral<T>::value, "");
      unsigned char ch;
      while (isspace(ch = readchar())) ;

      bool neg = false;
      if (std::is_signed<T>::value && ch == '-') {
        neg = true;
        ch = readchar();
      }
      typename std::make_unsigned<T>::type result = ch - '0';
      while (isdigit(ch = readchar())) {
        result = 10 * result + ch - '0';
      }
      out = std::is_signed<T>::value && neg ? -result : result;
    }
    void read_one(unsigned char& out) { out = readchar(); }
    void read_one(char& out) { out = readchar(); }
    void read_one(signed char& out) { out = readchar(); }
    void read_one(std::string& out) {
      out.clear();
      unsigned char ch;
      while (!isspace(ch = readchar())) {
        out.push_back(ch);
      }
    }

    unsigned char readchar() {
      if (ptr_ == end_) {
        ptr_ = buf_;
        end_ = buf_ + ::read(0, buf_, MAXBUF);
        if (ptr_ == end_) { // Simulate newline at EOF
          return '\n';
        }
      }
      return *ptr_++;
    }
  };
}
FastInput::FastInput fin;

namespace FastOutput {
  class FastOutput {
  public:
    FastOutput() : ptr_(buf_), end_(buf_ + BUFSIZE) { }
    ~FastOutput() { flush(); }

    void flush() {
      int rv = ::write(1, buf_, ptr_ - buf_);
      (void)rv;
      ptr_ = buf_;
    }

    template<typename... Args>
    void writeln(const Args&... args) {
      writeln_multi(true, args...);
    }

    void write(const char* str) {
      while (*str != '\0') { putchar(*str++); }
    }
    template<typename T>
    void write(const T& val) {
      static_assert(std::is_integral<T>::value, "");
      typename std::make_unsigned<T>::type x;
      if (std::is_signed<T>::value && val < 0) {
        putchar('-');
        x = -val;
      } else {
        x = val;
      }
      char buf[50], *p = buf;
      do { *p++ = '0' + x%10; x /= 10; } while (x > 0) ;
      do putchar(*--p); while (p != buf);
    }
    template<typename T>
    void write(const vector<T>& v) {
      bool first = true;
      for (const auto& u : v) {
        if (first) { first = false; } else { putchar(' '); }
        write(u);
      }
    }
    void write(const std::string& str) {
      for (char ch : str) { putchar(ch); }
    }
    void write(unsigned char ch) { putchar(ch); }
    void write(char ch) { putchar(ch); }
    void write(signed char ch) { putchar(ch); }

  private:
    static const int BUFSIZE = 8192;
    char buf_[BUFSIZE];
    char *ptr_, *end_;

    template<typename T, typename... Args>
    void writeln_multi(bool first, const T& val, const Args&... args) {
      if (!first) {
        putchar(' ');
      }
      write(val);
      writeln_multi(false, args...);
    }
    void writeln_multi(bool) { putchar('\n'); }

    void putchar(unsigned char ch) {
      if (ptr_ == end_) { flush(); }
      *ptr_++ = ch;
    }
  };
}
FastOutput::FastOutput fout;

int main() {
  ios_base::sync_with_stdio(false);

  int V, E, Q;
  fin.read(V, E, Q);

  struct Edge {
    int a, b, w, idx;
  };
  vector<Edge> edges(E);
  for (int i=0; i<E; ++i) {
    auto& e = edges[i];
    fin.read(e.a, e.b, e.w);
    e.idx = i+1;
  }
  sort(ALL(edges), [](const Edge& e1, const Edge& e2) { return e1.w > e2.w; });

  UnionFind uf(V+1);
  repeat (Q) {
    fill(boja, boja+V+1, 0);
    for (int a=1; a<=V; ++a) {
      adj[a].clear();
    }
    uf.reset();

    int L, R;
    fin.read(L, R);

    int ans = -1;
    for (const auto& e : edges) {
      if (e.idx < L || e.idx > R) {
        continue;
      }
      int a = e.a, b = e.b;
      int atop = uf.find(a), btop = uf.find(b);
      if (atop != btop) {
        if (boja[a] == boja[b]) {
          floodflip(uf.size[atop] < uf.size[btop] ? a : b, -1);
        }
        adj[a].push_back(b);
        adj[b].push_back(a);
        uf.union_find(a, b);
      } else {
        if (boja[a] == boja[b]) {
          ans = e.w;
          break;
        }
      }
    }
    fout.writeln(ans);
  }
}