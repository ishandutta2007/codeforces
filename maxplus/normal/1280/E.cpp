#include <bits/stdc++.h>

using namespace std;

constexpr int N = 80000, M = N * 2 + 5;

array<int, 3> node[M];
bool alive[N];
int tofill[N];
string expr;
const char* pos;

struct Solver {
  Solver() {
    uint64_t r;
    cin >> r;
    cin.ignore();
    getline(cin, expr);
    pos = expr.c_str();
    int v = reduce();
    memset(alive, 0, resistors);
    r *= node[v][2];
    int nfill = 0;
    while (1) {
      if (v == -1) {
        if (nfill == 0) break;
        v = tofill[--nfill];
      }
      if (node[v][2] == 1) {
        alive[node[v][0]] = 1;
        v = -1;
      } else {
        tofill[nfill++] = node[v][0];
        v = node[v][1];
      }
    }
    auto s = " " + to_string(r);
    auto t = " 0"s;
    cout << "REVOLTING";
    for (int i = 0; i < resistors; ++i) {
      puts((alive[i] ? s : t).c_str());
    }
    cout << "\n";
  }

private:
  int resistors = 0;
  int nodes = 0;

  void combine(int& v, int u, char op) {
    if (op == 'P') {
      node[nodes] = {v, u, node[v][2] + node[u][2]};
      v = nodes++;
    } else if (node[v][2] > node[u][2]) {
      swap(v, u);
    }
  }

  char getc() {
    if (*pos == ' ') {
      ++pos;
    }
    return *pos++;
  }

  int reduce() {
    if (getc() == '*') {
      return node[nodes] = {resistors, resistors++, 1}, nodes++;
    }
    int v = reduce();
    char c;
    while ((c = getc()) != ')') {
      combine(v, reduce(), c);
    }
    return v;
  }
};

int main() {
  for (int t = (cin >> t, t); t--; ) {
    Solver{};
  }
}