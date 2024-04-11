#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> point;

const int max_n = 2011, inf = 1000111222;

vector<point> pt;
string s;
int n;
vector<int> res;
bool vis[max_n];

// >0 left, <0 right
ll sq(point a, point b, point c) {
    return (b.F - a.F) * (c.S - a.S) - (c.F - a.F) * (b.S - a.S);
}

int get_leftmost(point a) {
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        if (vis[i]) continue;
        if (ans == -1) {
            ans = i;
            continue;
        }
        if (sq(a, pt[ans], pt[i]) > 0) {
            ans = i;
        }
    }
    return ans;
}

int get_rightmost(point a) {
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        if (vis[i]) continue;
        if (ans == -1) {
            ans = i;
            continue;
        }
        if (sq(a, pt[ans], pt[i]) < 0) {
            ans = i;
        }
    }
    return ans;
}

int main()
{
    //cout << sq(MP(0, 0), MP(0, 10), MP(1, 5)) << endl;
    //freopen("input.txt", "r", stdin);
    cin >> n;
    int ci;
    point mn = MP(inf, inf);
    for (int i = 0; i < n; ++i) {
        point p;
        cin >> p.F >> p.S;
        pt.PB(p);
        if (p < mn) {
            ci = i;
            mn = p;
        }
    }
    cin >> s;
    s += 'R';
    point cur = pt[ci];
    vis[ci] = 1;
    res.PB(ci);
    for (int i = 0; i < s.size(); ++i) {
        int nxt;
        if (s[i] == 'L') {
            nxt = get_rightmost(cur);
        } else {
            nxt = get_leftmost(cur);
        }
        res.PB(nxt);
        cur = pt[nxt];
        ci = nxt;
        vis[nxt] = 1;
    }
    for (int a : res) {
        cout << a + 1 << ' ';
    }
    return 0;
}

// think 47 min