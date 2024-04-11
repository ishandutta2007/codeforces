#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<ll, ll> pll;

bool isLess(pll a, pll b) {
    return a.first * b.second < a.second * b.first;
}

vector<ll> sums;
int n;
vector<ll> a;

ll getSum(int l, int r) {
    ll res = sums[r];
    l--;
    if (l >= 0)
        res -= sums[l];
    return res;
}

pll calcOdd(int mid, int len) {
    ll s = getSum(mid - len, mid) + getSum(n - len, n - 1);
    ll m = a[mid];
    ll cnt = 2 * len + 1;
    return pll(s - cnt * m, cnt);
}

pll calcEven(int mid, int len) {
    ll s = getSum(mid - len + 1, mid) + getSum(n - len, n - 1);
    ll m = a[mid] + a[n - len];
    ll cnt = 2 * len;
    return pll(s - len * m, cnt);
}

struct Result {
    pll val;
    int mid;
    int len;
    int type; // 1 - odd 0 - even

    Result(pll val, int mid, int len, int type): val(val), mid(mid), len(len), type(type) {}        
};

Result getMax(const Result& a, const Result& b) {
    if (isLess(a.val, b.val))
        return b;
    return a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    a.resize(n);
    sums.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        sums[i] = a[i];
        if (i > 0)
            sums[i] += sums[i - 1];
    }
    Result res(pll(0, 1), 0, 0, 1);
    for (int mid = 0; mid < n; mid++) {
        int lo = 0;
        int hi = min(mid, n - mid - 1);
        while (hi - lo > 10) {
            int m1 = lo + (hi - lo) / 3;
            int m2 = hi - (hi - lo) / 3;
            pll f1 = calcOdd(mid, m1);
            pll f2 = calcOdd(mid, m2);
            if (isLess(f1, f2))
                lo = m1;
            else  
                hi = m2;
        }
        for (int i = lo; i <= hi; i++) {
            pll f = calcOdd(mid, i);
            res = getMax(res, Result(f, mid, i, 1));
        }                  
    }
    for (int mid = 0; mid < n; mid++) {
        int lo = 0;
        int hi = min(mid + 1, n - mid - 1);
        while (hi - lo > 10) {
            int m1 = lo + (hi - lo) / 3;
            int m2 = hi - (hi - lo) / 3;
            pll f1 = calcEven(mid, m1);
            pll f2 = calcEven(mid, m2);
            if (isLess(f1, f2))
                lo = m1;
            else  
                hi = m2;
        }
        for (int i = lo; i <= hi; i++) {
            pll f = calcEven(mid, i);
            res = getMax(res, Result(f, mid, i, 0));
        }                  
    }
    if (res.type == 0) {
        cout << res.len * 2 << "\n";
        for (int i = res.mid - res.len + 1; i <= res.mid; i++)
            cout << a[i] << " ";
        for (int i = n - res.len; i < n; i++)
            cout << a[i] << " ";
    } else {
        cout << res.len * 2 + 1 << "\n";
        for (int i = res.mid - res.len; i <= res.mid; i++)
            cout << a[i] << " ";
        for (int i = n - res.len; i < n; i++)
            cout << a[i] << " ";
    }
    cout << endl;
    return 0;                          
}