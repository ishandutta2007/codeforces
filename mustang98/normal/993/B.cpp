#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 15, inf = 1000111222;

vector<pair<int, int> > a, b;
vector<int> other_a;
vector<int> other_b;

int can(pair<int, int> pa, pair<int, int> pb) {
    if (pa.F == pb.F && pa.S != pb.S) return pa.F;
    if (pa.S == pb.S && pa.F != pb.F) return pa.S;
    if (pa.F == pb.S && pa.S != pb.F) return pa.F;
    if (pa.S == pb.F && pa.F != pb.S) return pa.S;
    return 0;
}


int main()
{
    //freopen("input.txt", "r", stdin);
    int la, lb;
    cin >> la >> lb;
    pair<int, int> p;
    for (int i = 0; i < la; ++i) {
        cin >> p.F >> p.S;
        if (p.F > p.S) {
            swap(p.F, p.S);
        }
        a.PB(p);
    }
    for (int i = 0; i < lb; ++i) {
        cin >> p.F >> p.S;
        if (p.F > p.S) {
            swap(p.F, p.S);
        }
        b.PB(p);
    }

    set<int> c;
    for (int i = 0; i < la; ++i) {
        for (int j = 0; j < lb; ++j) {
            int comm = can(a[i], b[j]);
            if (comm != 0) {
                c.insert(comm);
            }
        }
    }
    if (c.size() == 0) {
        exit(228);
    }
    if (c.size() == 1) {
        cout << *c.begin();
        return 0;
    }
    for (int i = 0; i < la; ++i) {
        set<int> c;
        for (int j = 0; j < lb; ++j) {
            int comm = can(a[i], b[j]);
            if (comm != 0) {
                c.insert(comm);
            }
        }
        if (c.size() > 1) {
            cout << -1;
            return 0;
        }
    }
    for (int i = 0; i < lb; ++i) {
        set<int> c;
        for (int j = 0; j < la; ++j) {
            int comm = can(b[i], a[j]);
            if (comm != 0) {
                c.insert(comm);
            }
        }
        if (c.size() > 1) {
            cout << -1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}