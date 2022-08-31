#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 50, inf = 1000111222;

int cnt[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    int n, k;
    cin >> n >> k;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        cnt[s[i] - 'A']++;
    }
    int mx = inf;
    for (int i = 0; i < k; ++i) {
        mx = min(mx, cnt[i]);
    }
    cout << k * mx << endl;

    return 0;
}