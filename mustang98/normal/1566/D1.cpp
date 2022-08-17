#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 311, inf = 1000111222;

int a[max_n];
int s[max_n];

bool cmp(int i, int j) {
    if (a[i] == a[j]) {
        return i > j;
    }
    return a[i] < a[j];
}

int n, m;
int vis[max_n];
int calc(vector<int> v) {
    memset(vis, 0, sizeof(vis));
    int ans = 0;
    for (int i : v) {
        ans += accumulate(vis, vis + i + 1, 0);
        vis[i] = 1;
    }
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        vector<int> v;
        for (int i = 0; i < n * m; ++i) {
            cin >> a[i];
            v.PB(i);
        }
        sort(v.begin(), v.end(), cmp);
        cout << calc(v) << "\n";
    }

    return 0;
}