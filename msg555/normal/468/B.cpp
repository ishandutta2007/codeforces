#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 100010

int R[MAXN];

int main() {
  int N, A, B;
  cin >> N >> A >> B;

  map<int, int> mp;
  for(int i = 0; i < N; i++) {
    int ai; cin >> ai;
    mp[ai] = i + 1;
  }

  memset(R, -1, sizeof(R));
  if (A == B) {
    for(auto it = mp.begin(); it != mp.end(); ++it) {
      int x = it->first;
      if(mp.find(A - x) == mp.end()) {
        cout << "NO\n";
        return 0;
      }
    }
    memset(R, 0, sizeof(R));
    mp.clear();
  }

  set<int> st;
  for(auto it = mp.begin(); it != mp.end(); ++it) {
    int x = it->first;
    if(!st.insert(x).second) continue;

    int f = -1;
    vector<int> I;
    for(int i = 0, x0 = x; ; i++) {
      if(i % 2 == 0) {
        x0 = A - x0;
        f = 1;
      } else if(i % 2 == 1) {
        x0 = B - x0;
        f = 0;
      }
      if(mp.find(x0) == mp.end()) break;
      I.push_back(mp[x0]);
      st.insert(x0);
    }
    reverse(I.begin(), I.end());
    for(int i = 1, x0 = x; ; i++) {
      if(mp.find(x0) == mp.end()) break;
      I.push_back(mp[x0]);
      st.insert(x0);
      if(i % 2 == 0) {
        x0 = A - x0;
      } else if(i % 2 == 1) {
        x0 = B - x0;
      }
    }

    for(int i = 0; i + 1 < I.size(); i++) {
      if(I[i] == I[i + 1]) {
        if (i % 2 == 0) {
          I.resize(i);
          R[I[i]] = (f + i) % 2;
        } else {
          I.resize(i + 1);
        }
        break;
      }
    }

    if (I.size() % 2) {
      cout << "NO\n";
      return 0;
    }

    for(int i = 0; i < I.size(); i += 2) {
      R[I[i]] = f;
      R[I[i + 1]] = f;
    }
  }

  cout << "YES\n";
  for(int i = 1; i <= N; i++) {
    if(i>1) cout << ' ';
    cout << R[i];
  }
  cout << endl;

  return 0;
}