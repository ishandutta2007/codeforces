#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1, inf = 1000111222;

void check(vector<int> v) {
    vector<int> s;
    int n = v.size() / 2;
    for (int i = 0; i < v.size(); ++i) {
        int cs = 0;
        for (int j = 0; j < n; ++j) {
            cs += v[(i + j) % v.size()];
        }
        s.PB(cs);
    }

    sort(s.begin(), s.end());
    if (abs(s[0] - s.back()) <= 1) {
        for (int a : v) {
            cout << a << ' ';
        }
        cout << endl;
        exit(228);
    }
}
// 1 2
// 1 4 5 2 3 6
// 1 4 5 8 9 | 2 3 6 7 10
// 1 4 5 8 9 12 13 | 2 3 6 7 10 11 14

vector<int> solve(int n) {
    int cnt = ((n - 1) / 2);
    n *= 2;
    vector<int> v1;
    vector<int> v2;
    int cur = 1;
    v1.PB(cur++);
    for (int i = 0; i < cnt; ++i) {
        v2.PB(cur++);
        v2.PB(cur++);
        v1.PB(cur++);
        v1.PB(cur++);
    }
    v2.PB(cur);
    for (int a : v2) {
        v1.PB(a);
    }
    return v1;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << "NO" << endl;
        return 0;
    }
    vector<int> ans = solve(n);
    //check(ans);
    cout << "YES" << endl;
    for (int a : ans) {
        printf("%d ", a);
    }
    return 0;
}