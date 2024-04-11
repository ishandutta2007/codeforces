#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;
int m[max_n];
int d[max_n];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i =0 ; i < n; ++i) {
        cin >> m[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        d[i] = abs(m[i] - m[i + 1]);
        if (i % 2 == 0) {
            d[i] *= (-1);
        }
    }
    ll sum = 0;
    ll maxx = 0;
    for (int i = 0; i < n - 1; ++i) {
        sum += d[i];
        maxx = max(maxx, sum);
        if (sum < 0) {
            sum = 0;
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        d[i] = -d[i];
    }
    sum = 0;
    for (int i = 0; i < n - 1; ++i) {
        sum += d[i];
        maxx = max(maxx, sum);
        if (sum < 0) {
            sum = 0;
        }
    }
    cout << maxx;
    return 0;
}