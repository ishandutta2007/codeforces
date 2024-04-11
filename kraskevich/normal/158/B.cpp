#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt[4], a;
    for(int i = 0; i < 4; ++i)
            cnt[i] = 0;
    for(int i = 0; i < n; ++i) {
            cin >> a;
            cnt[--a]++;
    }
    int res = 0, left = 0;
    res += cnt[3];
    res += cnt[1] / 2;
    if(cnt[1] % 2 == 1) {
              res++;
              left = 2;
    }
    res += cnt[2];
    left += cnt[2];
    if(left < cnt[0]) {
            cnt[0] -= left;
            res += cnt[0] / 4 + (cnt[0] % 4 ? 1 : 0);
    }
    cout << res;
    cin >> n;
    return 0;
}