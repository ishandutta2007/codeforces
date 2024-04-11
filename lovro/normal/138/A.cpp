#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <cstring>

using namespace std;

#define repeat(n) for ( int repc = (n); repc > 0; --repc )
#define foreach(i,c) for ( typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i )

int k;

int findsuffixpos(const string &a) {
  int pos, cnt = k;
  for (pos=(int)a.size()-1; pos>=0; --pos) {
    if (strchr("aeiou", a[pos]) != NULL) {
      if (--cnt == 0) {
        return pos;
      }
    }
  }
  return -1;
}

bool rhymes(const string &a, const string &b) {
  int pa = findsuffixpos(a), pb = findsuffixpos(b);
  return pa != -1 && pb != -1 && a.substr(pa) == b.substr(pb);
}

int main() {
  cin.sync_with_stdio(0);

  int n;
  cin >> n >> k;

  map<string, bool> ans;
  ans["aabb"] = ans["abab"] = ans["abba"] = true;

  repeat(n) {
    string a, b, c, d;
    cin >> a >> b >> c >> d;

    ans["aabb"] &= rhymes(a, b) && rhymes(c, d);
    ans["abab"] &= rhymes(a, c) && rhymes(b, d);
    ans["abba"] &= rhymes(a, d) && rhymes(b, c);
  }

  int cnt = 0;
  string which = "NO";

  foreach (it, ans) {
    if (it->second) {
      ++cnt;
      which = it->first;
    }
  }

  if (cnt > 1) {
    cout << "aaaa\n";
  } else {
    cout << which << "\n";
  }

  return 0;
}