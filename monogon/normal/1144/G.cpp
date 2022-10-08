
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
#define ll long long
#define VI vector<int>

using namespace std;

// the minimum element must be the first one in the increasing sequence,
// or the last one in the decreasing sequence
// if everything before it doesn't form a decreasing subsequence, it can't be the first in the increasing seq.
// if everything after it doesn't form an increasing subseq, it can't be the last in the decreasing seq.
// if both of the above hold, it is trivial.
// if neither of the above hold, it is contradictory
// if one of the above holds, then we reduce the problem to a new range.

// suppose the minimum starts the increasing seq. Then everything before it is the prefix of the decreasing seq.
// Then we have an upper bound for the values in the new range.

// what do we need? The minimum of any given interval (segment tree)
// To check if the sequence is strictly increasing/decreasing on a given interval
// also use a segment tree for this. At each node store:
// minimum range, maximum range, boolean for increasing, boolean for decreasing

class node {
public:
    int m, M;
    int midx, Midx;
    bool inc, dec;
    node(int val, int idx) {
        m = M = val;
        midx = Midx = idx;
        inc = dec = true;
    }
    node() {
        m = M = midx = Midx = -1;
        inc = dec = true;
    }
    node operator+(const node &n) const {
        if(m == -1) return n;
        if(n.m == -1) return *this;
        node N;
        N.inc = (inc && n.inc && M < n.m);
        N.dec = (dec && n.dec && m > n.M);
        N.m = m;
        N.midx = midx;
        N.M = M;
        N.Midx = Midx;
        if(n.m < m) {
            N.m = n.m;
            N.midx = n.midx;
        }
        if(n.M > M) {
            N.M = n.M;
            N.Midx = n.Midx;
        }
        return N;
    }
};

const int MAX_N = 262144;
int n;
node tree[2 * MAX_N + 5];
int a[MAX_N], ans[MAX_N];

node getSum(int a, int b) {
    a += MAX_N;
    b += MAX_N;
    node sum, rsum;
    while(a <= b) {
        if(a % 2 == 1) sum = sum + tree[a++];
        if(b % 2 == 0) rsum = tree[b--] + rsum;
        a /= 2;
        b /= 2;
    }
    return sum + rsum;
}
void add(int k, int x) {
    k += MAX_N;
    tree[k] = node(x, k - MAX_N);
    for(k /= 2; k >= 1; k /= 2) {
        tree[k] = tree[2 * k] + tree[2 * k + 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin >> n;
    FOR(i, n) {
        cin >> a[i];
        add(i, a[i]);
    }

    fill(ans, ans + n, -1);
    int l = 0;
    int r = n - 1;
    int iupper = MAX_N; // upper bound for increasing sequence
    int dupper = MAX_N; // upper bound for decreasing sequence
    int ilower = -1; // lower bound for increasing sequence
    int dlower = -1; // lower bound for decreasing sequence
    while(l <= r) {
        node n = getSum(l, r);
        int i = n.midx;
        if(getSum(l, i - 1).dec && (i == l || (a[i - 1] > dlower && a[l] < dupper)) && a[i] > ilower && a[i] < iupper) {
            // cout << "DEC " << i << endl;
            for(int j = l; j < i; j++) {
                ans[j] = 1;
            }
            ans[i] = 0;
            ilower = a[i];
            if(i > l) {
                dupper = a[i - 1];
            }
            l = i + 1;
        }else if(getSum(i + 1, r).inc && (i == r || (a[i + 1] > ilower && a[r] < iupper)) && a[i] > dlower && a[i] < dupper) {
            // cout << "INC " << i << endl;
            for(int j = i + 1; j <= r; j++) {
                ans[j] = 0;
            }
            ans[i] = 1;
            dlower = a[i];
            if(i < r) {
                iupper = a[i + 1];
            }
            r = i - 1;
        }else {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}