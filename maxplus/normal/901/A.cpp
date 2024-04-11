#include <iostream>

using namespace std;

constexpr int N = 100001;

int n, f, a[N];

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    ++n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        f |= a[i] > 1 && i && a[i - 1] > 1;
    }
    if (!f) {
        return cout << "perfect\n", 0;
    }
    cout << "ambiguous\n";
    for (int tree = 0; tree < 2; ++tree) {
        for (int i = 0, prev = 0; i < n; prev += a[i++]) {
            for (int j = 0, shift = 0; j < a[i]; ++j, shift |= tree && i && a[i - 1] > 1) {
                cout << prev - shift << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}