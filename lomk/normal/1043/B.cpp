/*input
3
1 5 3


5
1 3 5 6 8


5
1 2 3 4 5

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

int n;
vector<int> a;

bool checkCir(int len) {
    assert(len != 0);
    loop(i, 0, len - 1) {
        for (int j = i; j < n; j += len) {
            if (a[j] != a[i]) return false;
        }
    }
    return true;
}

signed main() {
#ifndef UncleGrandpa
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif
    cin >> n;
    int pre = 0;
    loop(i, 1, n) {
        int t; cin >> t;
        a.push_back(t - pre);
        pre = t;
    }
    vector<int> order;
    loop(i, 1, n) {
        if (checkCir(i)) order.push_back(i);
    }
    cout << order.size() << endl;
    for (auto it : order) cout << it << sp;
    cout << endl;
}