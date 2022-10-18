#define NDEBUG
#include <cassert>
#include <cstdint>
#include <cstring>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

#define MINUSONE(v) memset((v), -1, sizeof (v))

int n;
int8_t win[7005][2];
short out_win_count[7005][2];
vector<int> moves[2];

void mark_losing(int, int);
void mark_winning(int pos, int pl) {
  if (pos == 1) {
    return;
  }
  auto& ref = win[pos][pl];
  if (ref != -1) {
    assert(ref == 1);
    return;
  }
  ref = 1;
  for (int m : moves[!pl]) {
    int prev = pos - m;
    if (prev < 1) {
      prev += n;
    }
    if (++out_win_count[prev][!pl] == (int)moves[!pl].size()) {
      mark_losing(prev, !pl);
    }
  }
}

void mark_losing(int pos, int pl) {
  auto& ref = win[pos][pl];
  if (ref != -1) {
    assert(ref == 0);
    return;
  }
  ref = 0;
  for (int m : moves[!pl]) {
    int prev = pos - m;
    if (prev < 1) {
      prev += n;
    }
    mark_winning(prev, !pl);
  }
}

int main() {
  ios_base::sync_with_stdio(false);

  cin >> n;

  for (int i=0; i<2; ++i) {
    int k;
    cin >> k;
    vector<int>& v = moves[i];
    v.resize(k);
    for (auto& x : v) {
      cin >> x;
    }
  }

  MINUSONE(win);
  mark_losing(1, 0);
  mark_losing(1, 1);
  for (int pl=0; pl<2; ++pl) {
    for (int pos=2; pos<=n; ++pos) {
      const char* ans;
      switch (win[pos][pl]) {
      case 1: ans = "Win"; break;
      case 0: ans = "Lose"; break;
      case -1: ans = "Loop"; break;
      default: assert(false);
      }
      cout << ans << " \n"[pos == n];
    }
  }
}