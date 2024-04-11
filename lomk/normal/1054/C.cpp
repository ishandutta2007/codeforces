/*input
3
0 0 0
0 0 0


4
0 0 2 0
1 1 1 1


5
0 0 1 1 2
2 0 1 0 0

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

int n;
int l[1005], r[1005];
int lx[1005], rx[1005];
int a[1005];
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    memset(a, -1, sizeof(a));
    loop(i, 1, n) cin >> l[i], lx[i] = l[i];
    loop(i, 1, n) cin >> r[i], rx[i] = r[i];
    int peak = n;
    loop(i, 1, n) {
        bool con = false;
        loop(j, 1, n) {
            if (a[j] == -1) {
                if (l[j] == 0 && r[j] == 0) {
                    a[j] = peak;
                    con = true;
                }
            }
        }
        if (!con) break;
        int cnt = 0;
        loop(j, 1, n) {
            if (a[j] == peak)cnt++;
            if (a[j] == -1)l[j] -= cnt;
        }
        cnt = 0;
        for (int j = n; j >= 1; j--) {
            if (a[j] == peak) cnt++;
            if (a[j] == -1)r[j] -= cnt;
        }
        peak--;
    }
    loop(i, 1, n) {
        if (a[i] == -1) {
            cout << "NO" << endl;
            return 0;
        }
    }
    loop(i, 1, n) {
        int cnt = 0;
        loop(j, 1, i - 1) {
            if (a[j] > a[i]) cnt++;
        }
        if (cnt != lx[i]) {
            cout << "NO" << endl;
            return 0;
        }
        cnt = 0;
        loop(j, i + 1, n) {
            if (a[j] > a[i]) cnt++;
        }
        if (cnt != rx[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    loop(i, 1, n) cout << a[i] << sp;
    cout << endl;
}