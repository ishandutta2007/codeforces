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

int k;
char s[1200000];
vector<int> vv;

int main() {
    scanf("%d ", &k);
    fgets(s, 1200000, stdin);
    int n = strlen(s);
    for (int i = 0; i < n; ++i)
        if (s[i] == '-')
            s[i] = ' ';
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        ++cnt;
        if (s[i] == ' ')
            vv.push_back(cnt), cnt = 0;
        else if (s[i] == '\n') {
            --cnt;
        }
    }
    vv.push_back(cnt);
    int lb = 0;
    int rb = 1e7;
    while (rb - lb > 1) {
        int mid = (lb + rb) >> 1;
        int cc = 1;
        int now = 0;
        for (int i = 0; i < vv.size(); ++i) {
            if (now + vv[i] <= mid)
                now += vv[i];
            else if (vv[i] <= mid)
                ++cc, now = vv[i];
            else {
                cc = k + 1;
                break;
            }
        }
        if (cc <= k)
            rb = mid;
        else
            lb = mid;
    }
    cout << rb << "\n";
    return 0;
}