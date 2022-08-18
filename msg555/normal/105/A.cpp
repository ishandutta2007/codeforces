#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

int main() {
  int N, M; double dK;
  cin >> N >> M >> dK;
  int K = (int)round(dK * 100);

  map<string, int> mp;
  for(int i = 0; i < N; i++) {
    int lev;
    string S;
    cin >> S >> lev;
    lev = (lev * K) / 100;
    if(lev >= 100) {
      mp[S] = lev;
    }
  }
  for(int i = 0; i < M; i++) {
    string S; cin >> S;
    if(mp.find(S) == mp.end()) mp[S] = 0;
  }
  cout << mp.size() << endl;
  for(typeof(mp.begin()) it = mp.begin(); it != mp.end(); it++) {
    cout << it->first << ' ' << it->second << endl;
  }
}