#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

int b[max_n];
int a[max_n];
int n;

bool check(int k) {
    int cnt = 0;
    int mna = k - 1, mnb = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= mna && b[i] >= mnb) {
            ++cnt;
            if (cnt == k) return true;
            --mna;
            ++mnb;
        }
    }
    return false;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
        }
        int l = 1;
        int r = n + 1;
        while(l + 1 < r) {
            int mid = (l + r) / 2;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << l << "\n";
    }
    return 0;
}