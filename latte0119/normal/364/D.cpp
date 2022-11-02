#include <bits/stdc++.h>

using namespace std;


using int64 = long long;

int N;
int64 A[1000000];

int main()
{
  std::mt19937 mt((unsigned) time(NULL)+13333);
  scanf("%d", &N);
  std::uniform_int_distribution<> randN(0, N - 1);
  for(int i = 0; i < N; i++) {
    scanf("%lld", &A[i]);
  }

  int64 all = 1;
  for(int loop = 0; loop < 13; loop++) {
    int p = randN(mt);
    vector< int64 > gcds(N);
    for(int i = 0; i < N; i++) gcds[i] = __gcd(A[i], A[p]);
    sort(begin(gcds), end(gcds));
    vector< pair< int64, int > > times;
    for(auto &s : gcds) {
      if(times.empty() || times.back().first != s) {
        times.emplace_back(s, 1);
      }  else {
        times.back().second++;
      }
    }

    for(int i = (int) times.size() - 1; i >= 0; i--) {
      if(times[i].first <= all) {
        break;
      }
      int ret = 0;
      for(int j = i; j < times.size(); j++) {
        if(times[j].first % times[i].first == 0) ret += times[j].second;
      }
      if(ret * 2 >= N) {
        all = times[i].first;
        break;
      }
    }
  }

  printf("%lld\n", all);
}