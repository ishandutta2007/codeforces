#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 50111, inf = 1000111222;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    if (n == 1 || n == 2) {
        cout << "No";
        return 0;
    }
    cout << "Yes" << endl;
    vector<int> g1, g2;

    if (n % 2 == 0) {
        g1.PB(1);
        g1.PB(n);
        for (int i = 2; i < n; ++i) {
            g2.PB(i);
        }
    } else {
        g1.PB(n / 2 + 1);
        for (int i = 1; i <= n; ++i) {
            if (i == n / 2 + 1) continue;
            g2.PB(i);
        }
    }
    cout << g1.size() << ' ';
    for (int a : g1) cout << a << ' ';
    cout << endl;

    cout << g2.size() << ' ';
    for (int a : g2) cout << a << ' ';
    cout << endl;


    return 0;
}