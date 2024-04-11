/*input
0 0
10 4
2 1
10 5
50 16
3 3

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
#define N
#define bit(x,y) ((x>>y)&1LL)
#define loop(i,l,r) for(int i=(int)(l); i<=(int)(r); i++)

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

bool mark[1000005];
int oriA, oriB;
int A, B;
vector<int> allA, allB;
int all = -1;

void makeA() {
    loop(i, 1, all) {
        if (A - i >= 0) {
            A -= i;
            allA.push_back(i);
        }
        else break;
    }
    reverse(allA.begin(), allA.end());
    int lim = all;
    for (auto &it : allA) {
        int d = min(A, lim - it);
        A -= d; it += d;
        lim--;
        if (A == 0) break;
    }
}

void makeB() {
    for (auto it : allA) mark[it] = true;
    loop(i, 1, all) if (!mark[i]) allB.push_back(i);
    assert(allA.size() + allB.size() == all);
    int x = 0; for (auto it : allA) x += it;
    assert(x <= oriA);
    x = 0; for (auto it : allB) x += it;
    assert(x <= oriB);
}

signed main() {
#ifndef UncleGrandpa
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif
    cin >> A >> B;
    oriA = A; oriB = B;
    int sum = A + B;
    if (sum == 0) {
        cout << 0 << endl;
        cout << endl;
        cout << 0 << endl;
        cout << endl;
        exit(0);
    }
    for (int i = 100000; i >= 1; i--) {
        if (i * (i + 1) / 2 <= sum) {
            all = i;
            break;
        }
    }
    makeA(); makeB();
    cout << allA.size() << endl;
    for (auto it : allA) cout << it << sp;
    cout << endl;
    cout << allB.size() << endl;
    for (auto it : allB) cout << it << sp;
    cout << endl;
}