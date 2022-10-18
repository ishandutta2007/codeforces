#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define foreach(i,c) for (decltype((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()

int main() {
  cin.sync_with_stdio(0);

  string s;
  int n;
  cin >> s >> n;

  vector<char> seen(26, 0);
  vector<int> freq(26, 0);
  foreach (it, s) {
    ++freq[*it - 'a'];
    seen[*it - 'a'] = 1;
  }

  if (count(ALL(seen), 1) > n) {
    cout << "-1\n";
    return 0;
  }

  for (int nsheets=1; nsheets<=s.size(); ++nsheets) {
    string output;
    vector<int> freq2(freq);
    for (int i=0; i<26; ++i) {
      while (freq2[i] > 0) {
        output += 'a' + i;
        freq2[i] -= nsheets;
      }
    }
    if (output.size() > n) {
      continue;
    }
    cout << nsheets << '\n';
    output += string(n - output.size(), 'a');
    cout << output << '\n';
    break;
  }
  return 0;
}