#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 2011, inf = 1000111222;

char a[max_n][max_n];
int cnt[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        scanf("%s", a[i]);
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '1') cnt[j]++;
        }
    }
    for (int i = 0; i < n; ++i) {
        bool can_del = 1;
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '1' && cnt[j] == 1) {
                can_del = 0;
                break;
            }
        }
        if (can_del) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}