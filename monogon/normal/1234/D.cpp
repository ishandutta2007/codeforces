
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int n, q, type, l, r, pos;
char c;
string s;
int bit[26][N];

int getSum(int c, int k) {
    int s = 0;
    while(k >= 1) {
        s += bit[c][k];
        k -= k & -k;
    }
    return s;
}
void add(int c, int k, int x) {
    while(k <= n) {
        bit[c][k] += x;
        k += k & -k;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n = s.length();
    cin >> q;
    for(int i = 0; i < n; i++) {
        add(s[i] - 'a', i + 1, 1);
    }
    while(q--) {
        cin >> type;
        if(type == 1) {
            cin >> pos >> c;
            add(s[pos - 1] - 'a', pos, -1);
            s[pos - 1] = c;
            add(c - 'a', pos, 1);
        }else {
            cin >> l >> r;
            int sum = 0;
            for(int i = 0; i < 26; i++) {
                if(getSum(i, r) - getSum(i, l - 1) > 0) {
                    sum++;
                }
            }
            cout << sum << endl;
        }
    }
}