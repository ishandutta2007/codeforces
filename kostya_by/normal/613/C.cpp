#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 30;

int aa[22][22];
string ss[22][22];

int is_palindrome(const string &s) {
  int l = 0, r = s.size() - 1;

  while (l < r) {
    if (s[l] != s[r]) {
      return 0;
    }

    l += 1;
    r -= 1;
  }

  return 1;
}

int calc(string s) {
  int result = 0;
  int n = s.size();

  for (int i = 0; i < n; i++) {
    result += is_palindrome(s);
    s += s[0];
    s.erase(s.begin());
  }

  return result;
}

int S;
vector<int> sz;
vector<char> cz;
string buffer;

int answer = -1;
string optimal = "";

void rec(int pos) {
  if (pos == S) {
    buffer = "";

    for (int i = 0; i < S; i++) {
      buffer += cz[i];
    }

    int value = calc(buffer);
    if (value > answer) {
      answer = value;
      optimal = buffer;
    }

    return; 
  }

  for (int i = 0; i < sz.size(); i++) {
    if (sz[i]) {
      cz.push_back('a' + i);
      sz[i] -= 1;

      rec(pos + 1);
    
      sz[i] += 1;
      cz.pop_back();
    }
  }
}

pair<int, string> solve1(vector<int> s) {
  S = 0;
  answer = -1;
  optimal = "";

  sz = s;
  for (int i = 0; i < s.size(); i++) {
    S += s[i];
  }

  rec(0);

  return make_pair(answer, optimal);
}

// baaaabbaaaab

int n;
int a[MAX_N];

void solve2() {
  // cerr << calc("baaaabbaaaab") << "\n";

  // for (int a = 2; a <= 10; a += 2) {
  //   for (int b = 2; b <= 10; b += 2) {
  //     auto x = solve1({a, b});
  //     cerr << a << " " << b << " -> " << x.first << " " << x.second << "\n";
  //   }
  // }

  auto x = solve1({4, 4, 4, 4});
  cerr << 4 << " " << 4 << " " << 4 << " " << 4 << " -> " << x.first << " " << x.second << "\n";
}

int gcd(int a, int b) {
  if (a != 0) {
    return gcd(b % a, a);
  } else {
    return b;
  }
}

void solve() {
  cin >> n;
  int odd_count = 0;
  int odd_place = -1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];

    if (a[i] % 2) {
      odd_count += 1;
      odd_place = i;
    }
  }

  if (n == 1) {
    string s = "";
    for (int i = 0; i < a[0]; i++) {
      s += 'a';
    }

    cout << a[0] << "\n";
    cout << s << "\n";
    return;
  }

  if (odd_count > 1) {
    string s = "";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < a[i]; j++) {
        s += 'a' + i;
      }
    }

    cout << 0 << "\n";
    cout << s << "\n";

    return;
  }

  int g = 0;
  for (int i = 0; i < n; i++) {
    g = gcd(g, a[i]);
  }

  cout << g << "\n";

  string answer = "";

  if (odd_count == 1) {

    string s = "";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < a[i] / g - a[i] % 2; j += 2) {
        s += 'a' + i;
      }
    }

    string t = s;
    t += 'a' + odd_place;
    reverse(s.begin(), s.end());
    t += s;

    for (int i = 0; i < g; i++) {
      answer += t;
    }
    // cerr << s << "\n";
  } else {
    string s = "";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < a[i] / g; j++) {
        s += 'a' + i;
      }
    }

    string t = s;
    reverse(t.begin(), t.end());

    for (int i = 0; i < g / 2; i++) {
      answer += s;
      answer += t;
    }
  }

  cout << answer << "\n";

  // cerr << "calc = " << calc(answer) << "\n";
}

// aabbaabbaabb
// abbaabbaabba

// aabcddcbaabcddcb
// cddcbaabcddcbaab

int main() {
  ios_base::sync_with_stdio(0);
  int cases; cases = 1;

  for (int i = 0; i < cases; i++) {
    solve();
  }

  return 0;
}