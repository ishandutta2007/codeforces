#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 3000;

ll n, best[Maxn];
pair <ll, ll> info[Maxn];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> info[i].first >> info[i].second;
    sort(info, info+n);
    best[0] = info[0].second;
    for (int i = 1; i < n; i++) {
        ll mn = best[0];
        for (int j = 0; j < i; j++) {
            mn = min(mn, best[j]);
            best[j] += info[i].first - info[j].first;
        }
        best[i] = mn + info[i].second;
    }
    ll mn = best[0];
    for (int i = 1; i < n; i++) mn = min(mn, best[i]);
    cout << mn << endl;
    return 0;
}