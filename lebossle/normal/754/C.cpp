#include <bits/stdc++.h>
using namespace std;

// This code uses the bossle/cp library
// Available at https://github.com/bossle/cp

// #pragma STDC FENV_ACCESS OFF
// #pragma STDC FP_CONTRACT ON
// #pragma STDC CX_LIMITED_RANGE ON
// #pragma GCC optimize "O3"

namespace cp_base {

auto init = (
  ios::sync_with_stdio(false),
  cin.tie(nullptr)
);

}  // namespace cp_base

       

#define LOG(x) 

string userChar="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

void solve() {
  int n;
  cin >> n;
  vector<string> names(n);
  for (string& s : names)
    cin >> s;
  int m;
  cin >> m;
  vector<string> input(m);
  cin.get();
  for (string& s : input)
    getline(cin, s);
  LOG(names);
  LOG(input);
  vector<set<string>> sender(m, set<string>(names.begin(), names.end()));
  vector<string> messages(m);
  for (int i=0; i<m; ++i) {
    int colon = input[i].find(':');
    string user = input[i].substr(0, colon);
    string msg = input[i].substr(colon+1);
    messages[i] = msg;
    LOG(input[i]);
    LOG(user);
    LOG(msg);
    if (user != "?")
      sender[i] = set<string>{user};
    for (int j=0; j<msg.size();) {
      int r = min(msg.size(), msg.find_first_not_of(userChar, j));
      LOG(r);
      sender[i].erase(msg.substr(j, r-j));
      j = r+1;
    }
  }
  LOG(sender);
  LOG(messages);
  for (int i=0; i<m; ++i)
    if (sender[i].size() == 1) {
      string s = *sender[i].begin();
      if (i+1<m)
        sender[i+1].erase(s);
      if (i>0 && sender[i-1].count(s)) {
        sender[i-1].erase(s);
        i-=2;
      }
    }
  LOG(sender);
  for (int i=0; i<m; ++i) {
    if (sender[i].empty()) {
      cout << "Impossible" << endl;
      return;
    }
    string s = *sender[i].begin();
    sender[i] = set<string>{s};
    if (i+1<m)
      sender[i+1].erase(s);
  }
  LOG(sender);
  for (int i=0; i<m; ++i)
    cout << *sender[i].begin() << ":" << messages[i] << '\n';
}

int main() {
  int t;
  cin >> t;
  for (int ta=0; ta<t; ++ta)
    solve();
}