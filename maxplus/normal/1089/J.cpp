#include <iostream>
#include <numeric>
#include <utility>
#include <vector>
#include <deque>
#include <map>
#include <set>

using namespace std;

set<string> reserved;
vector<string> tokens;

bool isnum(char c) {
  return !!isdigit(c);
}

bool isword(char c) {
  return isalnum(c) || c == '_' || c == '$';
}

int parsele(const string& s, int pos, int male = 1 << 30) {
  bool isn = isnum(s[pos]), isw = !isn && isword(s[pos]);
  int last = 0;
  int le = 1;
  while (1) {
    if (le <= 20 && reserved.count(s.substr(pos, le)) || isn || isw) {
      last = le;
    } else if (le > 20) {
      break;
    }
    if (pos + le == s.size()) {
      break;
    }
    isn &= isnum(s[pos + le]), isw &= isword(s[pos + le]);
    ++le;
    if (last > male) {
      break;
    }
  }
  if (last == male) {
    last = 1 << 30;
  }
  return last;
}

void read() {
  for (int nr = (cin >> nr, nr); nr--; ) {
    string s; cin >> s;
    reserved.insert(s);
  }
  string nocomments;
  for (int nl = (cin >> nl, cin.ignore(9999, '\n'), nl); nl--; ) {
    char c = 0;
    while (c != '\n') {
      c = cin.get();
      if (c == '#') {
        cin.ignore(9999, c = '\n');
      }
      if (!isspace(c)) {
        nocomments += c;
      } else if (nocomments.size() && nocomments.back() != ' ') {
        nocomments += ' ';
      }
    }
  }
  for (int i = 0; i < nocomments.size(); ) {
    if (nocomments[i] == ' ') {
      ++i;
      continue;
    }
    int le = parsele(nocomments, i);
    tokens.push_back(nocomments.substr(i, le));
    i += le;
  }
}

void rename() {
  deque<string> mini;
  for (char c = 'a'; c <= 'z'; ++c) if (!reserved.count({c})) {
    mini.push_back({c});
  }
  for (char c = 'a'; c <= 'z'; ++c)
  for (char d = 'a'; d <= 'z'; ++d) if (!reserved.count({c, d})) {
    mini.push_back({c, d});
  }
  for (char c = 'a'; c <= 'z'; ++c)
  for (char d = 'a'; d <= 'z'; ++d)
  for (char e = 'a'; e <= 'z'; ++e) if (!reserved.count({c, d, e})) {
    mini.push_back({c, d, e});
    if (mini.size() > 980) {
      c = d = e = 'z';
    }
  }
  map<string, string> rules;
  for (auto& s: tokens) {
    if (reserved.count(s) || isnum(s[0])) {
      continue;
    } else if (auto it = rules.lower_bound(s); it == rules.end() || it->first != s) {
      s = rules.emplace_hint(it, s, mini.front())->second; mini.pop_front();
    } else {
      s = it->second;
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  read();
  rename();
  int n = tokens.size();
  string s = accumulate(tokens.begin(), tokens.end(), ""s);
  vector<string> ans;
  for (int i = n, pos = s.size(); i--; ) {
    vector<string> cur;
    for (int j = i, le = 0; ; --j) {
      if (j == -1 || (le += tokens[j].size(),
                      parsele(s, pos - le, tokens[j].size()) <= le)) {
        i -= cur.size() - 1;
        pos -= j == -1? le: le - tokens[j].size();
        break;
      }
      cur.push_back(tokens[j]);
    }
    ans.push_back(accumulate(cur.rbegin(), cur.rend(), " "s));
  }
  cerr << '#';
  cout << accumulate(ans.rbegin(), ans.rend(), ""s).substr(1);
  cerr << '#';
}