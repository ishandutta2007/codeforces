#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

set<string> st;
set<pair<int, string> > vis;

void chomp(const string& S, int pos, string lst) {
  if (!vis.insert(make_pair(pos, lst)).second) {
    return;
  }

  for (int ln = 2; ln <= 3; ln++) {
    int s = pos - ln;
    if (s < 5) {
      continue;
    }

    string t = S.substr(s, ln);
    if (t != lst) {
      st.insert(t);
      chomp(S, s, t);
    }
  }
}

int main() {
  string S; cin >> S;
  chomp(S, S.size(), "");

  cout << st.size() << endl;
  for (string s : st) {
    cout << s << '\n';
  }
  return 0;
}