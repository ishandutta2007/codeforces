#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstdio>

using namespace std;

int main() {
  string S;
  getline(cin, S);

  bool space = false;
  bool quote = false;
  vector<string> A(S[0] == ' ' ? 0 : 1, string());
  for(int i = 0; i < S.size(); i++) {
    if(!quote && S[i] == ' ') {
      space = true;
      continue;
    }
    if(space) {
      A.push_back(string());
    }
    if(S[i] == '\"') {
      quote = !quote;
    } else {
      A.back() += S[i];
    }
    space = false;
  }
  
  for(int i = 0; i < A.size(); i++) {
    cout << '<' << A[i] << '>' << endl;
  }

  return 0;
}