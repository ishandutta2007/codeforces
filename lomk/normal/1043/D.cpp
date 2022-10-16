/*input
2 2
1 2
2 1


5 6
1 2 3 4 5
2 3 1 4 5
3 4 5 1 2
3 5 4 2 1
2 3 5 4 1
1 2 3 4 5


3 2
1 2 3
2 3 1

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

int n, m;
vector<int> a[11];
int pos[11][100005]; // in vector i,where is number X
deque<pair<int, bool> > dq[11];
int cntW[11];

void add(int X) {
    loop(i, 1, m) {
        if (dq[i].empty() || pos[i][X] > dq[i].back().fi) dq[i].push_back(mp(pos[i][X], 0));
        else {
            dq[i].back().se = 1; cntW[i]++;
            dq[i].push_back(mp(pos[i][X], 0));
        }
    }
}

void del(int X) {
    loop(i, 1, m) {
        cntW[i] -= dq[i].front().se;
        dq[i].pop_front();
    }
}

bool ok() {
    loop(i, 1, m) {
        if (cntW[i]) return false;
        if (dq[i].back().fi - dq[i].front().fi + 1 != dq[i].size()) return false;
    }
    return true;
}

signed main() {
#ifndef UncleGrandpa
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif
    cin >> n >> m;
    loop(i, 1, m) {
        a[i].push_back(-1);
        loop(j, 1, n) {
            int t; cin >> t; a[i].push_back(t);
            pos[i][t] = j;
        }
    }
    int L = 1;
    int ans = 0;
    loop(R, 1, n) {
        add(a[1][R]);
        while (!ok()) {
            del(a[1][L]); L++;
        }
        ans += R - L + 1;
    }
    cout << ans << endl;
}