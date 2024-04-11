#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e6 + 5;
long long a[N];
long long b[N];
long long sum1[N];
long long sum2[N];
int n;
pair < int, pair < int, int > > t[N];

mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count());

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    sum1[0] = 0; sum2[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum1[i] = sum1[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        sum2[i] = sum2[i - 1] + b[i];
    }
    if (sum2[n] == sum1[n]) {
        cout << n << '\n';
        for (int i = 1; i <= n; i++) {
            cout << i << " ";
        }
        cout << '\n' << n << '\n';
        for (int i = 1; i <= n; i++) {
            cout << i << " ";
        }
        return 0;
    }
    bool mark = false;
    if (sum1[n] > sum2[n]) {
        mark = true;
        for (int i = 1; i <= n; i++) {
            swap(sum1[i], sum2[i]);
        }
    }
    int ptr = n - 1;
    for (int i = n; i >= 1; i--) {
        while (sum1[i] < sum2[ptr]) {
            ptr--;
        }
        if (sum1[i] == sum2[ptr]) {
            if (!mark) {
                cout << i << '\n';
                for (int j = 1; j <= i; j++) {
                    cout << j << " ";
                }
                cout << '\n' << ptr << '\n';
                for (int j = 1; j <= ptr; j++) {
                    cout << j << " ";
                }
                return 0;
            }
            else {
                cout << ptr  << '\n';
                for (int j = 1; j <= ptr; j++) {
                    cout << j << " ";
                }
                cout << '\n' << i << '\n';
                for (int j = 1; j <= i; j++) {
                    cout << j << " ";
                }
                return 0;
            }
        }
        t[i].first = sum1[i] - sum2[ptr];
        t[i].second.first = i;
        t[i].second.second = ptr;
    }
    sort(t + 1, t + n + 1);
    for (int i = 1; i <= n; i++) {
        if (i > 1) {
            if (t[i].first == t[i - 1].first) {
                if (!mark) {
                    int x = t[i].second.first;
                    int y = t[i - 1].second.first;
                    if (x > y) swap(x, y);
                    cout << y - x  << '\n';
                    for (int j = x + 1; j <= y; j++) {
                        cout << j << " ";
                    }
                    cout << '\n';
                    x = t[i].second.second;
                    y = t[i - 1].second.second;
                    if (x > y) swap(x, y);
                    cout << y - x << '\n';
                    for (int j = x + 1; j <= y; j++) {
                        cout << j << " ";
                    }
                    return 0;
                }
                else {
                    int x = t[i].second.second;
                    int y = t[i - 1].second.second;
                    if (x > y) swap(x, y);
                    cout << y - x  << '\n';
                    for (int j = x + 1; j <= y; j++) {
                        cout << j << " ";
                    }
                    cout << '\n';
                    x = t[i].second.first;
                    y = t[i - 1].second.first;
                    if (x > y) swap(x, y);
                    cout << y - x << '\n';
                    for (int j = x + 1; j <= y; j++) {
                        cout << j << " ";
                    }
                    return 0;
                }
            }
        }
    }
}