
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int M = 1e5 + 5;
int t, m;
ll n, a[M];
int cnt[60];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        ll sum = 0;
        fill(cnt, cnt + 60, 0);
        for(int i = 0; i < m; i++) {
            cin >> a[i];
            sum += a[i];
            cnt[(int) round(log2(a[i]))]++;
        }
        if(n > sum) {
            cout << -1 << endl;
            continue;
        }
        sum = 0;
        int ops = 0;
        for(int i = 0; i < 60; i++) {
            ll k = (1LL << i);
            sum += cnt[i] * k;
            if(n & k) {
                if(sum < k) {
                    int j = i + 1;
                    while(cnt[j] == 0) j++;
                    ops += j - i;
                    cnt[j--]--;
                    while(j >= i) cnt[j--]++;
                }else {
                    sum -= k;
                }
            }
        }
        cout << ops << endl;
    }
}