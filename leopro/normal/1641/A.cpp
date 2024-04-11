/*






























*/

#include <bits/stdc++.h>

using namespace std;

#define MULTITEST

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template <class A, class B> ostream& operator << (ostream& out, const pair<A, B> &a) {
    return out << "(" << a.x << ", " << a.y << ")";
}

template <class A> ostream& operator << (ostream& out, const vector<A> &v) {
    out << "[";
    forn(i, sz(v)) {
        if(i) out << ", ";
        out << v[i];
    }
    return out << "]";
}

mt19937 rnd(time(NULL));

const int INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = int(1e9) + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 200 * 1000 + 13;

int n, x;
int a[N];

bool read () {
    if (scanf("%d%d", &n, &x) != 2)
        return false;
    forn(i, n)
        scanf("%d", &a[i]);
    return true;
}

struct Int {
    int value;

    Int(int value) : value(value) {}

    bool operator<(const Int &other) const { return value < other.value; }

    operator int() const { return value; }
};

void solve() {
    vector<pt> sv;
    forn(i, n){
        int cnt = 0;
        while (a[i] % x == 0){
            ++cnt;
            a[i] /= x;
        }
        sv.pb(mp(a[i], cnt));
    }
    sort(all(sv));
    int ans = 0;
    forn(i, n){
        int j = i - 1;
        multiset<Int> cur;
        while (j + 1 < n && sv[j + 1].x == sv[i].x){
            ++j;
            cur.insert(sv[j].y);
        }
        while (!cur.empty()){
            int x = *cur.begin();
            cur.erase(cur.begin());
            if (cur.count(x + 1))
                cur.erase(cur.find(x + 1));
            else
                ++ans;
        }
        i = j;
    }
    printf("%d\n", ans);
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int tt = clock();

#endif

    cerr.precision(15);
    cout.precision(15);
    cerr << fixed;
    cout << fixed;

#ifdef MULTITEST
    int tc;
    scanf("%d", &tc);
    while(tc--){
        read();
#else
        while(read()) {
#endif
        solve();

#ifdef _DEBUG
        cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

    }
}