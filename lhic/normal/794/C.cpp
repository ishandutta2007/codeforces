#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>
#include <functional>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

#ifndef LOCAL
#define cerr _cer
struct _cert
{
    template <typename T> _cert& operator << (T) { return *this; }
};
_cert _cer;
#endif

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}
const int MAXN = 410000;

char s[MAXN];
char t[MAXN];
char ans[MAXN];

int main() {
    scanf("%s %s", s, t);
    int n = strlen(s);
    int l2 = n / 2;
    int l1 = n - l2;
    sort(s, s + n);
    sort(t, t + n);
    reverse(t, t + n);
    int n1 = 0;
    int n2 = 0;
    int l = 0;
    int r = n - 1;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            if (n2 != l2 && t[n2] <= s[n1]) {
                ans[r] = s[l1 - 1];
                --l1;
                --r;
            }
            else {
                ans[l] = s[n1];
                ++n1;
                ++l;
            }
        }
        else {
            if (n1 != l1 && s[n1] >= t[n2]) {
                ans[r] = t[l2 - 1];
                --l2;
                --r;
            }
            else {
                ans[l] = t[n2];
                ++n2;
                ++l;
            }
        }
    }
    printf("%s\n", ans);
    return 0;
}