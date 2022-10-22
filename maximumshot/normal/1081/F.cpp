#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long double, long double > pdd;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 1e5 + 5;
const ll MAXX = 1e13;

int ask(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int res;
    cin >> res;
    return res;
}

int main() {

#ifdef debug
//    freopen("input.txt", "r", stdin);
#endif

    int n, t;

    cin >> n >> t;

    if(t == 0) {
        cout << "! " << string(n, '0') << endl;
        return 0;
    }

    if(t == n) {
        cout << "! " << string(n, '1') << endl;
        return 0;
    }

    vector< int > a(n + 1);
    vector< pii > queries;

    auto upd = [&](int l, int r) {
        for(int i = l;i <= r;i++) {
            a[i] ^= 1;
        }
    };

    if(n % 2 == 0) {
        int x = 0;
        for(int i = 1;i <= n;i++) {
            while(1) {
                int t2 = ask(i, i);
                if(t2 % 2 == (i + t) % 2) {
                    int c = ( (i + t - t2) / 2 - x );
                    a[i] = c;
                    x += c;
                    upd(1, i);
                    x = i - x;
                    queries.push_back({1, i});
                    t = t2;
                    break;
                }
                queries.push_back({i, n});
                t = t2;
            }
        }
        for(pii qi : queries) {
            upd(qi.first, qi.second);
        }
        cout << "! ";
        for(int i = 1;i <= n;i++) {
            cout << a[i];
        }
        cout << endl;
        return 0;
    }

    // n >= 3

    int F = -1;

    {
        for(int i = 0;i <= 30;i++) {
            int t2 = ask(2, n);
            if((n - t) % 2 == t2 % 2) {
                t = n - t;
                queries.push_back({1, n});
                continue;
            }
            F = (t2 + t + 1 - n) / 2;
            t = t2;
            queries.push_back({2, n});
            break;
        }
    }

//    cout << "F = " << F << "\n";

    a[1] = F;

    for(int d = F, x = d, i = 2;i <= n;i++) {
//        cout << i << " : " << x << " ? " << endl;
        while(1) {
//            cout << "i = " << i << ", x = " << x << ", d = " << d << "\n";
            int t2 = ask(i - 1, i);
            if((t + i) % 2 == t2 % 2) {
                int c = (t + i - t2) / 2 - x;
                a[i] = c;
                x += c;
                queries.push_back({1, i});
                upd(1, i);
                x = i - x;
                t = t2;
                d = c ^ 1;
                break;
            }
            queries.push_back({i - 1, n});
            upd(i - 1, n);
            x -= d;
            d ^= 1;
            x += d;
            t = t2;
        }
    }

//    for(pii qi : queries) {
////        cout << "[" << qi.first << " .. " << qi.second << "]\n";
//        upd(qi.first, qi.second);
//    }

    for(pii qi : queries) {
        upd(qi.first, qi.second);
    }
    cout << "! ";
    for(int i = 1;i <= n;i++) {
        cout << a[i];
    }
    cout << endl;

    return 0;
}