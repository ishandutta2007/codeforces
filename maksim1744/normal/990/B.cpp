/*
    11.06.2018 17:04:43
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

const bool debug = false;

int main(int argc, char const *argv[])
{
    if (debug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    int test_count = 3;
    if (!debug) {
        test_count = 1;
    }
    for (int test = 0; test < test_count; ++test)
    {
        if (debug) {
            cout << "Case #" << test + 1 << ":\n";
        }
        int n, k;
        cin >> n >> k;
        vector< int > a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector< pi > b;
        for (int i = 0; i < n; ++i)
        {
            if (b.size() == 0 || b[b.size() - 1].first != a[i]) {
                b.push_back(pi(a[i], 1));
            }
            else {
                b[b.size() - 1].second++;
            }
        }
        int cnt = 0;
        for (int i = 1; i < b.size(); i++) {
            if (b[i].first - b[i - 1].first > k) {
                cnt += b[i - 1].second;
            }
        }
        cnt += b[b.size() - 1].second;
        cout << cnt << endl;
    }
    fclose(stdout);
    return 0;
}