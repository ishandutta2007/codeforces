#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define MP make_pair
#define F first
#define S second

const int INF = (int)2e9;

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int hi = INF;
    int lo = -INF;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a;
        int x;
        cin >> x;
        cin >> b;
        if (a == ">") {
            if (b == "Y")
                lo = max(lo, x + 1);
            else
                hi = min(hi, x);
        }
        if (a == ">=") {
            if (b == "Y")
                lo = max(lo, x);
            else
                hi = min(hi, x - 1);
        }
        if (a == "<") {
            if (b == "Y")
                hi = min(hi, x - 1);
            else
                lo = max(lo, x);
        }
        if (a == "<=") {
            if (b == "Y")
                hi = min(hi, x);
            else
                lo = max(lo, x + 1);
        }
    }

    if (lo > hi)
        cout << "Impossible";
    else
        cout << lo;


    return 0;
}