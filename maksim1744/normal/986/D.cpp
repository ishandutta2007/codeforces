/*
    18.03.2019 20:09:55
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef HOME
#define TAG_LENGTH 45
#define LR_LEFT left
#define LR_RIGHT right
#define LR_VALUE value
#define LR_SECOND_VALUE mn
#include "C:/C++ libs/print.cpp"
#define showl cout << endl;
#define shows cout << string(5, ' ') + string(TAG_LENGTH, '-') << endl;
#else
#define show(...) 42;
#define showt(...) 42;
#define showl 42;
#define shows 42;
#define print(...) 42;
#define printTree(...) 42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

const int sz = 4;
const long long mod = 1e4;

long double eps = 1e-12;
long double pi = 3.14159265358979323;

struct Complex {
    long double x, y;

    Complex() : x(0), y(0) {}
    Complex(long double _x, long double _y) : x(_x), y(_y) {}
    Complex(long double _x) : x(_x), y(0) {}
    Complex(const Complex& c) : x(c.x), y(c.y) {}
};

Complex operator - (Complex& a) {
    return Complex(-a.x, -a.y);
}

Complex operator + (Complex& a, Complex&& b) {
    return Complex(a.x + b.x, a.y + b.y);
}

Complex operator * (Complex& a, Complex& b) {
    return Complex(a.x * b.x - a.y * b.y, a.x * b.y + b.x * a.y);
}

// using Complex = complex< long double >;

template< typename T >
vector< Complex > fft(vector< T >& v, bool good = false) {
    if (!good) {
        int p2 = 1;
        while (p2 < v.size()) {
            p2 *= 2;
        }
        v.resize(p2);
        for (int i = v.size(); i < p2; ++i) {
            v[i] = 0;
        }
    }
    if (v.size() == 1) {
        return vector< Complex > {Complex(v[0])};
    }
    int n = v.size() / 2;
    vector< Complex > v1(n * 2);
    int k = 0, n1 = 2 * n;
    while (n1 > 1) {
        n1 /= 2;
        ++k;
    }
    vector< Complex > w(2 * n);
    w[0] = 1;
    // w[1] = polar((long double)1, (long double)pi / n);
    w[1] = Complex(cosl(pi / n), sinl(pi / n));
    for (int i = 2; i < 2 * n; ++i) {
        w[i] = Complex(cosl(pi * i / n), sinl(pi * i / n));
        // w[i] = polar((long double)1, (long double)pi * i / n);
        // if (i >= n) {
        //     w[i] = -w[i - n];
        // } else {
        //     w[i] = w[i / 2] * w[i - i / 2];
        // }
    }
    vector< int > ind(2 * n, 0);
    ind[1] = 1 << (k - 1);
    int id = 2;
    for (int i = 1; i < k; ++i) {
        int z = (1 << i);
        for (int j = 0; j < z; ++j) {
            // cout << id << ' ' << z << ' ' << ind[id - z] << ' ' << i << ' ' << k << '\n';
            ind[id] = (ind[id - z]) + (1 << (k - 1 - i));
            ++id;
            // print(ind);
            // cout << id << endl;
        }
    }
    // print(ind);
    for (int i = 0; i < 2 * n; ++i) {
        v1[i] = Complex(v[ind[i]]);
    }
    for (int i = k - 1; i >= 0; --i) {
        int cnt = (1 << i);
        int sz = (1 << (k - i));
        int k1 = sz / 2 - 1;
        for (int j = 0; j < cnt; ++j) {
            int k2 = sz * j;
            vector< Complex > va(v1.begin() + sz * j, v1.begin() + sz * j + sz / 2);
            vector< Complex > vb(v1.begin() + sz * j + sz / 2, v1.begin() + sz * j + sz);
            for (int u = 0; u < sz; ++u) {
                v1[k2 + u] = va[u & k1] + w[u << i] * vb[u & k1];
            }
        }
    }
    return v1;
}

void multiply(vector< long long >& a, vector< long long >& b) {
    // if (a.size() <= 2 || b.size() <= 2) {
    //     vector< long double > c(a.size() + b.size() - 1, 0);
    //     for (int i = 0; i < a.size(); ++i) {
    //         for (int j = 0; j < b.size(); ++j) {
    //             c[i + j] += a[i] * b[j];
    //         }
    //     }
    //     while (c.size() > 0 && c.back() == 0) {
    //         c.pop_back();
    //     }
    //     return c;
    // }
    int k = a.size() + b.size() - 1;
    int p2 = 1;
    while (p2 < k) {
        p2 *= 2;
    }
    int oldasize = a.size();
    int oldbsize = b.size();
    a.resize(p2);
    for (int i = oldasize; i < p2; ++i) {
        a[i] = 0;
    }
    b.resize(p2);
    for (int i = oldbsize; i < p2; ++i) {
        b[i] = 0;
    }
    int n = p2;
    vector< Complex > va = fft(a, true), vb = fft(b, true);
    for (int i = 0; i < n; ++i) {
        va[i] = va[i] * vb[i];
    }
    vector< Complex > ansC = fft(va, true);
    for (int i = 0; i < n; ++i) {
        a[i] = (long long)round(ansC[i].x / (long double)(1.0 * n));
    }
    for (int i = 1; i <= n / 2; ++i) {
        swap(a[i], a[n - i]);
    }
    while (a.size() > 0 && a.back() == 0) {
        a.pop_back();
    }
}

void square(vector< long long >& a) {
    int k = a.size() * 2 - 1;
    int p2 = 1;
    while (p2 < k) {
        p2 *= 2;
    }
    int oldasize = a.size();
    a.resize(p2);
    for (int i = oldasize; i < p2; ++i) {
        a[i] = 0;
    }
    int n = p2;
    vector< Complex > va = fft(a, true);
    for (int i = 0; i < n; ++i) {
        va[i] = va[i] * va[i];
    }
    vector< Complex > ansC = fft(va, true);
    for (int i = 0; i < n; ++i) {
        a[i] = (long long)round(ansC[i].x / (long double)(1.0 * n));
    }
    for (int i = 1; i <= n / 2; ++i) {
        swap(a[i], a[n - i]);
    }
    while (a.size() > 0 && a.back() == 0) {
        a.pop_back();
    }
}

void push_down(vector< long long >& v) {
    long long rem = 0;
    for (int i = 0; i < v.size(); ++i) {
        v[i] += rem;
        rem = v[i] / mod;
        v[i] %= mod;
    }
    while (rem != 0) {
        v.push_back(rem % mod);
        rem /= mod;
    }
}

void multiply_by_num(vector< long long >& v, long long k) {
    long long rem = 0;
    for (int i = 0; i < v.size(); ++i) {
        v[i] = v[i] * k + rem;
        rem = v[i] / mod;
        v[i] %= mod;
    }
    while (rem != 0) {
        v.push_back(rem % mod);
        rem /= mod;
    }
}

bool comp(vector< long long >& a, vector< long long >& b) {
    if (a.size() != b.size())
        return a.size() < b.size();
    for (int i = a.size() - 1; i >= 0; --i) {
        if (a[i] != b[i])
            return a[i] < b[i];
    }
    return false;
}

vector< long long > mpow(vector< long long >& v, long long pow) {
    if (pow == 0) return {1};
    if (pow % 2 == 0) {
        auto v1 = mpow(v, pow / 2);
        // long long last = v1.front() % mod;
        square(v1);
        push_down(v1);
        // v1.front() = last * last % mod;
        return v1;
    } else {
        auto v1 = mpow(v, pow / 2);
        // long long last = v1.front() % mod;
        square(v1);
        multiply_by_num(v1, 3);
        // v1.front() = last * last * 3 % mod;
        return v1;
    }
}

int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector< int > dd = {0, 2, 4};
    vector< int > pp = {1, 2, 4};
    if (n <= 9) {
        int m = 0;
        for (int i = 0; i < n; ++i) {
            m = m * 10 + s[i] - '0';
        }
        if (m <= 3) {
            cout << m << '\n';
            return 0;
        }
        int ans = 1000000;
        for (int i = 0; i < 3; ++i) {
            int p = pp[i];
            int sm = 0;
            while (p < m) {
                p *= 3;
                sm += 3;
            }
            // show(p, sm, d);
            ans = min(ans, sm + dd[i]);
        }
        cout << ans << '\n';
        return 0;
    }
    vector< long long > need;
    int k0 = n % sz;
    k0 = k0 == 0 ? 0 : sz - k0;
    s = string(k0, '0') + s;
    for (int i = 0; i < s.size() / sz; ++i) {
        int k = 0;
        for (int j = sz * i; j < sz * i + sz; ++j) {
            k = k * 10 + s[j] - '0';
        }
        need.push_back(k);
    }
    reverse(need.begin(), need.end());
    int cnt = (long double)2.095903274289385 * n - 5;
    // show(cnt);
    vector< long long > p3 = {3};
    vector< long long > vv = {1};
    p3.reserve(n + 30);
    vv.reserve(n + 30);
    int cnt1 = cnt;
    // show(cnt1);
    vv = mpow(p3, cnt);
    // while (cnt1 != 0) {
    //     if (cnt1 & 1) {
    //         multiply(vv, p3);
    //         push_down(vv);
    //     }
    //     cnt1 >>= 1;
    //     if (cnt1 > 0) {
    //         square(p3);
    //         push_down(p3);
    //     }
    // }
    // show(vv);
    long long ans = 1e9l * 1e9l;
    for (int i = 0; i < 3; ++i) {
        auto v = vv;
        long long sm = cnt * 3;
        if (i != 0) {
            sm += dd[i];
            multiply_by_num(v, pp[i]);
        }
        while (comp(v, need)) {
            multiply_by_num(v, 3);
            sm += 3;
        }
        ans = min(ans, sm);
    }
    cout << ans << '\n';
    return 0;
}