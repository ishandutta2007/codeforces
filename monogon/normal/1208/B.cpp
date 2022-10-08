
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2005;
int n;
ll a[N];
map<ll, int> cnt;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // remove [i, j)
    int i = 0, j = 0;
    for(j = n - 1; j >= 0; j--) {
        if(cnt[a[j]]) {
            break;
        }
        cnt[a[j]]++;
    }
    j++;
    int m = j - i;
    while(++i < n) {
        cnt[a[i - 1]]++;
        while(j < n && cnt[a[i - 1]] > 1) {
            cnt[a[j]]--;
            j++;
        }
        if(cnt[a[i - 1]] > 1) break;
        m = min(m, j - i);
    }
    cout << m << endl;
}