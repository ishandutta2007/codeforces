/*input
3
RDL
2 1

5
RURUU
-2 3

1
LR
0 0

3
UUU
100 100


4
RULR
1 1



*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define __builtin_popcount __builtin_popcountll
#define bit(x,y) ((x>>y)&1LL)
#define loop(i,l,r) for(int i=(int)(l); i<=(int)(r); i++)
#define rloop(i,l,r) for(int i=(int)(l); i>=(int)(r); i--)

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
pair<int, int> tar;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int cnt[4];

deque<int> dq;

int m2(int x) {
    if (x % 2 == 0) return 0;
    return 1;
}

bool checkDQ(int len) {
    int diffY, diffX;
    diffX = abs(cnt[3] - cnt[2] - tar.fi);
    diffY = abs(cnt[0] - cnt[1] - tar.se);
    if ((diffX + diffY - len) % 2 != 0) return false;
    return (diffX + diffY <= len);
}

bool check(int len) {
    dq.clear();
    memset(cnt, 0, sizeof(cnt));
    for (auto it : a) cnt[it]++;
    loop(i, 0, len - 1) {
        dq.push_back(a[i]);
        cnt[a[i]]--;
    }
    if (checkDQ(len)) return true;
    loop(i, len, n - 1) {
        dq.push_back(a[i]); cnt[a[i]]--;
        while (dq.size() > len) cnt[dq.front()]++, dq.pop_front();
        if (checkDQ(len)) return true;
    }
    return false;
}

signed main() {
#ifndef UncleGrandpa
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif
    cin >> n;
    string s;
    cin >> s;
    for (auto &it : s) {
        if (it == 'U') a.push_back(0);
        else if (it == 'D') a.push_back(1);
        else if (it == 'L') a.push_back(2);
        else if (it == 'R') a.push_back(3);
    }
    cin >> tar.fi >> tar.se;
    memset(cnt, 0, sizeof(cnt));
    for (auto it : a) cnt[it]++;
    if (cnt[0] - cnt[1] == tar.se && cnt[3] - cnt[2] == tar.fi) {
        cout << 0 << endl;
        return 0;
    }
    int l = 0, r = n;
    while (l != r) {
        int mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    if (!check(l)) cout << -1 << endl;
    else cout << l << endl;
}