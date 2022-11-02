#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  string s;
  cin >> s;
  long long odd = 0;
  long long even = 0;
  vector<long long> cnt_odd(2, 0);
  vector<long long> cnt_even(2, 0);
  for (int i = 0; i < s.length(); i++) {
    int c = s[i] - 'a';
    if (i % 2 == 0) {
      cnt_even[c]++;
      odd += cnt_odd[c];
      even += cnt_even[c];
    }
    else {
      cnt_odd[c]++;
      odd += cnt_even[c];
      even += cnt_odd[c];
    }
  }
  cout << odd << " " << even << endl;
  return 0;
}