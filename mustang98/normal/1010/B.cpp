#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 35, inf = 1000111222;

bool p[max_n];

int m, n;

int q(int y) {
    cout << y << endl;
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}

int qind = 0;
int q1(int y) {
    cout << y << endl;
    cout.flush();
    int ans;
    cin >> ans;
    if (p[qind % n] == 0) {
        ans *= -1;
    }
    qind++;
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> m >> n;
    for (int i = 0; i < n; ++i) {
        int ans = q(m);
        if (ans == 0) {
            exit(0);
        }
        if (ans == -1) {
            p[i] = 1;
        } else {
            p[i] = 0;
        }
    }

    int l = 0, r = m + 1;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        int ans = q1(mid);
        if (ans == 0) {
            exit(0);
        }
        if (ans == -1) {
            r = mid;
        } else {
            l = mid;
        }
    }

    return 0;
}