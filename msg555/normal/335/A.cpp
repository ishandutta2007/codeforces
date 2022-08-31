#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
  map<char, int> mp;
  string S; cin >> S;
  int N; cin >> N;

  for(int i = 0; i < S.size(); i++) {
    ++mp[S[i]];
  }
  if(mp.size() > N) {
    cout << "-1\n";
    return 0;
  }

  for(int i = 1; ; i++) {
    string R;
    for(typeof(mp.begin()) it = mp.begin(); R.size() <= N && it != mp.end();
        ++it) {
      R += string((it->second + i - 1) / i, it->first);
    }
    if(R.size() <= N) {
      cout << i << endl;
      cout << R << string(N - R.size(), 'a') << endl;
      return 0;
    }
  }
}