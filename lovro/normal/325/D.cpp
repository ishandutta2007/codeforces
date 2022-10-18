#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

#define repeat(n) for (int repc = (n); repc > 0; --repc)
template<typename T>
inline T modp(const T a, const T b) {
  T result = a % b;
  if (result < 0) {
    result += b;
  }
  return result;
}

class UnionFind {
private:
  class TransactionalVector {
  public:
    TransactionalVector(int n) : v_(n) { }

    void commit() {
      log_.clear();
    }

    void rollback() {
      for (; !log_.empty(); log_.pop_back()) {
        const Mutation &m = log_.back();
        v_[m.index] = m.old_value;
      }
    }

    void set(int index, int value) {
      Mutation m = { index, v_[index] };
      log_.push_back(m);
      v_[index] = value;
    }

    void setNonTransactional(int index, int value) {
      v_[index] = value;
    }

    int operator[](int index) const {
      return v_[index];
    }

  private:
    struct Mutation {
      int index;
      int old_value;
    };

    vector<int> v_;
    vector<Mutation> log_;
  };

public:
  UnionFind(int n) : n(n), dad(n), rank(n) {
    reset();
  }

  void reset() {
    commit();
    for (int i=0; i<n; ++i) {
      dad.setNonTransactional(i, i);
      rank.setNonTransactional(i, 0);
    }
  }

  int find(int a) {
    int top;
    for (top=a; top != dad[top]; top=dad[top]) ;
    while (a != top) { int x = dad[a]; dad.set(a, top); a = x; }
    return top;
  }

  int union_find(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
      if (rank[a] > rank[b]) {
        dad.set(b, a);
        return a;
      } else {
        dad.set(a, b);
        if (rank[a] == rank[b]) {
          rank.set(b, rank[b] + 1);
        }
        return b;
      }
    }
    return -1;
  }

  void commit() {
    dad.commit();
    rank.commit();
  }

  void rollback() {
    dad.rollback();
    rank.rollback();
  }

private:
  int n;
  TransactionalVector dad, rank;
};

int R, C;
int comp[3000][6000];
inline bool inside(int y, int x) {
  return y >= 0 && y < R && x >= 0 && x < 2*C;
}

UnionFind union_find(600010);
int nextcomp = 1;

int add_point(int y, int x) {
  comp[y][x] = nextcomp++;

  for (int dy=-1; dy<=1; ++dy) {
    for (int dx=-1; dx<=1; ++dx) {
      int ny = y+dy, nx = modp(x+dx, 2*C);
      if (inside(ny, nx) && comp[ny][nx]) {
        union_find.union_find(comp[y][x], comp[ny][nx]);
      }
    }
  }

  return comp[y][x];
}

int main() {
  cin.sync_with_stdio(0);

  int N;
  cin >> R >> C >> N;

  int ans = 0;
  repeat (N) {
    int y, x;
    cin >> y >> x;
    --y; --x;

    add_point(y, x);
    add_point(y, x+C);

    if (union_find.find(comp[y][x]) != union_find.find(comp[y][x+C])) {
      ++ans;
      union_find.commit();
    } else {
      union_find.rollback();
      comp[y][x] = 0;
      comp[y][x+C] = 0;
    }
  }
  cout << ans << '\n';
  return 0;
}