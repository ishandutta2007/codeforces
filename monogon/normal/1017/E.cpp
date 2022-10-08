
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

#define pt complex<ll>
#define x real()
#define y imag()
#define dot(u, v) (conj(u) * (v)).x
#define cross(u, v) (conj(u) * (v)).y

istream &operator>>(istream &is, pt &p) {
    ll X, Y;
    is >> X >> Y;
    p = {X, Y};
    return is;
}

const int N = 1e5 + 5;
int n, m;

vector<pt> hull(vector<pt> &v) {
    int n = sz(v);
    sort(all(v), [&](pt a, pt b) {
        return make_pair(a.x, a.y) < make_pair(b.x, b.y);
    });
    auto sweep = [&]() {
        vector<pt> st;
        rep(i, 0, n) {
            while(sz(st) >= 2) {
                pt p1 = st.back(); st.pop_back();
                pt p2 = st.back();
                if(cross(p1 - p2, v[i] - p2) < 0) {
                    st.push_back(p1);
                    break;
                }
            }
            st.push_back(v[i]);
        }
        return st;
    };
    vector<pt> st = sweep();
    reverse(all(v));
    vector<pt> st2 = sweep();
    st.pop_back();
    st2.pop_back();
    st.insert(st.end(), all(st2));
    return st;
}

vector<ll> signature(vector<pt> &v) {
    vector<ll> ans;
    int n = sz(v);
    rep(i, 0, n) {
        int j = (i + 1) % n;
        int k = (i + 2) % n;
        ans.push_back(norm(v[j] - v[i]));
        ans.push_back(dot(v[k] - v[j], v[j] - v[i]));
        ans.push_back(cross(v[k] - v[j], v[j] - v[i]));
    }
    return ans;
}

int kmp[3 * N];

void makekmp(vector<ll> &v) {
    int i = 1, j = 0, n = sz(v);
    while(i < n) {
        if(v[i] == v[j]) kmp[i++] = ++j;
        else if(j == 0) kmp[i++] = 0;
        else j = kmp[j - 1];
    }
}

bool kmpfind(vector<ll> &s, vector<ll> &t) {
    int i = 0, j = 0, n = sz(s), m = sz(t);
    while(i < n) {
        if(s[i] == t[j]) i++, j++;
        if(j == m) return true;
        else if(i < n && s[i] != t[j]) {
            if(j == 0) i++;
            else j = kmp[j - 1];
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<pt> v1(n, 0), v2(m, 0);
    rep(i, 0, n) cin >> v1[i];
    rep(j, 0, m) cin >> v2[j];
    v1 = hull(v1);
    v2 = hull(v2);
    vector<ll> s1 = signature(v1);
    vector<ll> s2 = signature(v2);
    makekmp(s1);
    int k = sz(s2);
    rep(i, 0, k) s2.push_back(s2[i]);
    cout << (sz(v1) == sz(v2) && kmpfind(s2, s1) ? "YES" : "NO") << '\n';
}