#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define foreach(i,c) for ( typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i )

string padrev(string s, const vector<int> &cnt) {
  for (int d=0; d<=9; ++d) {
    s += string(cnt[d], '0'+d);
  }
  reverse(s.begin(), s.end());
  return s;
}

void greedysub(int &best,
               pair<string, string> &output,
               vector<int> cnt1,
               vector<int> cnt2,
               int d1,
               int d2) {
  int carry = 0;
  if (cnt1[d1] > 0 && cnt2[d2] > 0) {
    --cnt1[d1];
    --cnt2[d2];
    carry = 1;
  }

  string out1, out2;

  int initialzeros = max(0, min(cnt1[0] - cnt2[9], cnt2[0] - cnt1[9]));
  out1 += string(initialzeros, '0');
  out2 += string(initialzeros, '0');
  cnt1[0] -= initialzeros;
  cnt2[0] -= initialzeros;

  if (carry) {
    out1 += char('0'+d1);
    out2 += char('0'+d2);
  }

  int count = initialzeros + carry;
  for (int d=0; d<=9; ++d) {
    int e = (9-d) % 10;
    while (cnt1[d] && cnt2[e]) {
      --cnt1[d]; out1 += char('0' + d);
      --cnt2[e]; out2 += char('0' + e);
      count += carry;
    }
  }

  if (count > best) {
    best = count;
    output = make_pair(padrev(out1, cnt1), padrev(out2, cnt2));
  }
}

int main() {
  cin.sync_with_stdio(0);

  string input;
  cin >> input;
  vector<int> cnt1(10, 0);
  foreach (it, input) {
    ++cnt1[*it - '0'];
  }

  vector<int> cnt2(cnt1);

  int best = 0;
  pair<string, string> output(input, input);
  
  for (int d=1; d<=9; ++d) {
    greedysub(best, output, cnt1, cnt2, d, 10-d);
  }

  cout << output.first << "\n";
  cout << output.second << "\n";

  return 0;
}