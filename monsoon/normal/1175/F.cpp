#include <cstdio>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPDN(i,n) for(int i=(n)-1;i>=0;--i)
typedef long long ll;
typedef pair<int,int> pii;

const int N = 300100;
int n,a[N];
int last[N];
int cnt[N];
int hisend[N];
deque<int> maxs;
set<pii> cross_set, no_set;
ll ans;

void insert(int i, int end) {
  if (a[i] < end-i) {
    cross_set.insert(make_pair(a[i] - i, i));
  } else {
    hisend[i] = end;
    no_set.insert(make_pair(a[i] - (hisend[i]-i) - i, i));
  }
}

void remove(int i) {
  no_set.erase(make_pair(a[i] - (hisend[i]-i) - i, i));
  cross_set.erase(make_pair(a[i] - i, i));
}

int main() {
  scanf("%d",&n);
  REP(i,n) { scanf("%d",&a[i]); --a[i]; }

  int j = 0;
  REP(i,n) {
    while (j < n && cnt[a[j]] == 0) {
      ++cnt[a[j++]];
    }
    last[i] = j;
    --cnt[a[i]];
  }

  REPDN(i,n) {
    while (!maxs.empty() && a[maxs.front()] <= a[i]) {
      remove(maxs.front());
      maxs.pop_front();
    }
    while (!maxs.empty() && maxs.back() >= last[i]) {
      remove(maxs.back());
      maxs.pop_back();
    }

    if (!maxs.empty() && maxs.back() < last[i]) {
      remove(maxs.back());
      insert(maxs.back(), last[i]);
    }

    int end = last[i];
    if (!maxs.empty()) { end = maxs.front(); }
    maxs.push_front(i);

    while (!no_set.empty() && no_set.begin()->first + i < 0) {
      int I = no_set.begin()->second;
      no_set.erase(no_set.begin());
      cross_set.insert(make_pair(a[I] - I, I));
    }

    while (!cross_set.empty() && cross_set.begin()->first + i < 0) {
      cross_set.erase(cross_set.begin());
    }

    insert(i, end);

    ans += cross_set.size();
  }

  printf("%lld\n", ans);
}