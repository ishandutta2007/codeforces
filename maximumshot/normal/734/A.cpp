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

int main() {

    int n;
    cin >> n;

    string s;
    cin >> s;

    int c = 0;

    for(auto t : s) {
        c += t == 'A';
    }

    if(c > n - c) {
        cout << "Anton\n";
    }else if(c < n - c) {
        cout << "Danik\n";
    }else {
        cout << "Friendship\n";
    }

    return 0;
}