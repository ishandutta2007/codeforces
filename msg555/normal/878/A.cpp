#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N; cin >> N;

  vector<int> st(10, 0);
  for (int i = 0; i < N; i++) {
    char cmd; cin >> cmd;
    int num; cin >> num;

    for (int i = 0; i < 10; i++) {
      bool bt = (num & 1 << i) != 0;
      if (cmd == '|') {
        if (bt) {
          st[i] = -1;
        }
      } else if (cmd == '&') {
        if (!bt) {
          st[i] = -2;
        }
      } else if (cmd == '^') {
        if (bt) {
          st[i] ^= 1;
        }
      }
    }
  }

  int orcmd = 0;
  int andcmd = 0;
  int xorcmd = 0;
  for (int i = 0; i < 10; i++) {
    if (st[i] == 1) {
      xorcmd |= 1 << i;
    }
    if (st[i] == -1) {
      orcmd |= 1 << i;
    }
    if (st[i] != -2) {
      andcmd |= 1 << i;
    }
  }

  cout << 3 << endl;
  cout << "| " << orcmd << endl;
  cout << "& " << andcmd << endl;
  cout << "^ " << xorcmd << endl;

  return 0;
}