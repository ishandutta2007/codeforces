#include<bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define forn(i, n) fore(i, 0, n)

#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define x first
#define y second

typedef long long li;
typedef pair<int, int> pt;

const int INF = int(1e9) + 7;
const li INF64 = li(1e18) + 7;

const int N = 500005;
const int A = 27;
const int MAG = 500;

struct node {
    node *to[A];
    int cnt;
} nodes[N];
int szn = 0;

typedef node* vt;

vt getNode() {
    assert(szn < N);
    fore(i, 0, A)
        nodes[szn].to[i] = NULL;
    nodes[szn].cnt = 0;
    return &nodes[szn++];
}

void addWord(vt v, const string &s) {
    fore(i, 0, sz(s)) {
        int c = s[i] - 'a';
        if (!v->to[c])
            v->to[c] = getNode();
        v = v->to[c];
    }
    v->cnt++;
}

int calcCnt(vt v, const string &s, int pos) {
    assert(v->cnt == 0);
    int ans = 0;
    while(pos < sz(s)) {
        int c = s[pos] - 'a';
        if (!v->to[c])
            break;
        v = v->to[c];
        ans += v->cnt;
        pos++;
    }
    return ans;
}

vector<int> zf(string s) {
    vector<int> z(sz(s), 0);
    for (int i = 1, l = 0, r = 0; i < sz(s); ++i) {
        if(i < r)
            z[i] = min(r - i, z[i - l]);
        while (i + z[i] < sz(s) && s[i + z[i]] == s[z[i]])
            z[i]++;

        if(i + z[i] > r)
            l = i, r = i + z[i];
    }
    return z;
}

string t;
int n;
vector<string> s;

inline bool read() {
    if(!(cin >> t))
        return false;
    cin >> n;
    s.resize(n);
    fore(i, 0, n)
        cin >> s[i];
    return true;
}

inline void solve() {
    vector<int> cnt[2];
    fore(k, 0, 2) {
        cnt[k].assign(sz(t) + 1, 0);
        szn = 0;
        vt root = getNode();

        forn(i, n) {
            if (sz(s[i]) > MAG) {
                auto z = zf(s[i] + t);
                fore(j, 0, sz(t))
                    cnt[k][j] += (z[sz(s[i]) + j] >= sz(s[i]));
            } else {
                addWord(root, s[i]);
            }
        }

        fore(i, 0, sz(t))
            cnt[k][i] += calcCnt(root, t, i);

        reverse(all(t));
        fore(i, 0, n)
            reverse(all(s[i]));
    }

    li ans = 0;
    fore(i, 0, sz(t) + 1)
        ans += cnt[0][i] * 1ll * cnt[1][sz(t) - i];
    cout << ans << endl;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    int tt = clock();
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cerr << fixed << setprecision(15);

    if(read()) {
        solve();

#ifdef _DEBUG
        cerr << "TIME = " << clock() - tt << endl;
        tt = clock();
#endif
    }
    return 0;
}