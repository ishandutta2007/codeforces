#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1, inf = 1000111222;

char query(int x, int y) {
    cout << "? " << x << ' ' << y << endl;
    string r;
    cin >> r;
    if (r[0] == 'e') {
        exit(0);
    }
    return r[0];
}

int start() {
    int x = 0, y = 1;
    while(true) {
        char r = query(x, y);
        if (x == 0 && y == 1 && r == 'x') {
            return 1;
        }
        if (r == 'y') {
            x = y;
            y = x * 2;
        } else {
            break;
        }
    }
    int l = x, r = y;
    while(l + 1 < r) {
        int mid = (1LL * l + r) / 2;
        char res = query(x, mid);
        if (res == 'x') {
            r = mid;
        } else {
            l = mid;
        }
    }
    return r;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    while(true) {
        string s;
        cin >> s;
        if (s == "end") {
            return 0;
        }
        if (s == "mistake") {
            exit(228);
        }
        if (s == "start") {
            int res = start();
            cout << "! " << res << endl;
        }
    }

    return 0;
}