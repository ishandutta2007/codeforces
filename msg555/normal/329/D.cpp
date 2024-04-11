#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;

int main() {
  int N; cin >> N;
  if(N == 5) {
    cout <<
        ">...v\n"
        "v.<..\n"
        "..^..\n"
        ">....\n"
        "..^.<\n"
        "1 1\n";
  } else if(N == 3) {
    cout <<
        ">vv\n"
        "^<.\n"
        "^.<\n"
        "1 3\n";
  } else {
    string r1(33, '>');
    for(int j = 0; j < 33; j++) {
      r1 += ">.";
    }
    r1 += 'v';
    cout << r1 << '\n';
    r1[0] = '^';

    string r2 = "^v";
    for(int j = 0; j < 33; j++) {
      r2 += ".<";
    }
    for(; r2.size() < N; ) r2 += '<';
    cout << r2 << '\n';

    for(int i = 0; i < 48; i++) {
      cout << r1 << '\n';
      cout << r2 << '\n';
    }
    cout << "^<" << string(98, '.') << '\n';
    cout << string(100, '.') << '\n';

    cout << "1 1\n";
  }
  return 0;
}