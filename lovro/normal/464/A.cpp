#define NDEBUG
#include <iostream>
#include <string>
using namespace std;

template<typename T, typename U> inline void makemin(T &res, const U &x) {
  if (x < res) {
    res = x;
  }
}

bool has_palin_ends(const string &s, int endpos) {
  for (int start=endpos-1; start>=0; --start) {
    int i, j;
    for (i=start, j=endpos; i<j && s[i] == s[j]; ++i, --j) ;
    if (i >= j) {
      return true;
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(0);

  int n, p;
  cin >> n >> p;
  string s;
  cin >> s;
  int known_tolerable = 1;
  while (1) {
    {
      int i;
      for (i=n-1; i>=0; --i) {
        makemin(known_tolerable, i);
        if (s[i] == 'a' + p - 1) {
          s[i] = 'a';
        } else {
          ++s[i];
          break;
        }
      }
      if (i < 0) {
        cout << "NO\n";
        break;
      }
    }
    for (int i=known_tolerable; i<n; ++i) {
      if (has_palin_ends(s, i)) {
        for (int j=i+1; j<n; ++j) {
          s[j] = 'a' + p - 1;
        }
        break;
      }
      known_tolerable = i + 1;
    }
    if (known_tolerable == n) {
      cout << s << '\n';
      break;
    }
  }
}