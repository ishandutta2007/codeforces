#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 511, inf = 1000111222;

int n;
vector<char> ans1;
vector<char> ans2;

bool query(int i1, int j1, int i2, int j2) {
    cout << '?' << ' ' << i1 << ' ' << j1 << ' ' << i2 << ' ' << j2 << endl;
    cout.flush();
    string res;
    cin >> res;
    if (res == "BAD") {
        exit(228);
    }
    return res == "YES";
}

int main()
{
    cin >> n;
    //freopen("input.txt", "r", stdin);
    int curi = 1, curj = 1;
    for (int i = 0; i + 1 < n; ++i) {
        if (query(curi + 1, curj, n, n)) {
            ans1.PB('D');
            curi++;
        } else {
            ans1.PB('R');
            curj++;
        }
    }
    curi = n;
    curj = n;
    for (int i = 0; i + 1 < n; ++i) {
        if (query(1, 1, curi, curj - 1)) {
            ans2.PB('R');
            --curj;
        } else {
            ans2.PB('D');
            --curi;
        }
    }

    cout << "! ";
    reverse(ans2.begin(), ans2.end());
    for (int i = 0; i < ans1.size(); ++i) {
        cout << ans1[i];
    }
    for (int i = 0; i < ans2.size(); ++i) {
        cout << ans2[i];
    }
    return 0;
}