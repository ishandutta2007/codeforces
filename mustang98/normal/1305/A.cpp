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

int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--) {
        vector<int> a, b;
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int c;
            cin >> c;
            a.PB(c);
        }
        for (int i = 0; i < n; ++i) {
            int c;
            cin >> c;
            b.PB(c);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for (int x : a) {
            cout << x << ' ';
        }
        cout << endl;
        for (int x : b) {
            cout << x << ' ';
        }
        cout << endl;
    }

    return 0;
}