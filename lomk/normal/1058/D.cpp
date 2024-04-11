/*input
4 3 3

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

#define X fi
#define Y se
int gcd(int a , int b) {
    if (b == 0) return a;
    a %= b;
    return gcd(b, a);
}

int n, m, k;
int orin, orim;
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    orin = n; orim = m;
    n *= 2;
    int t = gcd(n, k);
    n /= t; k /= t;
    t = gcd(m, k);
    m /= t; k /= t;
    if (k != 1) {
        cout << "NO" << endl;
        return 0;
    }
    if (n > orin) {
        for (int i = 2; i <= sqrt(n) + 5; i++) {
            if (n % i == 0) {
                if (m * i > orim) break;
                n /= i; m *= i;
                break;
            }
        }
    }
    if (n > orin || m > orim) {
        cout << "NO" << endl;
        return 0;
    }
    auto A = mp(0, 0); auto B = mp(0, 0); auto C = mp(0, 0);
    A.X = 0; B.X = n;
    C.Y = m; B.Y = 0;
    A.Y = 0; C.X = B.X;
    cout << "YES" << endl;
    cout << A.X << sp << A.Y << endl;
    cout << B.X << sp << B.Y << endl;
    cout << C.X << sp << C.Y << endl;
}