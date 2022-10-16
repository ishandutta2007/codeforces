/*input
4 16
abcd
bcde
bcad
bcde

7 6
ypnxnnp
pnxonpm
nxanpou
xnnpmud
nhtdudu
npmuduh
pmutsnz


5 3
bwwwz
hrhdh
sepsp
sqfaf
ajbvw



*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define __builtin_popcount __builtin_popcountll
#define N
#define bit(x,y) ((x>>y)&1LL)
#define loop(i,l,r) for(int i=(int)(l); i<=(int)(r); i++)

void read(int &number) {
    bool negative = false;
    int c;
    number = 0;
    c = getchar();
    while (c == ' ' || c == '\n')
        c = getchar();
    if (c == '-') {
        negative = true;
        c = getchar();
    }
    for (; (c > 47 && c < 58); c = getchar())
        number = number * 10 + c - 48;
    if (negative)
        number = -number;
}

template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &a) {
    return os << '(' << a.first << ", " << a.second << ')';
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &a) {
    os << '[';
    for (unsigned int i = 0; i < a.size(); i++)
        os << a[i] << (i < a.size() - 1 ? ", " : "");
    os << ']';
    return os;
}
template <class T>
ostream &operator<<(ostream &os, const set<T> &a) {
    os << '{';
    for (typename set<T>::iterator it = a.begin(); it != a.end(); it++) {
        typename set<T>::iterator jt = it;
        os << *it << (++jt != a.end() ? ", " : "");
    }
    os << '}';
    return os;
}
template <class T1, class T2>
ostream &operator<<(ostream &os, map<T1, T2> &a) {
    os << "{\n";
    for (typename map<T1, T2>::iterator it = a.begin(); it != a.end(); it++) {
        typename map<T1, T2>::iterator jt = it;
        os << "  " << it->first << ": " << it->second << (++jt != a.end() ? ",\n" : "\n");
    }
    os << '}';
    return os;
}
int n, k;
int a[2005][2005];
int ma[2005][2005];
int dx[] = {0, 1};
int dy[] = {1, 0};
int mxDis = 0;

void preBfs() {
    memset(ma, -127, sizeof(ma));
    priority_queue<pair<int, pair<int, int> > >pq;
    ma[1][1] = k; if (a[1][1] != 1) ma[1][1]--;
    pq.push({ma[1][1], {1, 1}});
    while (!pq.empty()) {
        int x = pq.top().se.fi; int y = pq.top().se.se; int d = pq.top().fi; pq.pop();
        mxDis = max(mxDis, x + y);
        if (ma[x][y] == -1 || d != ma[x][y]) continue;
        loop(i, 0, 1) {
            int ax = x + dx[i]; int ay = y + dy[i];
            if (min(ax, ay) >= 1 && max(ax, ay) <= n) {
                int curD = ma[x][y];
                if (a[ax][ay] != 1) curD--;
                if (ma[ax][ay] < curD) {
                    ma[ax][ay] = curD;
                    pq.push({ma[ax][ay], {ax, ay}});
                }
            }
        }
    }
}

void bfs() {
    vector < pair<int, pair<int, int> > > v;
    loop(i, 1, n) {
        loop(j, 1, n) {
            if (ma[i][j] != -1) continue;
            if (i + j != mxDis) continue;
            v.push_back({a[i][j], {i, j}});
        }
    }
    vector<int> ret;
    while (true) {
        if (v.empty()) break;
        sort(v.begin(), v.end()); v.resize(distance(v.begin(), unique(v.begin(), v.end())));
        int mn = v[0].fi;
        while (v.back().fi > mn) v.pop_back();
        ret.push_back(a[v[0].se.fi][v[0].se.se]);
        if (v[0].se.fi == n && v[0].se.se == n) 
            break;
        vector < pair<int, pair<int, int> > > nxt;
        for (auto it : v) {
            int x = it.se.fi; int y = it.se.se;
            loop(i, 0, 1) {
                int ax = x + dx[i]; int ay = y + dy[i];
                if (min(ax, ay) >= 1 && max(ax, ay) <= n)
                    nxt.push_back({a[ax][ay], {ax, ay}});
            }
        }
        v.swap(nxt);
    }
    loop(i, 1, 2 * n - 1 - ret.size()) cout << 'a';
    for (auto it : ret) cout << char(it + 'a' - 1);
    cout << endl;
    // cout << ret << endl;
}

signed main() {
#ifndef UncleGrandpa
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif
    cin >> n >> k;
    loop(i, 1, n) {
        loop(j, 1, n) {
            char c; cin >> c;
            a[i][j] = c - 'a' + 1;
        }
    }
    preBfs();
    bfs();
}