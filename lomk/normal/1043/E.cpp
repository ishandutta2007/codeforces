/*input
5 3
-1 3
2 4
1 1
3 5
2 2
1 4
2 3
3 5


3 3
1 2
2 3
1 3
1 2
2 3
1 3


3 2
1 2
2 3
1 3
1 2
2 3
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define __builtin_popcount __builtin_popcountll
#define int long long
#define bit(x,y) ((x>>y)&1LL)
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
const int N = 300005;

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
struct data {
    int a, b, id, cnt;
    data(int _a = 0, int _b = 0, int _cnt = 0): a(_a), b(_b), cnt(_cnt) {};
};

struct BITx {
#define exp exp__
    data tree[N];
    data allTree;
    void update(int i, int a, int b, int exp) {
        int cnt = 1;
        allTree.a += a * exp; allTree.b += b * exp; allTree.cnt += cnt * exp;
        for (; i < N; i += i & -i) {
            tree[i].a += a * exp;
            tree[i].b += b * exp;
            tree[i].cnt += cnt * exp;
        }
        return;
    }
    data get(int i) { // <=i
        data ret;
        for (; i; i -= i & -i) {
            ret.a += tree[i].a;
            ret.b += tree[i].b;
            ret.cnt += tree[i].cnt;
        }
        return ret;
    }
    data revGet(int i) { // >=i
        auto rec = get(i - 1);
        return data(allTree.a - rec.a, allTree.b - rec.b, allTree.cnt - rec.cnt);
    }
} BIT;

int n, m;
data inp[N];
int posInSort[N];
vector<int> g[N];
int ans[N];

int getAnswer(int pos) {

    int ret = 0;
    auto rec = BIT.get(pos - 1);
    ret += rec.a;
    ret += inp[pos].b * rec.cnt;
    // if (pos == 1) {
    //     cout << rec.a << sp << rec.cnt << endl;
    //     exit(0);
    // }
    rec = BIT.revGet(pos + 1);
    ret += rec.b;
    ret += inp[pos].a * rec.cnt;
    return ret;
}

signed main() {
#ifndef UncleGrandpa
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif
    cin >> n >> m;
    loop(i, 1, n) {
        cin >> inp[i].a >> inp[i].b;
        inp[i].id = i;
    }
    sort(inp + 1, inp + n + 1, [&](data X, data Y) {
        if (X.a - X.b != Y.a - Y.b) return X.a - X.b < Y.a - Y.b;
        return X.id < Y.id;
    });
    loop(i, 1, n) {
        posInSort[inp[i].id] = i;
        BIT.update(i, inp[i].a, inp[i].b, 1);
    }
    loop(i, 1, m) {
        int u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }
    loop(i, 1, n) {
        auto modify = [&](int id, int exp) {
            int v = posInSort[id];
            BIT.update(v, inp[v].a, inp[v].b, exp);
            return;
        };
        for (auto v : g[i])
            modify(v, -1);
        ans[i] = getAnswer(posInSort[i]);
        for (auto v : g[i])
            modify(v, 1);
    }
    loop(i, 1, n) cout << ans[i] << sp;
    cout << endl;
}