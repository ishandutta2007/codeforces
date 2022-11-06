#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  while (n--) {
    string s, t;
    cin >> s >> t;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    set<char> st;
    int i=0;
    bool pos = true;
    for (char c : t) {
      while (i < s.size() && s[i] != c) {
        st.insert(s[i]);
        i++;
      }
      if (i == s.size() || st.count(c)) {
        pos = false;
        break;
      }
      i++;
    }
    cout << (pos ? "YES" : "NO") << endl;
  }
}