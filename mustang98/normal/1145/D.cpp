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

int main()
{
    //freopen("input.txt", "r", stdin);
    vector<int> v;
    int n;
    cin >> n;
    int mn = inf;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        v.PB(a);
        mn = min(mn, a);
    }
    //sort(v.begin(), v.end());
    cout << (2 + (v[2] ^ mn)) << endl;
    return 0;
}