#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <queue>
#include <deque>
#include <stack>
using namespace std;

#define ll long long
#define F first
#define S second

struct T {
       int val, nn;
};

bool cmp(T a, T b) {
     return a.val < b.val;
}

int main() {
    vector<pair<int, int> > ans;
    ios_base::sync_with_stdio(0);
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    T a[n], b[m];
    for(int i = 0; i < n; ++i) {
            cin >> a[i].val;
            a[i].nn = i;
    }
    for(int i = 0; i < m; ++i) {
            cin >> b[i].val;
            b[i].nn  = i;
    }
    sort(a, a + n, cmp);
    sort(b, b + m, cmp);
    int l = 0, r = m - 1;
    for(int i = 0; i < n; ++i) {
            r = m - 1;
            int xx = a[i].val - x;
            while(l < r) {
                    int m = (l + r) / 2;
                    if(b[m].val >= xx)
                            r = m;
                    else
                        l = m + 1;
            }
            if(b[r].val < xx)
                        break;
            if(b[r].val > a[i].val + y)
                    continue;
            ans.push_back(make_pair(a[i].nn + 1, b[r].nn + 1));
            l = r + 1;
            r = m - 1;
            if(l > r)
                 break;
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); ++i)
            cout << ans[i].F << " " << ans[i].S << endl;
    cin >> n;
    return 0;
}