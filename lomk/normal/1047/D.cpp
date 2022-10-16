/*input
17 1
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define int long long
#define N
#define bit(x,y) ((x>>y)&1LL)
#define loop(i,l,r) for(int i=l; i<=r; i++)

#define what_is(x) cerr << #x << " is " << x << endl;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
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

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    if (n < m) swap(n, m);
    if (m == 1) {
        int ans = n / 6 * 6;
        n %= 6;
        if (n == 4) ans += 2;
        else if (n == 5) ans += 4;
        cout << ans << endl;
        return 0;
    }
    int ans = 0;
    if (n == 1 || n == 2)
        ans = 0;
    else if (n == 3) {
        if (m == 2) ans = 4;
        else if (m == 3) ans = 8;
    }
    else if (n % 4 == 0) {
        ans = n * m;
    }
    else if (n % 4 == 1) {
        if (m % 2 == 1) ans = n * m - 1;
        else ans = n * m;
    }
    else if (n % 4 == 2) {
        ans = n * m;
    }
    else if (n % 4 == 3) {
        if (n == 7 && m == 2)
            ans = 12;
        else if (m % 2 == 0) ans = n * m;
        else ans = n * m - 1;
    }
    cout << ans << endl;
}