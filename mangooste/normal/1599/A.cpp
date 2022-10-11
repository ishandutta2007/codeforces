#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    sort(all(a));

    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 1; i < n; i++)
        cnt += s[i] != s[i - 1];

    int first = n - cnt - 1, second = first;
    array<char, 2> ar{'L', 'R'};
    if (ar[first & 1] != s[0])
        swap(ar[0], ar[1]);

    for (int i = 0; i < n; i++)
        if (i && s[i] == s[i - 1])
            cout << a[--first] << ' ' << ar[first & 1] << '\n';
        else
            cout << a[second++] << ' ' << ar[second & 1 ^ 1] << '\n';
}