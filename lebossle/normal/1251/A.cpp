#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int ta=0; ta<t; ++ta) {
    string s;
    cin >> s;
    s += "$";
    set<char> ans;
    for (int i=0; i<s.size()-1; ++i) {
      if (s[i] == s[i+1])
        i++;
      else
        ans.insert(s[i]);
    }
    string res(ans.begin(), ans.end());
    cout << res << endl;
  }
}