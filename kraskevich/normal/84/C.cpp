#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct mm {
       int x, y, r, n;
};

bool cmp(mm a, mm b) {
     return a.x < b.x;
} 

int sqr(int a) {
    return a * a;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    mm mh[n];
    int mn[n];
    for(int i = 0; i < n; ++i) {
            cin >> mh[i].x >> mh[i].r;
            mh[i].y = 0;
            mh[i].n = i;
            mn[i] = -1;
    }
    int cnt = 0;
    sort(mh, mh + n, cmp);
    int k;
    cin >> k;
    for(int i = 0; i < k; ++i) {
            int x, y;
            cin >> x >> y;
            int l = 0, r = n - 1;
            while(l < r - 1) {
                    int m = (l + r) / 2;
                    if(mh[m].x - mh[m].r < x)
                               l = m + 1;
                    else
                        r = m;
            }
            if(sqr(mh[l].x - x) + sqr(mh[l].y - y) <= sqr(mh[l].r) && mn[mh[l].n] == -1) {
                           ++cnt;
                           mn[mh[l].n] = i;
            }
            --l;
            if(l >= 0)
                 if(sqr(mh[l].x - x) + sqr(mh[l].y - y) <= sqr(mh[l].r) && mn[mh[l].n] == -1) {
                           ++cnt;
                           mn[mh[l].n] = i;
            }
            l += 2;
            if(l < n) if(sqr(mh[l].x - x) + sqr(mh[l].y - y) <= sqr(mh[l].r) && mn[mh[l].n] == -1) {
                           ++cnt;
                           mn[mh[l].n] = i;
            }
    }
    cout << cnt << endl;
    for(int i = 0; i < n; ++i)
            cout << (mn[i] >= 0 ? mn[i] + 1 : -1) << " ";
    cin >> n;
    return 0;
}