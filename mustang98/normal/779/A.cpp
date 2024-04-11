#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 111, inf = 1000111222;

int ca[6];
int cb[6];

int cab = 0, cba = 0;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ca[a]++;
    }
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        cb[a]++;
    }
    int ans = 0;
    for (int i = 1; i <= 5; ++i) {
        int d = abs(ca[i] - cb[i]);
        if (d % 2 == 1) {
            cout << -1 << endl;
            return 0;
        }
        if (ca[i] > cb[i]) {
            cab += d / 2;
        } else {
            cba += d / 2;
        }
    }
    if (cba == cab) {
        cout << cba << endl;
        return 0;
    }
    cout << -1 << endl;

    return 0;
}