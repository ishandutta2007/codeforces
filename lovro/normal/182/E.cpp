#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long int64;
#define foreach(i,c) for ( typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i )
#define debug(x) cerr << #x << " = " << (x) << endl;
#define MINUSONE(v) memset(v, -1, sizeof v)

const int MOD = 1000000007;

int N;
int64 memo[101][2][3001];
int a[101], b[101];

vector<pair<int, int> > moves[101];

int64 calc(int len, int last, int ori) {
  if (len < 0) {
    return 0;
  }
  if (len == 0) {
    return 1;
  }

  int64 &res = memo[last][ori][len];
  if (res != -1) {
    return res;
  }

  res = 0;
  int last_width = ori == 0 ? a[last] : b[last];
  foreach (it, moves[last_width]) {
    int type = it->first;
    int ori = it->second;
    if (type != last) {
      res += calc(len-last_width, type, !ori);
    }
  }
  res %= MOD;
  return res;
}

int main() {
  cin.sync_with_stdio(0);

  int L;
  cin >> N >> L;

  for (int i=0; i<N; ++i) {
    cin >> a[i] >> b[i];
    if (a[i] > b[i]) {
      swap(a[i], b[i]);
    }
    moves[a[i]].push_back(make_pair(i, 0));
    if (a[i] != b[i]) {
      moves[b[i]].push_back(make_pair(i, 1));
    }
  }

  MINUSONE(memo);
  int64 res = 0;
  for (int i=0; i<N; ++i) {
    res += calc(L-b[i], i, 0);
    if (a[i] != b[i]) {
      res += calc(L-a[i], i, 1);
    }
    res %= MOD;
  }
  cout << res << '\n';

  return 0;
}