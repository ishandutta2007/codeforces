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

vector<int> GetDiv(long long n) {
    vector<int> ans;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ans.push_back(i);
            if (n / i != i) {
                ans.push_back(n / i);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    long long n;
    cin >> n;
    vector<int> d = GetDiv(n);
    vector<long long> ans;
    for (ll a : d) {
        ll result = 1LL * (1 + n + 1) * (a + 1) / 2 - n - 1;
        ans.push_back(result);
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for (ll a : ans) {
        cout << a << ' ';
    }

    return 0;
}