#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 5011, inf = 1000111222;

int n;
int m[max_n];
int gr[max_n];
int lft[max_n];

inline bool is_sq(ll a, ll b) {
    ll ab = a * b;
    if (a * b < 0) return 0;
    double sq = sqrt(ab);
    ll sqi = ll(sq + 0.5);
    return (sqi * sqi == ab || (sqi - 1) * (sqi - 1) == ab || (sqi + 1) * (sqi + 1) == ab);
}

int max_gr = 0;

int ans[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    for (int i = 0; i < max_n; ++i) {
        gr[i] = -1;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        //m[i] = (1LL * rand() * rand()) % int(1e8);
        cin >> m[i];
    }
    for (int i = 0; i < n; ++i) {
        if (m[i] == 0) continue;
        for (int j = i - 1; j >= 0; --j) {
            if (m[j] == 0) continue;
            if (is_sq(m[i], m[j])) {
                gr[i] = gr[j];
                lft[i] = j;
                break;
            }
        }
        if (gr[i] == -1) {
            gr[i] = max_gr;
            lft[i] = -1;
            max_gr++;
        }
    }
    //cout << endl;
    for (int st = 0; st < n; ++st) {
        int cnt = 0;
        for (int j = st; j < n; ++j) {
            if (m[j] && (lft[j] == -1 || lft[j] < st)) ++cnt;
            ans[cnt]++;
        }
    }
    ans[1] += ans[0];
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }

    return 0;
}