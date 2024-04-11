#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define repeat(n) for ( int repc = (n); repc > 0; --repc )
typedef long long int64;
#define foreach(i,c) for ( typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i )

enum Type { START, END, MUSHROOM };

struct Event {
  int64 when;
  Type type;
  union {
    int p;
    int magic;
  } data;

  friend bool operator<(const Event &e1, const Event &e2) {
    return e1.when < e2.when;
  }
};

void add_interval(vector<Event> &events, int64 x1, int64 x2, int p) {
  Event e;
  e.data.p = p;
  e.when = x1;
  e.type = START;
  events.push_back(e);
  e.when = x2;
  e.type = END;
  events.push_back(e);
}

int main() {
  cin.sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<Event> events;
  
  repeat (n) {
    int64 x, h;
    int pleft, pright;
    cin >> x >> h >> pleft >> pright;

    add_interval(events, 2*(x-h) - 1, 2*x-1, 100 - pleft);
    add_interval(events, 2*x + 1, 2*(x+h) + 1, 100 - pright);
  }

  repeat (m) {
    int64 x; int b;
    cin >> x >> b;
    
    Event e;
    e.when = 2*x;
    e.type = MUSHROOM;
    e.data.magic = b;
    events.push_back(e);
  }

  sort(events.begin(), events.end());

  vector<int> cnt(101);
  double result = 0;
  foreach (it, events) {
    int p = it->data.p;
    if (it->type == START) {
      ++cnt[p];
    } else if (it->type == END) {
      --cnt[p];
    } else {
      double prob = 1.0;
      for (int i=0; i<=100; ++i) {
        if (cnt[i] > 0) {
          prob *= pow(0.01 * i, cnt[i]);
        }
      }
      result += prob * it->data.magic;
    }
  }

  printf("%.6f\n", result);

  return 0;
}