
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 4e5 + 5;
int n;
ll I;
ll a[MAX_N];
// number of distinct values up to, but not including i.
int distinct[MAX_N];

int main() {
    cin >> n >> I;
    I *= 8;
    ll k = I / n;
    ll K = 1;
    for(int i = 0; i < k && K < n; i++) {
        K *= 2;
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    distinct[0] = 0;
    for(int i = 1; i < n; i++) {
        distinct[i] = distinct[i - 1];
        if(a[i] != a[i - 1]) {
            distinct[i]++;
        }
    }
    distinct[n] = distinct[n - 1] + 1;

    int i = 0;
    int j = 0;
    int maxrange = 0;
    while(i < n) {
        maxrange = max(maxrange, j - i);
        if(j == n) {
            i++;
        }else if(distinct[j + 1] - distinct[i] + (distinct[j + 1] == distinct[j] ? 1 : 0) <= K) {
            j++;
        }else {
            i++;
            if(j < i) {
                j++;
            }
        }
    }
    cout << (n - maxrange) << endl;
}