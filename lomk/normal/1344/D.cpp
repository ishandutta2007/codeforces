/*input
10 32
1 2 3 4 5 5 5 5 5 5
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x,y) ((x>>y)&1)
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() {cout << endl;} template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value << ' ', print(values...);}
void debug() {cerr << endl;} template<typename T, typename... Ts> void debug(const T& value, const Ts&... values) {cerr << value << ' ', debug(values...);}
#endif
// const int N =;

int n, m;
vector<int> a, b, last;
const int INF = 4e18;

int cal(int A, int B) {
    return B * (A - B * B);
}

int calUp(int A, int B) {
    return -A + 3 * B * B + 3 * B + 1;
}

int calDown(int A, int B) {
    return A - 3 * B * B + 3 * B - 1;
}

void solveSmall(int need) {
    auto count2 = [&](int p, int loss) {
        int l = b[p]; int r = a[p];
        while (l != r) {
            int mid = (l + r + 1) / 2;
            if (calUp(a[p], mid) <= loss) l = mid;
            else r = mid - 1;
        }
        last[p] = l;
        return l - b[p];
    };
    auto count = [&](int loss) {
        int ret =  0;
        loop(i, 0, n - 1) {
            ret += count2(i, loss);
        }
        return ret;
    };
    int l = 0, r = INF;
    while (l != r) {
        int mid = (l + r + 1) / 2;
        if (count(mid) > need) r = mid - 1;
        else l = mid;
    }
    count(l);
    int curs = accumulate(last.begin(), last.end(), 0LL);
    vector<pair<int, int> > tmp;
    loop(i, 0, n - 1) {
        if (last[i] < a[i])
            tmp.push_back({calUp(a[i], last[i]), i});
    }
    sort(tmp.begin(), tmp.end());
    loop(i, 0, m - curs - 1) last[tmp[i].se]++;
}

void solveLarge(int need) {
    auto count2 = [&](int p, int loss) {
        int l = 0; int r = b[p];
        while (l != r) {
            int mid = (l + r) / 2;
            if (calDown(a[p], mid) <= loss) r = mid;
            else l = mid + 1;
        }
        last[p] = l;
        return b[p] - l;
    };
    auto count = [&](int loss) {
        int ret = 0;
        loop(i, 0, n - 1) {
            ret += count2(i, loss);
        }
        return ret;
    };
    int l = 0, r = INF;
    while (l != r) {
        int mid = (l + r + 1) / 2;
        if (count(mid) > need) r = mid - 1;
        else l = mid;
    }
    count(l);
    int curs = accumulate(last.begin(), last.end(), 0LL);
    vector<pair<int, int> > tmp;
    loop(i, 0, n - 1) {
        if (last[i] > 0)
            tmp.push_back({calDown(a[i], last[i]), i});
    }
    sort(tmp.begin(), tmp.end());
    loop(i, 0, curs - m - 1) last[tmp[i].se]--;
}


int sqrt128(int t) {
    int l = 0, r = 1e9;
    while (l != r) {
        int mid = (l + r + 1) / 2;
        if (mid * mid <= t) l = mid;
        else r = mid - 1;
    }
    return l;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
// #ifdef in1code
//     freopen("1test.inp", "r", stdin);
// #endif
    cin >> n >> m;
    loop(i, 1, n) {
        int t; cin >> t;
        a.push_back(t);
    }
    for (auto it : a) {
        auto t = sqrt128(it / 3);
        auto l1 = cal(it, t);
        auto l2 = cal(it, t + 1);
        if (l1 < l2) b.push_back(t + 1);
        else b.push_back(t);
    }
    last = b;
    int sum = accumulate(last.begin(), last.end(), 0LL);
    if (sum < m)
        solveSmall(m - sum);
    else if (sum > m)
        solveLarge(sum - m);
    for (auto it : last) cout << it << sp;
    cout << endl;
}