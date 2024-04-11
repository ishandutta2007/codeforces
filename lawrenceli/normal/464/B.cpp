#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define px real()
#define py imag()
#define rep(i, n) for (int i=0, _##i=(n); i<_##i; ++i)
#define repi(i, n) for (__typeof((n).begin()) i=(n).begin(), _##i=n.end(); i != _##i; ++i)
#define sz(x) int((x).size())
#define print(x) cerr << #x << ": " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct pnt {
    ll x, y, z;
    pnt() {}
    pnt(ll _x, ll _y, ll _z) : x(_x), y(_y), z(_z) {}
    pnt operator-(pnt p) {
        return pnt(x-p.x, y-p.y, z-p.z);
    }
};

ll dot(pnt p1, pnt p2) { return p1.x*p2.x+p1.y*p2.y+p1.z*p2.z; }
pnt cross(pnt p1, pnt p2) { return pnt(p1.y*p2.z-p1.z*p2.y, p1.z*p2.x-p1.x*p2.z, p1.x*p2.y-p1.y*p2.x); }

inline bool right(pnt p1, pnt p2, pnt p3) { return !dot(p2-p1, p3-p2); }

ll num[10][3];
pnt p[10];
bool in[10];

bool good(int i, int j) {
    if (dot(p[0]-p[i], p[0]-p[i]) != dot(p[0]-p[j], p[0]-p[j])) return 0;
    memset(in, 0, sizeof(in));
    in[0] = in[i] = in[j] = 1;
    int k = -1;
    for (int i1=1; i1<8; i1++)
        if (!in[i1] && !dot(p[0]-p[i1], cross(p[i]-p[0], p[j]-p[i1]))) {
            if (k != -1) return 0;
            k = i1;
        }
    in[k] = 1;
    if (!right(p[0], p[j], p[k])) return 0;
    if (!right(p[j], p[k], p[i])) return 0;

    vector<int> v(4);
    int cnt=0;
    for (int l=1; l<8; l++)
        if (!in[l]) v[cnt++] = l;

    if (dot(p[v[2]]-p[v[0]], cross(p[v[1]]-p[v[0]], p[v[3]]-p[v[2]]))) return 0;
    if (!right(p[v[1]], p[v[0]], p[v[2]]) && !right(p[v[1]], p[v[0]], p[v[3]])) swap(v[1], v[3]);
    else if (!right(p[v[1]], p[v[0]], p[v[2]]) && !right(p[v[2]], p[v[0]], p[v[3]])) swap(v[2], v[3]);

    if (!right(p[v[1]], p[v[0]], p[v[2]])) return 0;
    if (!right(p[v[0]], p[v[1]], p[v[3]])) return 0;
    if (!right(p[v[0]], p[v[2]], p[v[3]])) return 0;
    if (dot(p[v[0]]-p[v[1]], p[v[0]]-p[v[1]]) != dot(p[v[0]]-p[v[2]], p[v[0]]-p[v[2]]) || dot(p[v[0]]-p[v[1]], p[v[0]]-p[v[1]]) != dot(p[0]-p[i], p[0]-p[i]))
        return 0;
    if (!((right(p[i], p[0], p[v[0]]) && right(p[j], p[0], p[v[0]])) ||
          (right(p[0], p[j], p[v[0]]) && right(p[k], p[j], p[v[0]])) ||
          (right(p[i], p[k], p[v[0]]) && right(p[j], p[k], p[v[0]])) ||
          (right(p[0], p[i], p[v[0]]) && right(p[k], p[i], p[v[0]]))))
          return 0;

    return 1;
}

bool check() {
    rep(i, 8)
        p[i] = pnt(num[i][0], num[i][1], num[i][2]);

    rep(i, 8)
        for (int j=i+1; j<8; j++)
            if (p[i].x == p[j].x && p[i].y == p[j].y && p[i].z == p[j].z)
                return 0;

    for (int i=1; i<8; i++)
        for (int j=i+1; j<8; j++)
            if (!dot(p[i]-p[0], p[j]-p[0]))
                if (good(i, j))
                    return 1;
    return 0;
}

void dfs(int cur) {
    if (cur == 8) {
        if (check()) {
            cout << "YES\n";
            rep(i, 8) {
                rep(j, 3)
                    cout << num[i][j] << ' ';
                cout << '\n';
            }
            exit(0);
        }
    } else {
        do dfs(cur+1);
        while (next_permutation(num[cur], num[cur]+3));
    }
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    rep(i, 8) {
        rep(j, 3)
            cin >> num[i][j];
        sort(num[i], num[i]+3);
    }

    dfs(1);
    cout << "NO\n";
    return 0;
}