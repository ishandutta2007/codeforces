#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 111, inf = 1000111222;

int cnt[max_n];
int n, m;

bool check(int days) {
    int cntu = 0;
    for (int i = 0; i < max_n; ++i) {
        cntu += cnt[i] / days;
    }
    return cntu >= n;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < m ;++i) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    for (int i = 1; i < 200; ++i) {
        if (check(i) == 0) {
            cout << i - 1;
            return 0;
        }
    }

    return 0;
}