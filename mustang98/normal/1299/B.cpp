#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

pair<int, int> p[max_n];
int n;

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].F >> p[i].S;
    }
    if (n % 2 == 1) {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        int a = i;
        int b = (i + n / 2) % n;
        int a1 = (a + 1) % n;
        int b1 = (b + 1) % n;
        pair<int, int> v1 = {p[a1].F - p[a].F, p[a1].S - p[a].S};
        pair<int, int> v2 = {p[b1].F - p[b].F, p[b1].S - p[b].S};
        v2.F *= -1;
        v2.S *= -1;
        if (v1 != v2) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}