#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 7011, inf = 1000111222;

int c[max_n];
ll a[max_n];
ll b[max_n];
int n;

inline bool is_b(ll a, ll b) {
    return a != (b & a);
}

ll sum = 0, cnt = 0;
bool del[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    cnt = n;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (is_b(b[i], b[j])) {
                ++c[i];
            }
        }
        //cout << c[i] << ' ';
    }
    //cout << endl;

    while(cnt > 1) {
        int bst = -1;
        for (int i = 0; i < n; ++i) {
            if (!del[i] && c[i] == cnt - 1) {
                bst = i;
                break;
            }
        }
        if (bst == -1) {
            cout << sum << endl;
            return 0;
        }
        sum -= a[bst];
        del[bst] = 1;
        --cnt;
        for (int i = 0; i < n; ++i) {
            if (!del[i] && is_b(b[i], b[bst])) {
                --c[i];
            }
        }
    }
    cout << 0 << endl;
    return 0;
}