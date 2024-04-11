#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
//#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(bool);
void precalc();
clock_t start;
int main() {
#ifdef AIM
  freopen("/home/alexandero/CLionProjects/ACM/input.txt", "r", stdin);
  //freopen("/home/alexandero/CLionProjects/ACM/output.txt", "w", stdout);
  //freopen("out.txt", "w", stdout);
#else
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif
  start = clock();
  int t = 1;
  cout.sync_with_stdio(0);
  cin.tie(0);
  precalc();
  cout.precision(20);
  cout << fixed;
  //cin >> t;
  while (t--) {
    solve(true);
  }
  cout.flush();

#ifdef AIM1
  while (true) {
      solve(false);
  }
#endif

#ifdef AIM
  cerr << "\n\n time: " << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif
  return 0;
}

//BE CAREFUL: IS INT REALLY INT?

template<typename T>
T binpow(T q, T w, T mod) {
  if (!w)
    return 1 % mod;
  if (w & 1)
    return q * 1LL * binpow(q, w - 1, mod) % mod;
  return binpow(q * 1LL * q % mod, w / 2, mod);
}

template<typename T>
T gcd(T q, T w) {
  while (w) {
    q %= w;
    swap(q, w);
  }
  return q;
}
template<typename T>
T lcm(T q, T w) {
  return q / gcd(q, w) * w;
}

void precalc() {

}

//#define int li
//const int mod = 1000000007;

using State = std::array<int, 10>;

State start_state() {
  State res;
  res.fill(0);
  return res;
}

template <typename T>
void make_unique(vector<T>& vec) {
  sort(all(vec));
  vec.erase(unique(all(vec)), vec.end());
}

void print(State cur) {
  for (int i = 0; i < 10; ++i) {
    cout << cur[i] << " ";
  }
  cout << endl;
}

const int lg = 18;

vector<State> all_states;

vector<int> cur_state;

li L, R;
vector<int> l, r;

int ans = 0;
void process_state(State cur) {
  li cur_num = 0;
  bool found = false;
  bool good = true;
  bool is_less = false;
  for (int i = 0; i < lg && !found; ++i) {
    for (int c = l[i] + 1; c < 10; ++c) {
      if (cur[c]) {
        if (!is_less && c > r[i]) {
          break;
        }
        li now_num = cur_num * 10 + c;
        --cur[c];
        for (int j = 0; j < 10; ++j) {
          for (int z = 0; z < cur[j]; ++z) {
            now_num = now_num * 10 + j;
          }
        }
        ++cur[c];
        if (now_num <= R) {
          ++ans;
          //print(prev);
          found = true;
        }
        break;
      }
    }
    if (cur[l[i]] == 0) {
      good = false;
      break;
    }
    --cur[l[i]];
    if (l[i] < r[i]) {
      is_less = true;
    }
    cur_num = cur_num * 10 + l[i];
  }
  if (good && cur_num >= L && cur_num <= R) {
    ++ans;
  }
}

void gen_states(int last) {
  if (cur_state.size() == lg) {
    State res;
    res.fill(0);
    for (int i = 0; i < lg; ++i) {
      int c = cur_state[i];
      ++res[c];
    }
    /*for (int i = 0; i < 10; ++i) {
      cout << cur_state[i] << " ";
    }
    cout << endl;*/
    //all_states.push_back(res);
    process_state(res);
    return;
  }
  cur_state.push_back(last);
  gen_states(last);
  cur_state.pop_back();
  if (last + 1 < 10) {
    gen_states(last + 1);
  }
}

void solve(bool read) {
  //li L, R;
  cin >> L >> R;
  if (R == L) {
    cout << "1" << endl;
    return;
  }
  int add_ans = 0;
  if (R == 1000000000000000000LL) {
    --R;
    if (L > 100000000000000000LL) {
      ++add_ans;
    }
  }
  ans = add_ans;
  li oldL = L;
  li oldR = R;
  for (int i = 0; i < lg; ++i) {
    l.push_back(oldL % 10);
    r.push_back(oldR % 10);
    oldL /= 10;
    oldR /= 10;
  }
  reverse(all(l));
  reverse(all(r));

  gen_states(0);

  //cout << all_states.size() << endl;

  //int ans = add_ans;
  /*for (State cur : all_states) {
    li cur_num = 0;
    bool found = false;
    bool good = true;
    bool is_less = false;
    for (int i = 0; i < lg && !found; ++i) {
      for (int c = l[i] + 1; c < 10; ++c) {
        if (cur[c]) {
          if (!is_less && c > r[i]) {
            break;
          }
          li now_num = cur_num * 10 + c;
          --cur[c];
          for (int j = 0; j < 10; ++j) {
            for (int z = 0; z < cur[j]; ++z) {
              now_num = now_num * 10 + j;
            }
          }
          ++cur[c];
          if (now_num <= R) {
            ++ans;
            //print(prev);
            found = true;
          }
          break;
        }
      }
      if (cur[l[i]] == 0) {
        good = false;
        break;
      }
      --cur[l[i]];
      if (l[i] < r[i]) {
        is_less = true;
      }
      cur_num = cur_num * 10 + l[i];
    }
    if (good && cur_num >= L && cur_num <= R) {
      ++ans;
    }
  }*/

  cout << ans << endl;

  // add_ans

}