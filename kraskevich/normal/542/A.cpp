#include <bits/stdc++.h>

using namespace std;


struct Event {
    long long x;
    long long r;
    long long data;
    int id;
    int type;

    Event(long long x = 0, long long r = 0, long long data = 0, int id = 0, int type = 0):
        x(x), r(r), id(id), data(data), type(type) {}
    
    bool operator<(const Event& e) const {
        if (x != e.x)
            return x < e.x;
        return type < e.type;
    }
};

const int N = (int) 3e5;
const long long MAX_X = 1000 * 1000 * 1000;

long long l[N];
long long r[N];
long long a[N];
long long b[N];
long long c[N];
int n, m;
long long res = 0;
int resI, resJ;

typedef pair<long long, long long> pll;

void solve1() {
    const int START_ADD = 0;
    const int START_INT = 1;
    const int END_ADD = 2;
    vector<Event> e;
    for (int i = 0; i < n; i++) {
        e.push_back(Event(l[i], r[i], -1, i, START_ADD));
        e.push_back(Event(r[i], r[i], -1, i, END_ADD));   
    }
    for (int i = 0; i < m; i++) {
        e.push_back(Event(a[i], b[i], c[i], i, START_INT));
    }
    sort(e.begin(), e.end());
    set<pll> have;
    for (auto event : e) {
        if (event.type == START_ADD) {
            have.insert(pll(-event.r, event.id));
        } else if (event.type == END_ADD) {
           have.erase(pll(-event.r, event.id));
        } else {
            if (have.size() == 0)
                continue;
            long long r = min(event.r, -have.begin()->first);
            if ((r - event.x) * event.data > res) {
                res = (r - event.x) * event.data;
                resI = have.begin()->second;
                resJ = event.id;            
            }
        }
    }
}

void rev() {
    for (int i = 0; i < n; i++) {
        l[i] *= -1;
        r[i] *= -1;
        swap(l[i], r[i]);
    }
    for (int i = 0; i < m; i++) {
        a[i] *= -1; 
        b[i] *= -1;
        swap(a[i], b[i]);
    }
}

void solve2() {
    rev();
    solve1();
    rev();
}   

struct Tree {
    vector<pll> data;

    Tree(int size) {     
        data.resize(size * 4 + 10);
    }

    pll getMax(int i, int tl, int tr, int l, int r) {
        if (l == tl && r == tr)
            return data[i];
        int m = (tl + tr) / 2;
        pll ml;
        pll mr;
        if (l <= m)
            ml = getMax(2 * i + 1, tl, m, l, min(r, m));
        if (r > m)
            mr = getMax(2 * i + 2, m + 1, tr, max(m + 1, l), r);
        return max(ml, mr);
    }   

    void upd(int i, int tl, int tr, int pos, pll val) {
        data[i] = max(data[i], val);
        if (tl == tr)
            return;
        int m = (tl + tr) / 2;
        if (pos <= m)
            upd(2 * i + 1, tl, m, pos, val);
        else
            upd(2 * i + 2, m + 1, tr, pos, val);    
    }
};

vector<long long> all;

int getPos(long long x) {
    return lower_bound(all.begin(), all.end(), x) - all.begin();
}

void solve3() {
    int START_INT = 0;
    int START_ADD = 1;
    vector<Event> e;
    for (int i = 0; i < n; i++) {
        e.push_back(Event(l[i], r[i], -1, i, START_ADD));   
        all.push_back(r[i]); 
    }    
    for (int i = 0; i < m; i++) {
        e.push_back(Event(a[i], b[i], c[i], i, START_INT));
        all.push_back(b[i]);
    }
    sort(e.begin(), e.end());
    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());
    int tot = all.size();
    Tree tree(tot);
    for (auto event : e)
        if (event.type == START_INT)
            tree.upd(0, 0, tot - 1, getPos(event.r), pll(event.data, event.id));
        else {
            pll best = tree.getMax(0, 0, tot - 1, getPos(event.r), tot - 1);
            if (best.first * (event.r - event.x) > res) {
                res = best.first * (event.r - event.x);
                resI = event.id;
                resJ = best.second;                                 
            }
        }                   
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;  
    for (int i = 0; i < n; i++)
        cin >> l[i] >> r[i];
    for (int i = 0; i < m; i++)
        cin >> a[i] >> b[i] >> c[i];
    solve1();
    solve2();
    solve3();
    cout << res << endl;
    if (res > 0)
        cout << resI + 1 << " " << resJ + 1 << endl;    
    return 0;
}