#include <iostream>

using namespace std;

template<typename... Ts> void print(const Ts&... ts) { ((cout << ts << ' '), ...) << '\n'; }
struct { using X = int; template <typename T = X> auto operator ()() const { T t; cin >> t; return t; } operator X() const { return this->operator()<X>(); } template <typename T> operator T() const { return this->operator()<T>(); } } $;

struct Coord {
  int r, c;

  operator bool() {
    return r || c;
  }
};

bool interact(Coord c, int& dr) {
  print(c.r + 1, c.c + 1);
  string s = $;
  dr = s.find("Up") != s.npos? -1: s.find("Down") != s.npos;
  return s.find("Done") == s.npos;
}

constexpr int N = 8;

void solve(Coord q) {
  while (1) {
    int dr;
    do {
      ++q.r;
      if (!interact(q, dr)) {
        return;
      }
    } while (q.r != 1 && dr == 1);
    for (int c = 1; c < N - 1; ++c) if (q.c != c) {
      q.c = c;
      if (!interact(q, dr)) {
        return;
      } else if (dr == 1) {
        break;
      } else if (dr) {
        c = 0;
      }
    }
  }
}

int main() {
  for (int testcase = $; testcase; --testcase) {
    solve({0, 1});
  }
}