#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long int64;
#define foreach(i,c) for ( typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i )
#define debug(x) cerr << #x << " = " << (x) << endl;

int main() {
  cin.sync_with_stdio(0);

  string str;
  int64 k;
  cin >> str >> k;
  int n = (int)str.size();

  if (k > int64(n)*(n+1)/2) {
    cout << "No such line.\n";
    return 0;
  }

  vector<int> pool;
  for (int i=0; i<n; ++i) {
    pool.push_back(i);
  }

  vector<int64> cnt1(26), cntsub(26);
  string output;
  for (int level=0;; ++level) {
    fill(cnt1.begin(), cnt1.end(), 0);
    fill(cntsub.begin(), cntsub.end(), 0);
    foreach (it, pool) {
      int pos = *it + level;
      if (pos < n) {
        ++cnt1[str[pos] - 'a'];
        cntsub[str[pos] - 'a'] += max(0, n-pos);
      }
    }
    char selected = -1;
    for (int ch=0; ch<26; ++ch) {
      if (cntsub[ch] >= k) {
        selected = 'a'+ch;
        output += selected;
        k -= cnt1[ch];
        break;
      }
      k -= cntsub[ch];
    }
    if (k < 1) {
      break;
    }

    for (int i=0; i<(int)pool.size(); ++i) {
      int pos = pool[i] + level;
      if (pos >= n || str[pos] != selected) {
        swap(pool[i], pool.back());
        pool.pop_back();
        --i;
      }
    }
  }

  cout << output << endl;
  return 0;
}