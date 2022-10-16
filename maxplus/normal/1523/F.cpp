#include <algorithm>
#include <iostream>
#include <memory.h>
#include <cmath>

using namespace std;

class Point {
public:
  Point() : x{}, y{} {}

  unsigned operator-(const Point& other) const {
    return std::abs(x - other.x) + std::abs(y - other.y);
  }

  friend istream& operator>>(istream& in, Point& point) {
    return in >> point.x >> point.y;
  }

private:
  int x, y;
};

class Quest: public Point {
public:
  Quest() : Point{}, t{} {}

  unsigned t;
};

bool operator<(const Quest& lhs, const Quest& rhs) {
  return lhs.t < rhs.t;
}

istream& operator>>(istream& in, Quest& quest) {
  return in >> static_cast<Point&>(quest) >> quest.t;
}

constexpr int N = 14, M = 100, MASKS = 1 << N;

Point towers[N];
Quest quests[M];
unsigned dpt[MASKS][M + 1];
unsigned dpq[MASKS][M];
unsigned disttt[MASKS][N];
unsigned disttq[MASKS][M];
unsigned distqt[M][N];
unsigned distqq[M][M];

unsigned& mini(unsigned& lhs, unsigned rhs) {
  return lhs = min(lhs, rhs);
}

unsigned& maxi(unsigned& lhs, unsigned rhs) {
  return lhs = max(lhs, rhs);
}

int main()
{
  memset(dpt, -1, sizeof dpt);
  memset(disttt, -1, sizeof disttt);
  memset(disttq, -1, sizeof disttq);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> towers[i];
    dpt[1 << i][0] = 0;
  }
  for (int i = 0; i < m; ++i) {
    cin >> quests[i];
    dpq[0][i] = 1;
  }
  sort(quests, quests + m);
  unsigned ans = 0;
  int masks = 1 << n;
  for (int mask = 0; mask < masks; ++mask) {
    for (int towerPrev = 0; towerPrev < n; ++towerPrev) if (mask & (1 << towerPrev)) {
      for (int towerNext = 0; towerNext < n; ++towerNext) if (~mask & (1 << towerNext)) {
        mini(disttt[mask][towerNext], towers[towerNext] - towers[towerPrev]);
      }
      for (int questNext = 0; questNext < m; ++questNext) {
        mini(disttq[mask][questNext], quests[questNext] - towers[towerPrev]);
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      distqt[i][j] = towers[j] - quests[i];
    }
    for (int j = 0; j < m; ++j) {
      distqq[i][j] = quests[j] - quests[i];
    }
  }
  for (int mask = 0; mask < masks; ++mask) {
    unsigned qdone_towers = 0, quest = 0;
    while (qdone_towers <= m) {
      bool use_towers = quest == m || dpt[mask][qdone_towers] < quests[quest].t;
      unsigned qdone, t;
      bool skip = 0;
      if (use_towers) {
        qdone = qdone_towers, t = dpt[mask][qdone];
        skip = !mask || t == -1;
      } else {
        qdone = dpq[mask][quest], t = quests[quest].t;
        skip = !qdone;
      }
      if (!skip) {
        mini(dpt[mask][qdone], t);
        maxi(ans, qdone);
        for (int towerNext = 0; towerNext < n; ++towerNext) if (~mask & (1 << towerNext)) {
          mini(dpt[mask | (1 << towerNext)][qdone], t +
              (use_towers? disttt[mask][towerNext]: distqt[quest][towerNext]));
        }
        for (int questNext = quest + !use_towers; questNext < m; ++questNext) if (quests[questNext].t - t >=
            (use_towers? disttq[mask][questNext]: distqq[quest][questNext])) {
          maxi(dpq[mask][questNext], qdone + 1);
        }
      }
      ++(use_towers? qdone_towers: quest);
    }
  }
  cout << ans << '\n';
  return 0;
}