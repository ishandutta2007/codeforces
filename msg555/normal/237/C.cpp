#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <cstring>
#include <set>
#include <queue>

using namespace std;

#define MAXP 2010000

bool isp[MAXP];

int main() {
  vector<int> p;
  for(int i = 2; i < MAXP; i++) isp[i] = true;
  for(int i = 2; i < MAXP; i++) {
    if(!isp[i]) continue;
    for(int j = 2 * i; j < MAXP; j += i) isp[j] = false;
    p.push_back(i);
  }
  
  int A, B, K; cin >> A >> B >> K;

  int L = 0;
  int LL = 0x7fffffff;
  for(int i = A; i <= B - L + 1; i++) {
    int pos = lower_bound(p.begin(), p.end(), i) - p.begin() + K - 1;
    if(pos >= p.size()) pos = p.size() - 1;
    L = max(L, p[pos] - i + 1);
    if(i <= B - L) LL = B - i + 1;
  }
  L = min(L, LL);
  cout << (L <= B - A + 1 ? L : -1) << endl;
  return 0;
}