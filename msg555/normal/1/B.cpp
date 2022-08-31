#include <iostream>
#include <vector>
#include <ctype.h>
#include <stdlib.h>

using namespace std;

int tsp[20];

int main() {
  int T; cin >> T;
  for(int i = tsp[0] = 1; i < 20; i++) tsp[i] = tsp[i - 1] * 26;
  for(int t = 1; t <= T; t++) {
    string S; cin >> S;
    int rpos = S.find('R');
    int cpos = S.find('C');
    if(rpos == 0 && cpos != -1 && isdigit(S[cpos - 1])) {
      int r = atoi(S.substr(1, cpos - 1).c_str());
      int c = atoi(S.substr(cpos + 1).c_str());

      --c;
      int ln = 1;
      for(; c >= tsp[ln]; c -= tsp[ln++]);

      string colname(ln, 0);
      for(int i = 0; i < ln; i++) {
        for(colname[i] = 'A'; c >= tsp[ln - i - 1]; colname[i]++) {
          c -= tsp[ln - i - 1];
        }
      }
      cout << colname << r << endl;
    } else {
      int r = 0;
      int m = 1;
      int ln = S.size();
      while(isdigit(S[ln - 1])) {
        r += m * (S[--ln] - '0');
        m *= 10;
      }
      string colname = S.substr(0, ln);

      int c = 0;
      for(int i = 1; i < ln; i++) c += tsp[i];
      for(int i = 0; i < ln; i++) {
        c += (colname[i] - 'A') * tsp[ln - i - 1];
      }

      cout << 'R' << r << 'C' << c + 1 << endl;
    }
  }
}