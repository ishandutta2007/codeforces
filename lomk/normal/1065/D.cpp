/*input
3
1 9 3
8 6 7
4 2 5
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define N 11
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
const int knight = 0;
const int bishop = 1;
const int rook = 2;

struct data {
    pair<int, int> pos; int type; int need; pair<int, int> val;
    data(pair<int, int> _pos, int _type, int _need, pair<int, int> _val = mp(1e9, 1e9)) {
        pos = _pos; type = _type; need = _need; val = _val;
    }
};

bool operator < (data x, data y) {
    if (x.val.fi != y.val.fi) return x.val.fi > y.val.fi;
    return x.val.se > y.val.se;
}

int n;
int a[N][N];
pair<int, int> root;
pair<int, int> dis[N][N][3][101];

int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

vector<pair<int, int> > getKnight(pair<int, int> pos) {
    vector<pair<int, int> > ret;
    loop(i, 0, 7) {
        int ax = pos.fi + dx[i]; int ay = pos.se + dy[i];
        if (1 <= ax && ax <= n && 1 <= ay && ay <= n) {
            ret.push_back(mp(ax, ay));
        }
    }
    return ret;
}

vector<pair<int, int> > getBishop(pair<int, int> pos) {
    vector<pair<int, int> > ret;
    loop(i, -n, n) {
        int ax = pos.fi + i; int ay = pos.se + i;
        if (1 <= ax && ax <= n && 1 <= ay && ay <= n)
            ret.push_back(mp(ax, ay));
    }
    loop(i, -n, n) {
        int ax = pos.fi + i; int ay = pos.se - i;
        if (1 <= ax && ax <= n && 1 <= ay && ay <= n)
            ret.push_back(mp(ax, ay));
    }
    return ret;
}

vector<pair<int, int> > getRook(pair<int, int> pos) {
    vector<pair<int, int> > ret;
    loop(i, -n, n) {
        int ax = pos.fi + i; int ay = pos.se;
        if (1 <= ax && ax <= n && 1 <= ay && ay <= n)
            ret.push_back(mp(ax, ay));
    }
    loop(i, -n, n) {
        int ax = pos.fi; int ay = pos.se + i;
        if (1 <= ax && ax <= n && 1 <= ay && ay <= n)
            ret.push_back(mp(ax, ay));
    }
    return ret;
}

priority_queue<data> pq;

void upd(data u, pair<int, int> val) {
    auto it = u.pos;
    if (dis[it.fi][it.se][u.type][u.need].fi > val.fi) {
        dis[it.fi][it.se][u.type][u.need] = mp(val.fi, val.se);
        pq.push(data(it, u.type, u.need, dis[it.fi][it.se][u.type][u.need]));
    }
    else if (dis[it.fi][it.se][u.type][u.need].fi == val.fi && dis[it.fi][it.se][u.type][u.need].se > val.se) {
        dis[it.fi][it.se][u.type][u.need] = mp(val.fi, val.se);
        pq.push(data(it, u.type, u.need, dis[it.fi][it.se][u.type][u.need]));
    }
}

pair<int, int> ans = mp(1e9, 1e9);
void bfs() {
    memset(dis, 127, sizeof(dis));
    pq.push(data(root, knight, 1, mp(0, 0))); pq.push(data(root, bishop, 1, mp(0, 0))); pq.push(data(root, rook, 1, mp(0, 0)));
    dis[root.fi][root.se][knight][1] = mp(0, 0); dis[root.fi][root.se][bishop][1] = mp(0, 0); dis[root.fi][root.se][rook][1] = mp(0, 0);
    while (!pq.empty()) {
        auto u = pq.top(); pq.pop();
        if (dis[u.pos.fi][u.pos.se][u.type][u.need] != u.val) continue;
        // if at the same pos as need, ++need
        if (a[u.pos.fi][u.pos.se] == u.need) {
            if (u.need == n * n) {
                ans = min(ans, u.val);
                continue;
            }
            upd(data(u.pos, u.type, u.need + 1), u.val);
        }
        // travel
        vector<pair<int, int> > rec;
        if (u.type == knight) rec = getKnight(u.pos);
        else if (u.type == bishop) rec = getBishop(u.pos);
        else rec = getRook(u.pos);
        for (auto it : rec)
            upd(data(it, u.type, u.need), mp(u.val.fi + 1, u.val.se));
        // change type
        loop(i, 0, 2) {
            upd(data(u.pos, i, u.need), mp(u.val.fi + 1, u.val.se + 1));
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    loop(i, 1, n) {
        loop(j, 1, n) {
            cin >> a[i][j];
            if (a[i][j] == 1) root = mp(i, j);
        }
    }
    bfs();
    cout << ans.fi << sp << ans.se << endl;
    // cout << dis[1][1][0][3] << endl;
}