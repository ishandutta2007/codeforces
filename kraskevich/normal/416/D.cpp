#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long LL;
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

    int n;
    cin >> n;
    vector<LL> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int res = 0;
    int i = 0;
    while (i < n) {
        res++;
        vector<LL> p;
        LL start = i;
        while (i < n && p.size() < 2) {
            if (a[i] > 0)
                p.push_back(i);
            i++;
        }
        if (p.size() < 2)
            break;
        LL p1 = p[0];
        LL p2 = p[1];
        LL v1 = a[p1];
        LL v2 = a[p2];
        if ((v2 - v1) % (p2 - p1)) {
            i = p2;
            continue;
        }
        LL delta = (v2 - v1) / (p2 - p1);
        LL startVal = v2 - (p2 - start) * delta;
        if (startVal <= 0) {
            i = p2;
            continue;
        }
        long long want = v2;
        while (i < n) {
            want += delta;
            if (want <= 0)
                break;
            if (a[i] > 0 && a[i] != want)
                break;
            i++;
        }
    }

    cout << res;

    return 0;
}