/*
    15.03.2019 11:59:07
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef HOMEm
#define TAG_LENGTH 45
#define LR_LEFT left
#define LR_RIGHT right
#define LR_VALUE value
#define LR_SECOND_VALUE mn
#include "C:/C++ libs/print.cpp"
#define showl cout << endl;
#define shows cout << string(5, ' ') + string(TAG_LENGTH, '-') << endl;
#else
#define show(...) 42;
#define showt(...) 42;
#define showl 42;
#define shows 42;
#define print(...) 42;
#define printTree(...) 42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

const long long mxsize = 100000;

int main() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int sm = 0;
    for (int i = 0; i < n; i += 2) {
        sm += (int)a[i] - (int)a[i + 1] - (int)b[i] + (int)b[i + 1];
    }
    if (sm != 0) {
        cout << -1 << '\n';
        return 0;
    }
    for (int i = 0; i < n; i += 2) {
        a[i] = '9' - (a[i] - '0');
        b[i] = '9' - (b[i] - '0');
    }
    show(a, b);
    int ind = 0;
    vector< pair< int, int > > ans;
    long long cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i])
            continue;
        if (a[i] < b[i]) {
            if (ind <= i)
                ind = i + 1;
            while (a[i] != b[i] && a[i + 1] != '0') {
                ++cnt;
                ++a[i];
                --a[i + 1];
                if (ans.size() < mxsize)
                    ans.push_back({i + 1, (i & 1 ? -1 : 1)});
            }
            while (a[i] != b[i]) {
                while (a[ind] == '0')
                    ++ind;
                while (a[i] != b[i] && a[ind] != '0') {
                    cnt += ind - i;
                    ++a[i];
                    --a[ind];
                    if (ans.size() < mxsize)
                        for (int j = ind - 1; j >= i; --j)
                            ans.push_back({j + 1, (j & 1 ? -1 : 1)});
                }
            }
        } else {
            if (ind <= i)
                ind = i + 1;
            while (a[i] != b[i] && a[i + 1] != '9') {
                ++cnt;
                --a[i];
                ++a[i + 1];
                if (ans.size() < mxsize)
                    ans.push_back({i + 1, (i & 1 ? 1 : -1)});
            }
            while (a[i] != b[i]) {
                while (a[ind] == '9')
                    ++ind;
                while (a[i] != b[i] && a[ind] != '9') {
                    cnt += ind - i;
                    --a[i];
                    ++a[ind];
                    if (ans.size() < mxsize)
                        for (int j = ind - 1; j >= i; --j)
                            ans.push_back({j + 1, (j & 1 ? 1 : -1)});
                }
            }
        }
    }
    cout << cnt << '\n';
    for (int i = 0; i < min(cnt, mxsize); ++i) {
        cout << ans[i].first << ' ' << -ans[i].second << '\n';
    }
    return 0;
}