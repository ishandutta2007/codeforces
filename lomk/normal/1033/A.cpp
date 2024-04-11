/*input
8
3 5
1 2
6 1


8
4 4
2 3
1 6


8
4 4
1 3
3 1
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define int long long
#define N 1005
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
int qX, qY;
bool mark[N][N];
bool visited[N][N];
int sx, sy, tx, ty;

int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> qX >> qY;
    loop(i, 1, n) mark[qX][i] = mark[i][qY] = true;
    loop(i, -n, n) {
        if (qX + i >= 1 && qY + i >= 1 && qX + i <= n && qY + i <= n)
            mark[qX + i][qY + i] = true;
    }
    loop(i, -n, n) {
        if (qX + i >= 1 && qY - i >= 1 && qX + i <= n && qY - i <= n)
            mark[qX + i][qY - i] = true;
    }
    queue<pair<int, int> > q;
    cin >> sx >> sy >> tx >> ty;
    visited[sx][sy] = true;
    q.push(mp(sx, sy));
    while (!q.empty()) {
        int x = q.front().fi; int y = q.front().se;
        q.pop();
        loop(i, 0, 7) {
            int ax = x + dx[i];
            int ay = y + dy[i];
            if (1 <= ax && ax <= n && 1 <= ay && ay <= n && !mark[ax][ay] && !visited[ax][ay]) {
                visited[ax][ay] = true;
                q.push(mp(ax, ay));
            }
        }
    }
    if (visited[tx][ty]) cout << "YES" << endl;
    else cout << "NO" << endl;
}