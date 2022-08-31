#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 21, max_v = 1011, inf = 1000111222;

int ans[max_n][max_n];
vector<int> v;
int cnt[max_v];
vector<int> v4;
vector<int> v2;
vector<int> v1;
int n;

void print() {
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ans[i][j] << ' ' ;
        }
        cout << endl;
    }
    exit(0);
}

void solvec() {
    if (v2.size() || v1.size()) {
        cout << "NO" << endl;
        exit(0);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (ans[i][j] != 0) continue;
            int cur = v4.back();
            ans[i][j] = cur;
            ans[i][n - 1 - j] = cur;
            ans[n - 1 - i][j] = cur;
            ans[n - 1 - i][n - 1 - j] = cur;
            v4.pop_back();
        }
    }
    print();
}

void NO() {
    cout << "NO" << endl;
    exit(0);
}

void solvenc() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == n / 2 || j == n / 2) continue;
            if (ans[i][j] != 0) continue;
            if (v4.empty()) {
                NO();
            }
            int cur = v4.back();
            v4.pop_back();
            ans[i][j] = cur;
            ans[i][n - 1 - j] = cur;
            ans[n - 1 - i][j] = cur;
            ans[n - 1 - i][n - 1 - j] = cur;
        }
    }
    while(!v4.empty()) {
        int cur = v4.back();
        v4.pop_back();
        v2.PB(cur);
        v2.PB(cur);
    }
    for (int i = 0; i < n / 2; ++i) {
        if (v2.empty()) {
            NO();
        }
        int cur = v2.back();
        v2.pop_back();
        ans[i][n / 2] = cur;
        ans[n - 1 - i][n / 2] = cur;
    }
    for (int i = 0; i < n / 2; ++i) {
        if (v2.empty()) {
            NO();
        }
        int cur = v2.back();
        v2.pop_back();
        ans[n / 2][i] = cur;
        ans[n / 2][n - 1 - i] = cur;
    }
    if (v2.size()) {
        exit(228);
    }
    ans[n / 2][n / 2] = v1[0];
    print();
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n * n; ++i) {
        int a;
        cin >> a;
        v.PB(a);
        cnt[a]++;
    }
    for (int i = 0; i < max_v; ++i) {
        int c = cnt[i];
        while (c >= 4) {
            c -= 4;
            v4.PB(i);
        }
        while (c >= 2) {
            c -= 2;
            v2.PB(i);
        }
        if (c == 1) {
            v1.PB(i);
        }
    }
    if (n % 2 == 0) {
        solvec();
        return 0;
    } else {
        solvenc();
        return 0;
    }

    return 0;
}