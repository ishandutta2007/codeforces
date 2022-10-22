#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

bool solve() {

    int d[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    string w[7] = {
           "monday",
           "tuesday",
           "wednesday",
           "thursday",
           "friday",
           "saturday",
           "sunday"
    };

    string s1, s2;
    cin >> s1 >> s2;

    int a, b;

    for(int i = 0;i < 7;i++) {
        if(s1 == w[i]) a = i;
        if(s2 == w[i]) b = i;
    }

    int delt = ((b - a) % 7 + 7) % 7;

    for(int i = 0;i < 12;i++) {
        if(d[i] % 7 == delt) {
            cout << "YES\n";
            return true;
        }
    }

    cout << "NO\n";

    return true;
}

int main() {

#ifdef MY
    while(solve());
#else
    solve();
#endif

    return 0;
}