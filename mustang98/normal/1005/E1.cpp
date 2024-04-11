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

vector<int> v;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, M;
    cin >> n >> M;
    int pos = -1;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a < M) {
            v.PB(-1);
        }
        if (a > M) {
            v.PB(1);
        }
        if (a == M) {
            v.PB(M);
            pos = i;
        }
    }
    map<int, int> m;
    int sum = 0;
    m[0]++;
    for (int i = pos - 1; i >= 0; --i) {
        sum += v[i];
        m[sum]++;
    }
    ll ans = 0;
    ans += m[0];
    ans += m[1];
    sum = 0;
    for (int i = pos + 1; i < v.size(); ++i) {
        sum += v[i];
        int sum1 = -sum;
        ans += m[sum1];
        sum1++;
        ans += m[sum1];
    }
    cout << ans;
    return 0;
}