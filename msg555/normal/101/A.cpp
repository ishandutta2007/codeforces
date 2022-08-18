#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int num[256];

int main() {
  string S;
  int K;
  cin >> S >> K;

  memset(num, 0, sizeof(num));
  for(int i = 0; i < S.size(); i++) num[S[i]]++;

  vector<pair<int, int> > V;
  for(int i = 0; i < 256; i++) V.push_back(make_pair(num[i], i));
  sort(V.begin(), V.end());

  int i;
  int sm = 0;
  for(i = 0; i < 256 && sm + V[i].first <= K; i++) {
    sm += V[i].first;
    num[V[i].second] = 0;
  }

  cout << 256 - i << endl;
  for(int i = 0; i < S.size(); i++) {
    if(num[S[i]]) {
      cout << S[i];
    }
  }
  cout << endl;
}