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

set<int> s;
int m[200];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        m[i] = a;
        s.insert(a);
    }
    if (s.size() < k) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    for (int i = 0; i < k; ++i) {
        int v = *s.begin();
        s.erase(s.begin());
        for (int j = 0; j < n; ++j) {
            if (m[j] == v) {
                cout << j + 1 << ' ';
                break;
            }
        }
    }

    return 0;
}