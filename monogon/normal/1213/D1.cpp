
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n, k;
int a[N];
int len[N];
multiset<int> ms;
int cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int d = 1;
    for(int i = 0; i < n; i++) {
        while((a[i] >> d) != 0) {
            d++;
        }
        len[i] = d;
    }
    int minops = INT_MAX;
    for(int d = 0; d < 20; d++) {
        ms.clear();
        for(int i = 0; i < n; i++) {
            if(len[i] <= d) continue;
            int num = a[i] >> (len[i] - d - 1);
            int c = ms.count(num);
            if(c == 0) {
                cnt[num] = 0;
            }
            cnt[num] += len[i] - d - 1;
            ms.insert(num);
            if(c + 1 == k) {
                minops = min(minops, cnt[num]);
            }
        }
    }
    cout << minops << endl;
}