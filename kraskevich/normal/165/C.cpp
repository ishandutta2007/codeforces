#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

#define pb push_back
#define F first
#define S second
typedef long long ll;
int n;
int sum[1000 * 1000];

int low(int k, int pos) {
    int l = pos, r = n - 1;
    while(l < r - 1) {
            int m = (l + r) / 2;
            if(sum[m] - (pos ? sum[pos - 1] : 0) < k)
                      l = m;
            else
                r = m;
    }
    if(sum[l] - (pos ? sum[pos - 1] : 0) >= k)
              r = l;
    return r;
}

int high(int k, int pos) {
    int l = pos, r = n - 1;
    while(l < r - 1) {
            int m = (l + r) / 2;
            if(sum[m] - (pos ? sum[pos - 1] : 0) <= k)
                      l = m;
            else
                r = m;
    }
    if(sum[r] - (pos ? sum[pos - 1] : 0) == k)
              l = r;
    return l;
}

int main() {
    ios_base::sync_with_stdio(0);
    int k;
    cin >> k;
    string s;
    cin >> s;
    if(k == 0) {
         ll res = 0, cur = 0;
         for(int i = 0; i < s.length(); ++i) {
                 if(s[i] == '0')
                         ++cur;
                 else {
                      res += cur * (cur + 1) / 2;
                      cur = 0;
                 }
         }
         res += cur * (cur + 1) / 2;
         cout << res;
         cin >> n;
         return 0;
    }
    n = s.length();
    for(int i = 0; i < n; ++i) {
            sum[i] = (s[i] == '1' ? 1 : 0);
            if(i)
                 sum[i] += sum[i - 1];
    }
    ll res  = 0;
    for(int i = 0; i < n; ++i) {
            if(sum[n - 1] - (i ? sum[i - 1] : 0) < k)
                     break;
            int l = low(k, i), r = high(k, i);
            res = (ll)res + max((ll)0, ll(r) - l + 1);
    }
    cout << res;
    cin >> n;
    return 0;
}