#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>

using namespace std;


int main() {
  int k, n1, n2, n3, t1, t2, t3;
  cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;

  priority_queue<pair<int, int> > q;

  int tm = 0;
  int cnt[3] = {n1, n2, n3};
  for(int i = 0; i < k; i++) {
    while(!cnt[0] || !cnt[1] || !cnt[2]) {
      tm = -q.top().first;
      cnt[q.top().second]++;
      q.pop();
    }
    cnt[0]--;
    cnt[1]--;
    cnt[2]--;
    q.push(make_pair(-(tm + t1), 0));
    q.push(make_pair(-(tm + t2), 1));
    q.push(make_pair(-(tm + t3), 2));
  }
  cout << tm + t1 + t2 + t3 << '\n';

  return 0;
}