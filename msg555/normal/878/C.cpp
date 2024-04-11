#include <iostream>
#include <vector>
#include <set>

#define INF 1000000010

using namespace std;

struct strengths {
  strengths(int K) : K(K), count(0) {
    mns.resize(K, INF);
    mxs.resize(K);
  }

  strengths(const vector<int>& s) : K(s.size()), count(1) {
    mns = s;
    mxs = s;
  }

  void merge(const strengths& x) {
    count += x.count;
    for (int i = 0; i < K; i++) {
      mns[i] = min(mns[i], x.mns[i]);
      mxs[i] = max(mxs[i], x.mxs[i]);
    }
  }

  int K;
  int count;
  vector<int> mns;
  vector<int> mxs;
};

struct strength_container {
  strength_container(strengths* s, int k) : s(s), k(k) {
  }

  bool operator<(const strength_container& x) const {
    return s->mxs[k] > x.s->mxs[k];
  }

  int k;
  strengths* s;
};

set<strength_container> dead[10];

void add_dead(const strengths& s) {
  strengths* sp = new strengths(s);
  for (int i = 0; i < s.K; i++) {
    dead[i].insert(strength_container(sp, i));
  }
}

int main() {
  int N, K;
  cin >> N >> K;

  int result = 0;

  strengths tp(K);
  for (int i = 0; i < N; i++) {
    vector<int> s(K);
    for (int j = 0; j < K; j++) {
      cin >> s[j];
    }

    bool pareto = true;
    for (int j = 0; j < K; j++) {
      if (s[j] < tp.mxs[j]) {
        pareto = false;
        break;
      }
    }
    if (pareto) {
      add_dead(tp);
      tp = strengths(s);
    } else {
      bool ok = false;
      for (int j = 0; j < K; j++) {
        if (s[j] >= tp.mns[j]) {
          ok = true;
          break;
        }
      }
      if (ok) {
        tp.merge(strengths(s));
      } else {
        add_dead(strengths(s));
      }
    }

    bool change = true;
    while (change) {
      change = false;
      for (int i = 0; i < K; i++) {
        if (dead[i].empty()) {
          continue;
        }
        while (!dead[i].empty() && dead[i].begin()->s->mxs[i] > tp.mns[i]) {
          change = true;
          strengths* sp = dead[i].begin()->s;
          tp.merge(*sp);
          for (int j = 0; j < K; j++) {
            dead[j].erase(strength_container(sp, j));
          }
          delete sp;
        }
      }
    }

    cout << tp.count << endl;
    
  }
}