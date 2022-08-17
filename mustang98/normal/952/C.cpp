#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 11, inf = 1000111222;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int m[max_n];
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        if (abs(m[i] - m[i + 1]) >= 2) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

    return 0;
}