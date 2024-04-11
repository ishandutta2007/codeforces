
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// find longest substring with two pointers
// i <= j.
// increment i if bad bracket sequence and decrement count if open paren
// increment j otherwise and increment/decrement count.
// if count = 0, it's a valid sequence.
// [i, j)

// find [i, j] so that f(i) = f(j) and f(x) >= f(i) on the interval

const int N = 1e6 + 5;
string s;
int n;
vector<pair<int, int>> v;
int bit[N];

int getSum(int k) {
    int s = 0;
    while(k >= 1) {
        s += bit[k];
        k -= k & -k;
    }
    return s;
}
void add(int k, int x) {
    while(k <= n + 5) {
        bit[k] += x;
        k += k & -k;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n = s.length();
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        v.emplace_back(cnt, i + 1);
        cnt += (s[i] == '(' ? 1 : -1);
    }
    v.emplace_back(cnt, n + 1);
    sort(v.begin(), v.end());
    int best = 0, times = 1;
    int lastcnt = -n - 1;
    int firsti = 0;
    for(int i = 0; i < v.size(); i++) {
        int cnt, j;
        tie(cnt, j) = v[i];
        if(cnt > lastcnt) {
            lastcnt = cnt;
            while(firsti < i) {
                add(v[firsti].second, 1);
                firsti++;
            }
        }
        while(getSum(v[firsti].second) != getSum(j)) {
            add(v[firsti].second, 1);
            firsti++;
        }
        int len = j - v[firsti].second;
        if(len > best) {
            best = len;
            times = 1;
        }else if(len == best && len > 0) times++;
    }
    cout << best << " " << times << endl;
}