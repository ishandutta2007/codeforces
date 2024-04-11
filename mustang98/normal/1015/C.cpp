#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

ll a[max_n];
ll b[max_n];
vector<ll> v;

bool comp(int i, int j) {
    return a[i] - b[i] < a[j] - b[j];
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    ll m;
    ll curw = 0;
    ll sumb = 0;

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        v.PB(i);
        curw += a[i];
        sumb += b[i];
    }
    if (sumb > m) {
        cout << -1;
        return 0;
    }
    sort(v.begin(), v.end(), comp);
    int ans = 0;
    while (curw > m) {
        ans++;
        int i = v.back();
        v.pop_back();
        curw -= (a[i] - b[i]);
    }
    cout << ans;

    return 0;
}