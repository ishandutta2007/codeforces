#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>

using namespace std;

int main() {
  string A, B;
  int a = 0, b = 0;

  cin >> A >> B;
  for(int i = 0; i < A.size(); i++) {
    if(A[i] == '1') {
      a++;
    }
  }
  for(int i = 0; i < B.size(); i++) {
    if(B[i] == '1') {
      b++;
    }
  }
  if(a & 1) a++;

  cout << (b <= a ? "YES" : "NO") << endl;
  return 0;
}