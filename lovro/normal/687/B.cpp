#define NDEBUG
#include <cassert>
#include <cctype>
#include <iostream>
#include <tuple>
#include <unistd.h>
#include <utility>
#include <vector>
using namespace std;

#define repeat(n) for (int repc = (n); repc > 0; --repc)

const int MAXK = 1000005;

class Faktorizator {
public:
  Faktorizator(int upto) : factor_(upto/2+1) {
    for (int i=3; i*i<=upto; i+=2) {
      if (factor_[i/2] == 0) {
        for (int j=i*i; j<=upto; j+=2*i) {
          if (factor_[j/2] == 0) {
            factor_[j/2] = i;
          }
        }
      }
    }
  }

  void rastavi(int n, vector<pair<int, int> >& out) {
    assert(n >= 1);
    assert(n/2 <= (int)factor_.size());
    out.clear();
    auto dodaj = [&](int a) {
      if (out.empty() || a != out.back().first) {
        out.push_back(make_pair(a, 1));
      } else {
        ++out.back().second;
      }
    };
    while (n % 2 == 0) {
      dodaj(2);
      n /= 2;
    }
    while (n > 1 && factor_[n/2] != 0) {
      dodaj(factor_[n/2]);
      n /= factor_[n/2];
    }
    if (n > 1) {
      dodaj(n);
    }
  }

  vector<pair<int, int> > rastavi(int n) {
    vector<pair<int, int> > out;
    rastavi(n, out);
    return out;
  }

private:
  vector<int> factor_;
};

namespace FastInput {
  class FastInput {
  public:
    FastInput() : ptr_(buf_), end_(buf_) { }

    unsigned char readchar() {
      if (ptr_ == end_) {
        ptr_ = buf_;
        end_ = buf_ + ::read(0, buf_, MAXBUF);
      }
      return *ptr_++;
    }

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
  } fin;

  template<> void FastInput::read_one<>(unsigned char& out) { out = readchar(); }
  template<> void FastInput::read_one<>(char& out) { out = readchar(); }
  template<> void FastInput::read_one<>(signed char& out) { out = readchar(); }
}
FastInput::FastInput fin;

int main() {
  int n, k;
  fin.read(n, k);

  Faktorizator fakt(MAXK);

  vector<pair<int, int> > krastav = fakt.rastavi(k);
  repeat (n) {
    int c;
    fin.read(c);
    static vector<pair<int, int> > crastav;
    fakt.rastavi(c, crastav);
    for (pair<int, int> par : crastav) {
      int a, p;
      tie(a, p) = par;
      for (int j = 0; j < (int)krastav.size(); ++j) {
        if (krastav[j].first > a) {
          break;
        } else if (krastav[j].first == a) {
          if (krastav[j].second <= p) {
            krastav.erase(krastav.begin() + j);
          }
          break;
        }
      }
    }
  }
  cout << (krastav.empty() ? "Yes" : "No") << '\n';
}