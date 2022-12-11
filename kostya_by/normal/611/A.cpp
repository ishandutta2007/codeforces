#include <bits/stdc++.h>

using namespace std;

int months[40];
int weeks[8];

void solve() {
  months[29] = 1;
  months[30] = 4;
  months[31] = 7;

  weeks[1] = 52;
  weeks[2] = 52;
  weeks[3] = 52;
  weeks[4] = 52;
  weeks[5] = 53;
  weeks[6] = 53;
  weeks[7] = 52;

  string b, c;
  int a; 

  cin >> a >> b >> c;


  if (c == "week") {
    cout << weeks[a] << "\n";
  } else {
    int answer = 0;
    for (int i = a; i < 40; i++) {
      answer += months[i];
    }

    cout << answer << "\n";
  }
}

int main() {
  int cases; cases = 1;

  for (int i = 0; i < cases; i++) {
    solve();
  }

  return 0;
}