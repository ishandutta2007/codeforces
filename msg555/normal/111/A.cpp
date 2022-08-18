#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
  long long N, X, Y;
  cin >> N >> X >> Y;

  if(N > Y) {
    cout << -1 << endl;
  } else {
    if((N - 1) + (Y - N + 1) * (Y - N + 1) < X) {
      cout << -1 << endl;
    } else {
      for(int i = 1; i < N; i++) cout << "1\n";
      cout << Y - N + 1 << endl;
    }
  }
}