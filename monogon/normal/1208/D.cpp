
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n;
ll bit[N], s[N];

ll getSum(int k) {
    ll sum = 0;
    while(k >= 1) {
        sum += bit[k];
        k -= k & -k;
    }
    return sum;
}
void add(int k, int x) {
    while(k <= n) {
        bit[k] += x;
        k += k & -k;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for(int i = 1; i <= n; i++) {
        add(i, i);
    }
    for(int i = n; i >= 1; i--) {
        int l = 1, r = n;
        while(l < r) {
            int m = l + (r - l) / 2;
            ll sum = getSum(m - 1);
            if(sum == s[i]) {
                if(getSum(m) - getSum(m - 1) == 0) {
                    l = m + 1;
                }else {
                    l = r = m;
                }
            }else if(sum < s[i]) {
                l = m + 1;
            }else {
                r = m - 1;
            }
        }
        add(l, -l);
        s[i] = l;
    }
    for(int i = 1; i <= n; i++) {
        cout << s[i] << " ";
    }
    cout << endl;
}