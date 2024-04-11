
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
struct bit {
    size_t n, lg;
    vector<T> a;
    bit(size_t n) : n(n) {
        a.assign(n, T());
        lg = 0;
        while(2 * (1u << lg) < n) lg++;
    }
    void add(size_t i, T x) {
        while(i < n) {
            a[i] = a[i] + x;
            i += i & -i;
        }
    }
    T get(size_t i) {
        T x = T();
        while(i > 0) {
            x = x + a[i];
            i -= i & -i;
        }
        return x;
    }
    size_t lower_bound(T val) {
        size_t i = 0;
        T sum = T();
        for(size_t k = lg; ; k--) {
            if(i + (1 << k) < n && sum + a[i + (1 << k)] < val) {
                i += (1 << k);
                sum = sum + a[i];
            }
            if(k == 0) return i + 1;
        }
    }
};

const int N = 2e5 + 5;
bit<int> B(N);
int cache[N];

int ask(int r) {
    if(cache[r] >= 0) return cache[r] + B.get(r);
    cout << "? " << 1 << ' ' << r << endl;
    int ans;
    cin >> ans;
    cache[r] = ans - B.get(r);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t, k;
    cin >> n >> t;
    fill(cache, cache + N, -1);
    while(t--) {
        cin >> k;
        int L = 1, R = n;
        while(L < R) {
            int m = (L + R) / 2;
            int x = ask(m);
            if(m - x < k) {
                L = m + 1;
            }else {
                R = m;
            }
        }
        cout << "! " << L << endl;
        B.add(L, 1);
    }
}