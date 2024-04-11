#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
#define MP make_pair
#define F first
#define S second


int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int l = k - 1;
    int r = n - k;
    k--;
    if (l <= r) {
        for (int i = 0; i < k; i++)
            cout << "LEFT\n";
        for (int i = 0; i < n - 1; i++)
            cout << "PRINT " << s[i] << "\n" << "RIGHT\n";
        cout << "PRINT " << s[n - 1] << "\n";
    } else {
        for (int i = 0; i < n - k - 1; i++)
            cout << "RIGHT\n";
        for (int i = 0; i < n - 1; i++)
            cout << "PRINT " << s[n - i - 1] << "\n" << "LEFT\n";
        cout << "PRINT " << s[0] << "\n";
    }
    return 0;
}