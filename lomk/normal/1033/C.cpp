/*input
8
3 6 5 4 2 7 1 8


1
1
8
3 6 5 4 2 7 1 8





8
3 6 5 4 2 7 1 8

*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define int long long
#define N 100005
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
vector<int> a;
int dp[N];

int cal(int p) {
    int &ret = dp[p];
    if (ret != -1) return ret;
    for (int d = a[p]; p + d < n; d += a[p]) {
        if (a[p + d] <= a[p]) continue;
        if (cal(p + d) == 0) {
            ret = 1;
            return ret;
        }
    }
    for (int d = a[p]; p - d >= 0; d += a[p]) {
        if (a[p - d] <= a[p]) continue;
        if (cal(p - d) == 0) {
            ret = 1;
            return ret;
        }
    }
    ret = 0;
    return ret;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    loop(i, 1, n) {
        int t; cin >> t;
        a.push_back(t);
    }
    memset(dp, -1, sizeof(dp));
    loop(i, 0, n - 1) {
        if (cal(i) == 0) cout << "B";
        else cout << "A";
    }
}