#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 101, inf = 1000111222;

int n;
ll m[max_n];

bool comp(ll a, ll b) {
    int cnt2a = 0, cnt2b = 0;
    while (a % 2 == 0) {
        a /= 2;
        cnt2a++;
    }
    while (b % 2 == 0) {
        b /= 2;
        cnt2b++;
    }
    if (cnt2a == cnt2b) return a > b;
    return cnt2a < cnt2b;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
    }
    sort(m, m + n, comp);
    for (int i = 0; i < n; ++i) {
        cout << m[i] << ' ';
    }
    return 0;
}