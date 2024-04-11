
#include <bits/stdc++.h>

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORK(i, k, n) for(int i = k; i < n; i++)
#define FORr(i, n) for(int i = n - 1; i >= 0; i--)
#define FORKr(i, k, n) for(int i = n - 1; i >= k; i--)
#define PRINT(a, b) copy((a), (b), ostream_iterator<int>(cout, " "))
#define all(a) a.begin(), a.end()
#define in(a, b) ((b).find(a) != (b).end())
#define sz(a) ((int) (a).size())
#define Mp make_pair
#define PII pair<int, int>
#define LL long long
#define VI vector<int>

using namespace std;

// we need to find pref and suf
// pref is maximum prefix of values that form a sorted array
// suf is max. suffix ...
// for this, we need first occurences and last occurences.

const int MAX_N = 1e6 + 5;

int n, x;
int a[MAX_N], frs[MAX_N], lst[MAX_N], prefmax[MAX_N];

int main() {
    std::ios_base::sync_with_stdio(false);
    cin >> n >> x;
    fill(frs, frs + x + 1, n + 1);
    fill(lst, lst + x + 1, 0);
    prefmax[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        prefmax[i] = max(prefmax[i - 1], a[i]);
        if(frs[a[i]] == n + 1) {
            frs[a[i]] = i;
        }
        lst[a[i]] = i;
    }
    int pref = 1;
    int l = lst[1];
    for(int i = 1; i < x; i++) {
        if(frs[i + 1] > l) {
            pref++;
            if(lst[i + 1] != 0) {
                l = lst[i + 1];
            }
        }else break;
    }
    int suf = x;
    int f = frs[x];
    for(int i = x; i > 1; i--) {
        if(lst[i - 1] < f) {
            suf--;
            if(frs[i - 1] != n + 1) {
                f = frs[i - 1];
            }
        }else break;
    }

    // for(int i = 1; i <= x; i++) {
    //     cout << i << ": FIRST: " << frs[i] << " LAST: " << lst[i] << endl;
    // }

    // cout << "PREF: " << pref << " SUF: " << suf << endl;
    long long sum = 0;
    // include [1, ..., p] U [s, ..., x]
    // i.e. [p + 1, s - 1] is deleted
    l = 0;
    for(int p = 0; p <= pref; p++) {
        if(lst[p] != 0) l = lst[p];
        int s = max(prefmax[l] + 1, max(suf, p + 2));
        sum += x - s + 2;
        // cout << "PAIR: " << (p + 1) << " " << (s - 1) << endl;
    }
    cout << sum << endl;
}