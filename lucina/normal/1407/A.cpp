#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;

int n;
int a[nax];

int main() {
    int T;
    cin.tie(0)->sync_with_stdio(false);

    for (cin >> T ; T -- ;) {
        cin >> n;

        for (int i = 1 ; i <= n ; ++ i)
            cin >> a[i];

        int one = count(a + 1, a + 1 + n, 1);
        int zero = n - one;
        if (one <= n / 2) {
            cout << zero << '\n';
            for (int i = 0 ; i < zero ; ++ i)
            cout << '0' << ' ';
            cout << '\n';
        } else {
            if (one % 2) -- one;
            cout << one << '\n';
            for (int i = 0 ; i < one ; ++ i)
                cout << '1' << ' ';
            cout << '\n';
        }
    }
}
/**
    Why 9am tomorrow?
    :sad face
*/