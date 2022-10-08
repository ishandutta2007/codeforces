
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int K = 16, N = 5005;
int k, n[K];
ll a[K][N];
ll off[K];
ll sum;
bool dp[1 << K];
int track[1 << K];
map<ll, pair<int, int>> box;

// for each cycle, store a bitmask for the boxes involved
// also store the (i, j) position in the cycle of minimal i.
// for each position, store the index of the cycle it's involved in
vector<int> vmask;
vector<pair<int, int>> vpos;
int cycle[K][N];
int vis[K][N];

int C[N], P[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> k;
    sum = 0;
    for(int i = 0; i < k; i++) {
        cin >> n[i];
        for(int j = 0; j < n[i]; j++) {
            cin >> a[i][j];
            off[i] += a[i][j];
            sum += a[i][j];
            box[a[i][j]] = {i, j};
            cycle[i][j] = -1;
        }
    }
    if(sum % k != 0) {
        cout << "No" << endl;
        return 0;
    }
    sum /= k;
    for(int i = 0; i < k; i++) {
        off[i] = sum - off[i];
    }
    int q = 1;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < n[i]; j++) {
            q++;
            if(vis[i][j]) continue;
            // try to create new cycle
            pair<int, int> pos = {i, j};
            vector<pair<int, int>> vec;
            bool flag = true;
            int msk = 0;
            int l = 0;
            while(true) {
                vec.push_back(pos);
                vis[pos.first][pos.second] = q;
                msk += (1 << pos.first);
                ll val = off[pos.first] + a[pos.first][pos.second];
                if(box.count(val) == 0) {
                    flag = false;
                    break;
                }else {
                    pos = box[val];
                    if((msk >> pos.first) & 1) {
                        if(vis[pos.first][pos.second] != q) flag = false;
                        else {
                            while(vec[l].first != pos.first) {
                                msk -= (1 << vec[l].first);
                                l++;
                            }
                        }
                        break;
                    }
                }
            }
            if(flag) {
                // create the cycle
                vmask.push_back(msk);
                vpos.push_back(*min_element(vec.begin() + l, vec.end()));
                int c = (int) vpos.size() - 1;
                for(auto it = vec.begin() + l; it != vec.end(); it++) {
                    cycle[it->first][it->second] = c;
                }
            }
        }
    }
    int upper = (1 << k);
    dp[0] = true;
    int msb = 0;
    for(int i = 1; i < upper; i++) {
        if(i >= (1 << msb)) msb++;
        int r = msb - 1;
        for(int j = 0; j < n[r]; j++) {
            int c = cycle[r][j];
            if(c >= 0 && (vmask[c] & i) == vmask[c] && dp[i - vmask[c]]) {
                dp[i] = true;
                track[i] = c;
                break;
            }
        }
    }
    if(!dp[upper - 1]) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    int st = upper - 1;
    while(st > 0) {
        int c = track[st];
        // process cycle c
        pair<int, int> pos = vpos[c];
        int i = pos.first, j = pos.second;
        do {
            C[pos.first] = a[pos.first][pos.second];
            ll val = off[pos.first] + C[pos.first];
            P[box[val].first] = pos.first + 1;
            pos = box[val];
        }while(pos.first != i);
        st -= vmask[c];
    }
    for(int i = 0; i < k; i++) {
        cout << C[i] << " " << P[i] << endl;
    }
}