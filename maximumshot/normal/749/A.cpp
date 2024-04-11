#include <bits/stdc++.h>

#include <unordered_set>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    int n;
    cin >> n;

    if(n == 2) cout << "1\n2\n";
    else if(n == 3) cout << "1\n3\n";
    else {
        if(n % 2 == 0) {
            cout << n / 2 << "\n";
            for(int i = 0;i < n / 2;i++) cout << "2 ";
        }else {
            cout << (n - 3) / 2 + 1 << "\n";
            for(int i = 0;i < (n - 3) / 2;i++) cout << "2 ";
            cout << 3 << "\n";
        }
    }

    return 0;
}