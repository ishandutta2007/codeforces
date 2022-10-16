#include <bits/stdc++.h>

using namespace std;

const int maxn = 200010;

int arr[maxn], n, k;
char cc[maxn];
vector<int> rr[3];

int main() {
  scanf("%d%d", &n, &k);
  if (k == 1) {
    printf("-1\n");
    return 0;
  }
  for (int i = 0; i < n; i++) scanf("%d", arr + i);
  scanf("%s", &cc);

  long long r = 0, o = 0, w = 0;
  for (int i = 0; i < n; i++) {
    if (cc[i] == 'R') rr[0].push_back(arr[i]);
    else if (cc[i] == 'W') rr[1].push_back(arr[i]);
    else rr[2].push_back(arr[i]);
  }
  for (int i = 0; i < 3; i++) {
    sort(rr[i].begin(), rr[i].end());
  }
  long long ans = -1;
  for (int i = 0; i < 2; i++) {
    if (rr[i].size()+rr[2].size() < k) continue;
    if (rr[i].size() == 0 || rr[2].size() == 0) continue;
    int id1 = (int)(rr[i].size())-2;
    int id2 = (int)(rr[2].size())-2;
    long long cur = rr[i][id1+1] + rr[2][id2+1];
    for (int j = 0; j < k-2; j++) {
        if (id1 < 0) cur += rr[2][id2--];
        else if (id2 < 0) cur += rr[i][id1--];
        else if (rr[i][id1] > rr[2][id2]) cur += rr[i][id1--];
        else cur += rr[2][id2--];
    }
    ans = max(ans, cur);

  }
  printf("%I64d\n", ans);

}