#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;


struct PossibleChange {
  int cost, delta_negative, pos;

  friend bool operator<(const PossibleChange &c1, const PossibleChange &c2) {
    if (c1.cost != c2.cost) {
      return c1.cost < c2.cost;
    }

    if (c1.delta_negative != c2.delta_negative) {
      return c1.delta_negative;
    }

    if (c1.delta_negative) {
      return c1.pos < c2.pos;
    } else {
      return c1.pos > c2.pos;
    }
  }
};

pair<int, string> calc(string str, int k, int target) {
  vector<PossibleChange> changes;
  for (int i=0; i<(int)str.size(); ++i) {
    PossibleChange p;
    p.cost = abs(target - str[i]);
    p.delta_negative = target < str[i];
    p.pos = i;
    changes.push_back(p);
  }
  sort(changes.begin(), changes.end());

  int cost = 0;
  for (int i=0; i<k; ++i) {
    cost += changes[i].cost;
    str[changes[i].pos] = target;
  }
  return make_pair(cost, str);
}

int main() {
  cin.sync_with_stdio(0);

  int n, k;
  cin >> n >> k;
  string str;
  cin >> str;

  int best = INT_MAX/2;
  string beststr;
  for (int target='0'; target<='9'; ++target) {
    pair<int, string> now = calc(str, k, target);
    if (now.first < best ||
        now.first == best && now.second < beststr) {
      best = now.first;
      beststr = now.second;
    }
  }
  cout << best << endl << beststr << endl;

  return 0;
}