#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef unsigned long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    int n, k, a, b;

    cin >> n >> k >> a >> b;

    if(a == 0) {
        if(n > k) {
            cout << "NO\n";
        }else {
            for(int i = 0;i < n;i++) {
                cout << "B";
            }
            cout << "\n";
        }
        return 0;
    }

    if(b == 0) {
        if(n > k) {
            cout << "NO\n";
        }else {
            for(int i = 0;i < n;i++) {
                cout << "G";
            }
            cout << "\n";
        }
        return 0;
    }

    if(a == b) {
        for(int i = 0;i < n;i++) {
            cout << (i % 2 ? "G" : "B");
        }
        cout << "\n";
        return 0;
    }

    if(a > b) {
        if((b + 1) * k < a) {
            cout << "NO\n";
            return 0;
        }
        vec< int > mas(b + 1, 1);
        int d = a - b - 1;
        for(int i = 0;i <= b;i++) {
            mas[i] += min(k - 1, d);
            d -= min(k - 1, d);
        }
        for(int i = 0;i <= b;i++) {
            cout << string( mas[i], 'G' );
            if(i < b) cout << "B";
        }
        cout << "\n";
    }else {
        if((a + 1) * k < b) {
            cout << "NO\n";
            return 0;
        }
        vec< int > mas(a + 1, 1);
        int d = b - a - 1;
        for(int i = 0;i <= a;i++) {
            mas[i] += min(k - 1, d);
            d -= min(k - 1, d);
        }
        for(int i = 0;i <= a;i++) {
            cout << string( mas[i], 'B' );
            if(i < a) cout << "G";
        }
        cout << "\n";
    }

    return 0;
}