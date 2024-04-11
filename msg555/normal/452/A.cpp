#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>

using namespace std;

string poks[] = {
"vaporeon",
"jolteon",
"flareon",
"espeon", 
"umbreon", 
"leafeon", 
"glaceon", 
"sylveon",
};

int main() {
  int N; cin >> N;
  string S; cin >> S;
  for(int i = 0; i < 8; i++) {
    bool ok = N == poks[i].size();
    for(int j = 0; j < N && ok; j++) {
      ok = S[j] == '.' || S[j] == poks[i][j];
    }
    if(ok) {
      cout << poks[i] << endl;
    }
  }
  return 0;
}