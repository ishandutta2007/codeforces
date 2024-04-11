#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <cstdio>

#include <unistd.h>

using namespace std;

string canon(string S) {
  S = string("0") + S;
  for(int i = 1; i + 1 < S.size(); i++) {
    for(int j = i; j > 0 && S[j] == '1' && S[j + 1] == '1'; j -= 2) {
      S[j] = '0';
      S[j + 1] = '0';
      S[j - 1] = '1';
    }
  }
  int ln = 0;
  while(ln < S.size() && S[ln] == '0') {
    ln++;
  }
  return S.substr(ln);
}

int main() {
  for (int i = 3; i < 1024; i++) {
    if (close(i) != -1) {
      printf("FD: %d\n", i);
    }
  }

  string A, B;
  cin >> A >> B;
/*
  A = string(100000, '1');
  B = string(100000, '1');
*/
  A = canon(A);
  B = canon(B);

//cout << A << ", " << B << endl;
  int c = 0;
  if(A.size() < B.size()) {
    c = -1;
  } else if(B.size() < A.size()) {
    c = 1;
  } else if(A < B) {
    c = -1;
  } else if(B < A) {
    c = 1;
  }

  if(c < 0) {
    cout << "<\n";
  } else if(c == 0) {
    cout << "=\n";
  } else {
    cout << ">\n";
  }
  return 0;
}