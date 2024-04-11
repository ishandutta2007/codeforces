#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstdio>

using namespace std;

typedef unsigned int in_addr_t;

in_addr_t inet_addr(const char* s) {
  unsigned int R[4];
  sscanf(s, "%d.%d.%d.%d", R, R + 1, R + 2, R + 3);
  return R[0] << 24 | R[1] << 16 | R[2] << 8 | R[3];
}

string inet_ntoa(in_addr_t addr) {
  char buf[32];
  sprintf(buf, "%d.%d.%d.%d", (addr >> 24) & 0xFFU, (addr >> 16) & 0xFFU,
                              (addr >> 8) & 0xFFU, (addr >> 0) & 0xFFU);
  return buf;
}

int main() {
  int N, K; cin >> N >> K;

  vector<in_addr_t> A;
  for(int i = 0; i < N; i++) {
    string S; cin >> S;
    A.push_back(inet_addr(S.c_str()));
  }

  for(int i = 31; i > 0; i--) {
    in_addr_t msk = 0xFFFFFFFFU & ~((1U << i) - 1);

    set<in_addr_t> nets;
    for(int i = 0; i < A.size(); i++) {
      nets.insert(msk & A[i]);
    }
    if(nets.size() == K) {
      cout << inet_ntoa(msk) << endl;
      return 0;
    }
  }

  cout << "-1" << endl;
  return 0;
}