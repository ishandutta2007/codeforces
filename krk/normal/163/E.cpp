#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Maxm = 5242880;
const int K = 26;


struct node {
    int L, R, cnt;
    node(): L(0), R(0), cnt(0) {}
};

char tmp[Maxm];
int n, k;
string nam[Maxn];
vector <int> my[Maxn];
int qid[Maxn];
string qstring[Maxn];
node st[Maxm];
int slen;

int newNode() { return slen++; }

void Read(string &s)
{
    scanf("%s", tmp); s = tmp;
}

void Add(int &v, int oldv, int l, int r, int a, int b)
{
    v = newNode();
    st[v].L = st[oldv].L;
    st[v].R = st[oldv].R;
    st[v].cnt = st[oldv].cnt;
    if (l == a && r == b) st[v].cnt++;
    else {
        int m = l + r >> 1;
        if (a <= m) Add(st[v].L, st[oldv].L, l, m, a, min(m, b));
        else st[v].L = st[oldv].L;
        if (m + 1 <= b) Add(st[v].R, st[oldv].R, m + 1, r, max(m + 1, a), b);
        else st[v].R = st[oldv].R;
    }
}

int Get(int v, int l, int r, int x)
{
    if (v == 0) return 0;
    int res = st[v].cnt;
    if (l < r) {
        int m = l + r >> 1;
        if (x <= m) res += Get(st[v].L, l, m, x);
        else res += Get(st[v].R, m + 1, r, x);
    }
    return res;
}

struct Vertex {
    map <char, int> next;
    map <char, int> go;
    int leaf = 0;
    int p = -1;
    char pch;
    int link = -1;
    int ent = -1;

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {}
};

vector<Vertex> t(1);

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int get_entry(int v)
{
    if (t[v].ent == -1)
        if (v == 0) t[v].ent = 0;
        else {
            t[v].ent = get_entry(get_link(v));
            if (t[v].leaf) {
                int ind = t[v].leaf;
                for (int i = 0; i < my[ind].size(); i += 2)
                    if (my[ind][i] + 1 < my[ind][i + 1])
                        Add(t[v].ent, t[v].ent, 1, n, my[ind][i] + 1, my[ind][i + 1] - 1);
            }
        }
    return t[v].ent;
}

int go(int v, char ch) {
    auto it = t[v].go.find(ch);
    if (it == t[v].go.end()) {
        auto nit = t[v].next.find(ch);
        if (nit != t[v].next.end()) {
            t[v].go.insert(*nit);
            return nit->second;
        } else {
            int val = v == 0? 0: go(get_link(v), ch);
            t[v].go.insert(make_pair(ch, val));
            return val;
        }
    }
    return it->second;
}

void add_string(int ind) {
    int v = 0;
    for (char ch : nam[ind]) {
        auto it = t[v].next.find(ch);
        if (it == t[v].next.end()) {
            int ind = t.size();
            t[v].next.insert(make_pair(ch, ind));
            t.emplace_back(v, ch);
            v = ind;
        } else v = it->second;
    }
    t[v].leaf = ind;
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= k; i++) {
        Read(nam[i]);
        my[i].push_back(0);
    }
    for (int i = 1; i <= n; i++) {
        char op; scanf(" %c", &op);
        if (op == '+') {
            int id; scanf("%d", &id);
            if (my[id].size() % 2 == 0)
                my[id].push_back(i);
        } else if (op == '-') {
            int id; scanf("%d", &id);
            if (my[id].size() % 2 != 0)
                my[id].push_back(i);
        } else {
            qid[i] = i;
            Read(qstring[i]);
        }
    }
    newNode();
    for (int i = 1; i <= k; i++) {
        if (my[i].size() % 2 != 0)
            my[i].push_back(n + 1);
        add_string(i);
    }
    for (int i = 1; i <= n; i++) if (qid[i]) {
        int cur = 0;
        ll res = 0;
        for (int j = 0; j < qstring[i].size(); j++) {
            cur = go(cur, qstring[i][j]);
            res += Get(get_entry(cur), 1, n, i);
        }
        printf("%I64d\n", res);
    }
    return 0;
}