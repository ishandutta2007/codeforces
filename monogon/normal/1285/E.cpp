
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int t, n, m;
ll l[N], r[N];
int off[2 * N], bit[2 * N], numl[2 * N], numr[2 * N];
vector<ll> vx;

int getSum(int k) {
    int s = 0;
    while(k >= 1) {
        s += bit[k];
        k -= k & -k;
    }
    return s;
}
void add(int k, int x) {
    while(k <= m) {
        bit[k] += x;
        k += k & -k;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        vx.clear();
        for(int i = 0; i < n; i++) {
            cin >> l[i] >> r[i];
            vx.push_back(l[i]);
            vx.push_back(r[i]);
        }
        sort(vx.begin(), vx.end());
        vx.erase(unique(vx.begin(), vx.end()), vx.end());
        m = vx.size();
        fill(off, off + m + 1, 0);
        fill(numl, numl + m + 1, 0);
        fill(numr, numr + m + 1, 0);
        for(int i = 0; i < n; i++) {
            l[i] = lower_bound(vx.begin(), vx.end(), l[i]) - vx.begin();
            r[i] = lower_bound(vx.begin(), vx.end(), r[i]) - vx.begin();
            off[l[i] + 1]++;
            off[r[i] + 1]--;
            numl[l[i]]++;
            numr[r[i]]++;
        }
        fill(bit, bit + m + 1, 0);
        int cnt = 0;
        for(int i = 1; i <= m; i++) {
            off[i] += off[i - 1];
            if(off[i] == 1) {
                add(i, 1);
            }else if(off[i] == 0) cnt++;
        }
        int M = -500;
        for(int i = 0; i < n; i++) {
            int o = getSum(r[i]) - getSum(l[i]);
            if(l[i] == r[i]) {
                if(numl[l[i]] == 1 && numr[r[i]] == 1 && off[l[i] + 1] == 0) o = -1;
                else o = 0;
            }else if(l[i] + 1 == r[i] && off[l[i] + 1] == 1) {
                o = -1;
                if(numr[l[i]] > 0) o++;
                if(numl[r[i]] > 0) o++;
            }else {
                if(numr[l[i]] == 0 && off[l[i] + 1] == 1) o--;
                if(numl[r[i]] == 0 && off[r[i]] == 1) o--;
            }
            M = max(M, o);
        }
        cout << cnt + M << endl;
    }
}