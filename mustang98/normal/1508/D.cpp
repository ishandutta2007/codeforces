#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 2011, inf = 1000111222;

struct point {
    ll x, y;
    int mark, ind;
};

point p[max_n];

inline int quad (point p) {
  if (p.x < 0 && p.y < 0) return 0;
  if (p.x >= 0 && p.y < 0) return 1;
  if (p.x >= 0 && p.y >= 0) return 2;
  if (p.x < 0 && p.y >= 0) return 3;
  assert(69 == 420);
}

vector<int> gv[max_n];

int g[max_n];
set<pair<int, int>> ss;

void ins(int a, int b) {
    if (a == b) {
        exit(228);
    }
    if (ss.count(MP(a, b)) || ss.count(MP(b, a))) {
        exit(1);
    }
    ss.insert(MP(a, b));
    ss.insert(MP(b, a));
}


int main()
{
  //  freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int bad = -1;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y >> p[i].mark;
        p[i].ind = i;
        --p[i].mark;
        if (p[i].mark == i) {
            continue;
        }
        if (p[i].x < p[bad].x || p[i].x == p[bad].x && p[i].y < p[bad].y) {
            bad = i;
        }
    }
    if (bad == -1) {
        cout << 0 << endl;
        return 0;
    }
    point cent = p[bad];
    for (int i = 0; i < n; ++i) {
        p[i].x -= cent.x;
        p[i].y -= cent.y;
    }

    vector<int> v;
    for (int i = 0; i < n; ++i) {
        if (i == p[i].mark || i == bad) continue;
        v.PB(i);
    }

    sort(v.begin(), v.end(), [] (int ia, int ib) {
      point a = p[ia];;
      point b = p[ib];
      return quad(a) == quad(b) ? a.x * b.y > a.y * b.x : quad(a) < quad(b);
    });

    for (int i = 0; i < n; ++i) {
        g[i] = -1;
    }
    int col = -1;
    for (int i = 0; i < n; ++i) {
        if (g[i] != -1) {
            continue;
        }
        ++col;
        int st = i;
        int cur = p[i].mark;
        g[st] = col;
        gv[col].PB(st);
        while (cur != st) {
            g[cur] = col;
            gv[col].PB(cur);
            cur = p[cur].mark;
        }
    }

    int si = -1;

    for (int i = 0; i < v.size(); ++i) {
        int ind = v[i];
        if (g[ind] == g[bad]) {
            si = i;
            break;
        }
    }
    if (si == -1) {
        exit(228);
    }
    int mnc = g[bad];
    vector<pair<int, int>> ans;
    for (int i = si; i + 1 < v.size(); ++i) {
        int cur = v[i];
        int nxt = v[i + 1];
        if (g[cur] == g[nxt]) {
            continue;
        }
        ans.emplace_back(cur, nxt);
        ins(cur, nxt);

        swap(p[cur].mark, p[nxt].mark);
        int other = g[nxt];
        while (!gv[other].empty()) {
            int ind = gv[other].back();
            g[ind] = mnc;
            gv[mnc].push_back(ind);
            gv[other].pop_back();
        }
    }
    for (int i = si; i - 1 >= 0; --i) {
        int cur = v[i];
        int nxt = v[i - 1];
        if (g[cur] == g[nxt]) {
            continue;
        }
        ans.emplace_back(cur, nxt);
        ins(cur, nxt);

        swap(p[cur].mark, p[nxt].mark);
        int other = g[nxt];
        while (!gv[other].empty()) {
            int ind = gv[other].back();
            g[ind] = mnc;
            gv[mnc].push_back(ind);
            gv[other].pop_back();
        }
    }
    while (p[bad].mark != bad) {
        int to = p[bad].mark;
        ans.emplace_back(bad, to);
        ins(bad, to);
        swap(p[to].mark, p[bad].mark);
    }
    for (int i = 0; i < n; ++i) {
        if (p[i].ind != p[i].mark) {
            exit(228);
        }
    }
    cout << ans.size() << endl;
    for (pair<int, int> p : ans) {
        printf("%d %d\n", p.F + 1, p.S + 1);
    }
    return 0;
}