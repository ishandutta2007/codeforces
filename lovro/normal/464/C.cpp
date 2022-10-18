#define NDEBUG
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long int64;
#define MINUSONE(v) memset((v), -1, sizeof (v))
#define ALL(x) (x).begin(), (x).end()

int n;
struct Query { int from; vector<int> to; };
vector<Query> queries;

const int MOD = 1000000007;

struct Chunk {
  int64 val, mag;
};

Chunk concat(Chunk one, Chunk two) {
  one.val *= two.mag;
  one.val += two.val;
  one.mag *= two.mag;
  one.val %= MOD;
  one.mag %= MOD;
  return one;
}

Chunk memo[10][100005];
Chunk calc(int d, int pos) {
  if (pos == n) {
    return Chunk{d, 10};
  }

  if (memo[d][pos].val != -1) {
    return memo[d][pos];
  }
  Chunk ans = {0, 1};
  if (queries[pos].from != d) {
    ans = calc(d, pos+1);
  } else {
    for (int e : queries[pos].to) {
      ans = concat(calc(e, pos+1), ans);
    }
  }
  return memo[d][pos] = ans;
}

int main() {
  ios_base::sync_with_stdio(0);

  string str;
  cin >> str >> n;
  queries.resize(n);
  for (Query &q : queries) {
    string qstr;
    cin >> qstr;
    q.from = qstr[0] - '0';
    for (int j=3; j<(int)qstr.size(); ++j) {
      q.to.push_back(qstr[j] - '0');
    }
    reverse(ALL(q.to));
  }

  MINUSONE(memo);
  Chunk ans = {0, 1};
  for (int i=(int)str.size()-1; i>=0; --i) {
    ans = concat(calc(str[i]-'0', 0), ans);
  }
  cout << ans.val << '\n';
}