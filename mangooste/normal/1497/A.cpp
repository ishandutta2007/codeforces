#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vec<int> a(n);
        vec<int> freq(101);
        for (auto &x : a) {
            cin >> x;
            freq[x]++;
        }
        sort(all(a));
        a.resize(unique(all(a)) - a.begin());
        for (auto x : a)
            cout << x << ' ';
        for (int i = 0; i < 101; i++)
            for (int j = 1; j < freq[i]; j++)
                cout << i << ' ';
        cout << '\n';
    }
}