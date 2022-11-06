#include <bits/stdc++.h>

using namespace std;

template <class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')
    cerr<<*sdbg++;
  cerr<<"="<<h<<","; 
  _dbg(sdbg+1, a...);
}

template<class T> ostream & operator<<(ostream & os, vector<T> V){
  os<<"[";
  for(auto vv: V) os << vv <<",";
  return os << "]";
}
template<class L, class R> ostream & operator <<(ostream & os, pair<L,R> P){
  return os <<"("<<P.st <<","<<P.nd <<")";
}

#ifdef DEBUG
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int N = 200005, BASE = (1 << 19);

int tree[2 * BASE + 5];
int n, fromX[N], toX[N], fromY[N], toY[N];

int query(int posa, int posb) {
    posa += BASE;
    posb += BASE;
    int res = max(tree[posa], tree[posb]);
    while (posa / 2 != posb / 2) {
        if (posa % 2 == 0) {
            res = max(res, tree[posa + 1]);
        }
        if (posb % 2 == 1) {
            res = max(res, tree[posb - 1]);
        }
        posa /= 2;
        posb /= 2;
    }
    return res;
}

void insert(int pos, int w) {
    pos += BASE;
    while (pos >= 1) {
        tree[pos] = max(tree[pos], w);
        pos /= 2;
    }
}

bool check() {
    for (int i = 1; i <= 2 * BASE; i++) {
        tree[i] = 0;
    }
    vector<pair<int, pair<int, int> > > events;
    for (int i = 1; i <= n; i++) {
        events.push_back({fromX[i], {0, i}});
        events.push_back({toX[i], {1, i}});
    }
    sort(events.begin(), events.end());
    set<int> points;
    for (auto event : events) {
        int pos = event.first;
        int type = event.second.first;
        int id = event.second.second;
        if (type == 0) {
            auto it = points.lower_bound(fromY[id]);
            if (it == points.end()) {
                continue;
            }
            if (*it <= toY[id]) {
                return true;
            }
            int res = query(0, fromY[id]);
            if (res >= fromY[id]) {
                return true;
            }
        } else {
            points.insert(fromY[id]);
            points.insert(toY[id]);
            insert(fromY[id], toY[id]);
        }
    }
    
    return false;
}

int main() {
    
    scanf("%d", &n);
    
    vector<pair<int, pair<int, int> > > xs, ys;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d %d", &fromX[i], &toX[i], &fromY[i], &toY[i]);
        xs.push_back({fromX[i], {i, 0}});
        xs.push_back({toX[i], {i, 1}});
        ys.push_back({fromY[i], {i, 0}});
        ys.push_back({toY[i], {i, 1}});
    }
    
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    
    int id = 0;
    for (int i = 0; i < xs.size(); i++) {
        if (i == 0 || xs[i].first != xs[i - 1].first) {
            id++;
        }
        if (xs[i].second.second == 0) {
            fromX[xs[i].second.first] = id;
        } else {
            toX[xs[i].second.first] = id;
        }
    }
    
    id = 0;
    for (int i = 0; i < ys.size(); i++) {
        if (i == 0 || ys[i].first != ys[i - 1].first) {
            id++;
        }
        if (ys[i].second.second == 0) {
            fromY[ys[i].second.first] = id;
        } else {
            toY[ys[i].second.first] = id;
        }
    }
    
    bool c1 = check();
    for (int i = 1; i <= n; i++) {
        fromX[i] = 2 * n - fromX[i];
        toX[i] = 2 * n - toX[i];
        swap(fromX[i], toX[i]);
    }
    c1 |= check();
    
    for (int i = 1; i <= n; i++) {
        swap(fromX[i], toX[i]);
        fromX[i] = 2 * n - fromX[i];
        toX[i] = 2 * n - toX[i];
        swap(fromX[i], fromY[i]);
        swap(toX[i], toY[i]);
    }
    c1 |= check();
    
    for (int i = 1; i <= n; i++) {
        fromX[i] = 2 * n - fromX[i];
        toX[i] = 2 * n - toX[i];
        swap(fromX[i], toX[i]);
    }
    c1 |= check();
    
    printf(c1 ? "NO\n" : "YES\n");
    return 0;
}