#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 101, inf = 1000111222;

string s;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    vector<int> v, v1;
    cin >> n;
    for (int i = 0; i < n / 2; ++i) {
        int a;
        cin >> a;
        v.PB(a);
    }
    sort(v.begin(), v.end());
    v1 = v;
    int ans1 = 0;
    for (int i = n; i > 0; i -= 2) {
        ans1 += abs(v.back() - i);
        v.pop_back();
    }

    int ans2 = 0;
    for (int i = n - 1; i > 0; i -= 2) {
        ans2 += abs(v1.back() - i);
        v1.pop_back();
    }
    cout << min(ans1, ans2) << endl;

    return 0;
}