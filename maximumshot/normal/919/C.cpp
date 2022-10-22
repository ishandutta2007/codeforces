#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned int ui;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1ll * inf * inf;

int count(vec< string > a, int k) {
    if((int)a[0].size() < k) return 0;
    int res = 0;
    for(int i = 0;i < (int)a.size();i++) {
        int cnt = 0;
        for(int j = 0;j < k;j++) {
            cnt += a[i][j] == '*';
        }
        for(int j = 0;j + k - 1 < (int)a[i].size();j++) {
            res += !cnt;
            cnt -= a[i][j] == '*';
            if(j + k < (int)a[i].size()) {
                cnt += a[i][j + k] == '*';
            }
        }
    }
    return res;
}

vec< string > transpose(vec< string > a) {
    vec< string > res((int)a[0].size(), string((int)a.size(), '.'));
    for(int i = 0;i < (int)a.size();i++) {
        for(int j = 0;j < (int)a[i].size();j++) {
            res[j][i] = a[i][j];
        }
    }
    return res;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n, m, k;

    cin >> n >> m >> k;

    vec< string > a(n, string(m, '.'));

    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }

    int res = count(a, k);

    if(k > 1) {
        a = transpose(a);
        res += count(a, k);
    }

    cout << res << "\n";

    return 0;
}