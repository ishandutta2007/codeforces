#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< int, int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

//    freopen("input.txt", "r", stdin);

    string a, b;

    cin >> a >> b;

    int n;
    cin >> n;

    for(int i = 0;i < n;i++) {
        cout << a << " " << b << "\n";

        string x, y;

        cin >> x >> y;

        if(x == a) a = y;
        else b = y;

    }

    cout << a << " " << b << "\n";

    return 0;
}